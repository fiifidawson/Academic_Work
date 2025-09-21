# Override system SQLite before any other imports
__import__('pysqlite3')
import sys
sys.modules['sqlite3'] = sys.modules.pop('pysqlite3')

import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import zipfile
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, TensorDataset
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer
from sklearn.metrics import accuracy_score
from io import BytesIO


def main():
    # State management
    if 'model' not in st.session_state:
        st.session_state.update({
            'model': None,
            'history': {'train_loss': [], 'val_loss': [], 'train_acc': [], 'val_acc': []},
            'scaler': None,
            'label_encoder': None,
            'training_plot': None,
            'features': None,
            'processed_df': None,
            'target_col': None
        })

    # Title
    st.title("🧠 NeuroClassify - Intelligent Classification")

    # File upload section
    st.header("1. Upload Dataset")
    uploaded_file = st.file_uploader("Drag CSV here", type=["csv"], key="nn_upload")

    if uploaded_file is not None:
        try:
            df = pd.read_csv(uploaded_file)
            
            st.subheader("Column Selection")
            with st.expander("Manage Columns"):
                cols_to_drop = st.multiselect(
                    "Select columns to remove",
                    options=df.columns,
                    help="Remove irrelevant columns before analysis"
                )
                
                processed_df = df.drop(columns=cols_to_drop)
                
                if processed_df.empty:
                    st.error("Error: All columns have been removed. Please keep at least one column.")
                    st.stop()
                    
                st.success(f"Retained columns: {', '.join(processed_df.columns)}")
                st.session_state.processed_df = processed_df

            st.subheader("Data Preview")
            with st.expander("View Dataset Structure"):
                st.write(f"Original columns: {len(df.columns)} | Remaining columns: {len(processed_df.columns)}")
                st.dataframe(processed_df.head(10), use_container_width=True)
                st.write(f"Shape: {processed_df.shape}")

            st.header("2. Set Target Variable")
            user_target = st.text_input("Target Column Name", key="target_input")
            
            if user_target:
                target_col = next((col for col in processed_df.columns 
                                if col.lower() == user_target.strip().lower()), None)
                
                if not target_col:
                    st.error(f"Column '{user_target}' not found in dataset!")
                    st.stop()
                
                st.session_state.target_col = target_col

            if st.session_state.target_col and (st.session_state.target_col in processed_df.columns):
                X = processed_df.drop(columns=[st.session_state.target_col])
                y = processed_df[st.session_state.target_col]

                le = LabelEncoder()
                y_encoded = le.fit_transform(y)
                num_classes = len(le.classes_)
                st.session_state.label_encoder = le

                numeric_cols = X.select_dtypes(include=np.number).columns.tolist()
                selected_features = st.multiselect(
                    "Select Features for Classification",
                    numeric_cols,
                    default=numeric_cols,
                    key="feature_select"
                )
                st.session_state.features = selected_features

                if X[selected_features].isnull().sum().sum() > 0:
                    st.warning("Missing Values Detected!")
                    na_strategy = st.radio(
                        "Handling Strategy:",
                        ["Remove Incomplete Records", "Impute with Mean"],
                        key="na_handle"
                    )
                    
                    if na_strategy == "Remove Incomplete Records":
                        X = X.dropna(subset=selected_features)
                        y_encoded = y_encoded[X.index]
                    else:
                        imputer = SimpleImputer(strategy='mean')
                        X[selected_features] = imputer.fit_transform(X[selected_features])

                scaler = StandardScaler()
                X_scaled = scaler.fit_transform(X[selected_features])
                st.session_state.scaler = scaler

                X_tensor = torch.FloatTensor(X_scaled)
                y_tensor = torch.LongTensor(y_encoded)

                st.header("3. Model Configuration")
                col1, col2 = st.columns(2)
                with col1:
                    test_size = st.slider("Validation Set Size (%)", 10, 40, 20) / 100
                    epochs = st.slider("Number of Epochs", 10, 200, 50)
                with col2:
                    batch_size = st.slider("Batch Size", 16, 256, 32)
                    learning_rate = st.slider("Learning Rate", 0.0001, 0.1, 0.001, format="%.4f")

                X_train, X_val, y_train, y_val = train_test_split(
                    X_tensor, y_tensor, test_size=test_size, random_state=42
                )

                train_dataset = TensorDataset(X_train, y_train)
                val_dataset = TensorDataset(X_val, y_val)
                train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
                val_loader = DataLoader(val_dataset, batch_size=batch_size)

                st.subheader("Network Architecture")
                col1, col2 = st.columns(2)
                with col1:
                    hidden_layers = st.selectbox("Number of Hidden Layers", [1, 2, 3])
                    optimizer_name = st.selectbox("Optimizer", ["Adam", "SGD"])
                with col2:
                    units = st.slider("Units per Hidden Layer", 16, 256, 64)
                    activation = st.selectbox("Activation Function", ["ReLU", "Sigmoid"])

                class NeuralNet(nn.Module):
                    def __init__(self):
                        super(NeuralNet, self).__init__()
                        self.layers = nn.ModuleList()
                        self.layers.append(nn.Linear(len(selected_features), units))
                        self.layers.append(nn.ReLU() if activation == "ReLU" else nn.Sigmoid())
                        
                        for _ in range(hidden_layers-1):
                            self.layers.append(nn.Linear(units, units))
                            self.layers.append(nn.ReLU() if activation == "ReLU" else nn.Sigmoid())
                        
                        self.output = nn.Linear(units, num_classes)
                    
                    def forward(self, x):
                        for layer in self.layers:
                            x = layer(x)
                        return self.output(x)

                model = NeuralNet()
                criterion = nn.CrossEntropyLoss()
                
                if optimizer_name == "Adam":
                    optimizer = optim.Adam(model.parameters(), lr=learning_rate)
                else:
                    optimizer = optim.SGD(model.parameters(), lr=learning_rate)

                st.header("4. Model Training")
                if st.button("Start Training"):
                    progress_bar = st.progress(0)
                    status_text = st.empty()
                    chart_placeholder = st.empty()
                    
                    st.session_state.history = {'train_loss': [], 'val_loss': [], 'train_acc': [], 'val_acc': []}
                    
                    for epoch in range(epochs):
                        model.train()
                        train_loss = 0.0
                        correct = 0
                        total = 0
                        
                        for inputs, labels in train_loader:
                            optimizer.zero_grad()
                            outputs = model(inputs)
                            loss = criterion(outputs, labels)
                            loss.backward()
                            optimizer.step()
                            
                            train_loss += loss.item()
                            _, predicted = torch.max(outputs.data, 1)
                            total += labels.size(0)
                            correct += (predicted == labels).sum().item()
                        
                        model.eval()
                        val_loss = 0.0
                        val_correct = 0
                        val_total = 0
                        
                        with torch.no_grad():
                            for inputs, labels in val_loader:
                                outputs = model(inputs)
                                loss = criterion(outputs, labels)
                                
                                val_loss += loss.item()
                                _, predicted = torch.max(outputs.data, 1)
                                val_total += labels.size(0)
                                val_correct += (predicted == labels).sum().item()
                        
                        train_acc = correct / total
                        val_acc = val_correct / val_total
                        
                        st.session_state.history['train_loss'].append(train_loss/len(train_loader))
                        st.session_state.history['val_loss'].append(val_loss/len(val_loader))
                        st.session_state.history['train_acc'].append(train_acc)
                        st.session_state.history['val_acc'].append(val_acc)
                        
                        progress = (epoch + 1) / epochs
                        progress_bar.progress(progress)
                        
                        status_text.markdown(f"""
                        **Epoch {epoch+1}/{epochs}**  
                        Training Loss: {train_loss/len(train_loader):.4f} | Validation Loss: {val_loss/len(val_loader):.4f}  
                        Training Accuracy: {train_acc:.2%} | Validation Accuracy: {val_acc:.2%}
                        """)
                        
                        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 5))
                        
                        ax1.plot(st.session_state.history['train_loss'], label='Training Loss')
                        ax1.plot(st.session_state.history['val_loss'], label='Validation Loss')
                        ax1.set_title('Loss Evolution')
                        ax1.set_xlabel('Epoch')
                        ax1.legend()
                        
                        ax2.plot(st.session_state.history['train_acc'], label='Training Accuracy')
                        ax2.plot(st.session_state.history['val_acc'], label='Validation Accuracy')
                        ax2.set_title('Accuracy Evolution')
                        ax2.set_xlabel('Epoch')
                        ax2.legend()
                        
                        chart_placeholder.pyplot(fig)
                        plt.close(fig)
                    
                    st.session_state.model = model
                    img_buffer = BytesIO()
                    fig.savefig(img_buffer, format='png', bbox_inches='tight')
                    st.session_state.training_plot = img_buffer.getvalue()
                    st.success("Training Complete!")

                if st.session_state.model:
                    st.header("Training Performance")
                    col1, col2 = st.columns(2)
                    col1.metric("Final Training Accuracy", 
                                f"{st.session_state.history['train_acc'][-1]:.2%}")
                    col2.metric("Final Validation Accuracy", 
                                f"{st.session_state.history['val_acc'][-1]:.2%}")

                    st.header("5. Make Predictions")
                    prediction_option = st.radio("Prediction Input Method:",
                                                ["Upload Test File", "Manual Input"],
                                                horizontal=True)
                    
                    if prediction_option == "Upload Test File":
                        test_file = st.file_uploader("Upload Test CSV", type=["csv"])
                        if test_file:
                            try:
                                test_df = pd.read_csv(test_file)
                                
                                if set(st.session_state.features).issubset(test_df.columns):
                                    X_test = st.session_state.scaler.transform(test_df[st.session_state.features])
                                    X_test_tensor = torch.FloatTensor(X_test)
                                    
                                    st.session_state.model.eval()
                                    with torch.no_grad():
                                        outputs = st.session_state.model(X_test_tensor)
                                        _, preds = torch.max(outputs, 1)
                                    
                                    test_df['Prediction'] = st.session_state.label_encoder.inverse_transform(preds.numpy())
                                    
                                    if st.session_state.target_col in test_df.columns:
                                        y_true = st.session_state.label_encoder.transform(test_df[st.session_state.target_col])
                                        accuracy = accuracy_score(y_true, preds.numpy())
                                        st.metric("Test Accuracy", f"{accuracy:.2%}")

                                    st.dataframe(test_df, height=400)
                                else:
                                    st.error("Test file missing required features!")
                            except Exception as e:
                                st.error(f"Error processing test file: {str(e)}")
                    
                    else:
                        with st.form("manual_prediction"):
                            cols = st.columns(len(st.session_state.features))
                            input_data = []
                            for i, col in enumerate(cols):
                                input_data.append(col.number_input(st.session_state.features[i]))
                            
                            if st.form_submit_button("Predict"):
                                try:
                                    X_new = np.array(input_data).reshape(1, -1)
                                    X_new_scaled = st.session_state.scaler.transform(X_new)
                                    X_new_tensor = torch.FloatTensor(X_new_scaled)
                                    
                                    st.session_state.model.eval()
                                    with torch.no_grad():
                                        output = st.session_state.model(X_new_tensor)
                                        _, pred = torch.max(output, 1)
                                    
                                    predicted_class = st.session_state.label_encoder.inverse_transform(pred.numpy())
                                    st.success(f"**Prediction Result**: {predicted_class[0]}")
                                except Exception as e:
                                    st.error(f"Prediction failed: {str(e)}")

                    st.header("6. Export Results")
                    if st.button("Download Full Package"):
                        try:
                            zip_buffer = BytesIO()
                            with zipfile.ZipFile(zip_buffer, 'w', zipfile.ZIP_DEFLATED) as zip_file:
                                model_path = "data/neural/trained_model.pth"
                                torch.save(st.session_state.model.state_dict(), model_path)
                                zip_file.write(model_path)
                                
                                history_df = pd.DataFrame(st.session_state.history)
                                zip_file.writestr("training_history.csv", history_df.to_csv(index=False))
                                
                                if st.session_state.training_plot:
                                    zip_file.writestr("training_plot.png", st.session_state.training_plot)
                                
                                np.save("data/neural/label_encoder.npy", st.session_state.label_encoder.classes_)
                                zip_file.write("data/neural/label_encoder.npy")
                                
                                scaler_params = {
                                    'mean': st.session_state.scaler.mean_,
                                    'scale': st.session_state.scaler.scale_
                                }
                                np.savez("data/neural/scaler.npz", **scaler_params)
                                zip_file.write("data/neural/scaler.npz")

                            st.download_button(
                                label="⬇ Download ZIP Archive",
                                data=zip_buffer.getvalue(),
                                file_name="model_package.zip",
                                mime="application/zip"
                            )
                        
                        except Exception as e:
                            st.error(f"Export failed: {str(e)}")

        except UnicodeDecodeError:
            st.error("""
            ❗ Failed to read file. Try different encoding:
            1. Latin-1 (European characters)
            2. cp1252 (Windows Western European)
            3. iso-8859-1 (ISO Western European)
            """)
            st.stop()

    else:
        st.info("Please upload a dataset to begin classification")

    st.markdown("---")
    st.caption("© 2025 AI Suite - Neural Classification Module v1.1")