import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import joblib
import io
import zipfile
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, r2_score


def main():    
    # State management
    if 'model' not in st.session_state:
        st.session_state.model = None
    if 'dataset' not in st.session_state:
        st.session_state.dataset = None

    # Title
    st.title("📈 Regression Model Predictor")

    # File upload section
    st.header("1. Upload Your Data")
    uploaded_file = st.file_uploader("Drag CSV here", type=["csv"], key="file_upload")

    if uploaded_file is not None:
        try:
            df = pd.read_csv(uploaded_file)
            st.session_state.dataset = df
            
            # Dataset preview
            st.subheader(" Data Preview")
            with st.expander("View First 10 Rows"):
                st.dataframe(df.head(10), use_container_width=True)

            # Target specification
            st.header("2. Set Target Variable")
            user_target = st.text_input("Target Column Name", key="target_input")
            
            # Case-insensitive column matching
            target_col = next((col for col in df.columns 
                            if col.lower() == user_target.strip().lower()), None) if user_target else None

            if user_target:
                if not target_col:
                    st.error(f"Column '{user_target}' not found in dataset!")
                    st.stop()
                st.success(f"Identified target column: {target_col}")

                # Validate target data type
                if not pd.api.types.is_numeric_dtype(df[target_col]):
                    st.error(f"""
                    ❗ Invalid target column type! 
                    Regression requires numeric targets. 
                    Column '{target_col}' contains {df[target_col].dtype} data.
                    
                    Please select a column with:
                    - Numerical values
                    - No text/categorical data
                    """)
                    st.stop()

            if target_col and (target_col in df.columns):
                # Preprocessing
                st.header("3. Data Preparation")
                features = df.columns.drop(target_col)
                selected_feature = st.selectbox("Select Primary Predictor", features, key="feature_select")

                # Missing values handling
                if df[[target_col, selected_feature]].isnull().sum().sum() > 0:
                    st.warning("Missing Data Detected!")
                    na_option = st.radio("Handling Strategy:",
                                    ["Remove Incomplete Records", "Impute with Average"],
                                    key="na_handle")
                    
                    if na_option == "Remove Incomplete Records":
                        df = df.dropna(subset=[target_col, selected_feature])
                    else:
                        df[selected_feature].fillna(df[selected_feature].mean(), inplace=True)
                        df[target_col].fillna(df[target_col].mean(), inplace=True)

                # Validate remaining data
                if df.empty:
                    st.error("No data remaining after preprocessing! Adjust your cleaning strategy.")
                    st.stop()

                # Model training
                X = df[[selected_feature]].values
                y = df[target_col].values

                st.header("4. Model Configuration")
                test_size = st.slider("Validation Set Size (%)", 10, 40, 20, key="test_size") / 100
                
                try:
                    X_train, X_test, y_train, y_test = train_test_split(
                        X, y, test_size=test_size, random_state=42
                    )
                except ValueError as e:
                    st.error(f"""
                    ❗ Data splitting failed: {str(e)}
                    
                    Possible causes:
                    1. Not enough samples after preprocessing
                    2. Invalid test size ratio
                    3. Missing values in unexpected locations
                    """)
                    st.stop()

                model = LinearRegression()
                
                try:
                    model.fit(X_train, y_train)
                except Exception as e:
                    st.error(f"""
                    ❗ Model training failed: {str(e)}
                    
                    Common solutions:
                    1. Check for NaN/infinite values
                    2. Verify feature/target data types
                    3. Ensure sufficient data quantity
                    """)
                    st.stop()
                    
                st.session_state.model = model

                # Evaluation
                y_pred = model.predict(X_test)
                mae = mean_absolute_error(y_test, y_pred)
                r2 = r2_score(y_test, y_pred)

                # Results display
                st.header("Performance Analysis")
                col1, col2 = st.columns(2)
                col1.metric("Average Prediction Error", f"{mae:.2f}")
                col2.metric("Model Accuracy (R²)", f"{r2:.2f}")

                # Visualization
                st.subheader("Visualization")
                fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))
                
                # Regression plot
                sns.regplot(x=X_test.flatten(), y=y_test, ax=ax1, line_kws={'color': 'orange'})
                ax1.set_title(f"Regression Line: {selected_feature} vs {target_col}", pad=20)
                ax1.set_xlabel(selected_feature, labelpad=15)
                ax1.set_ylabel(target_col, labelpad=15)

                # Prediction accuracy
                sns.scatterplot(x=y_test, y=y_pred, ax=ax2)
                ax2.plot([y.min(), y.max()], [y.min(), y.max()], '--', color='green')
                ax2.set_title("Prediction Accuracy Check", pad=20)
                ax2.set_xlabel("Actual Values", labelpad=15)
                ax2.set_ylabel("Predicted Values", labelpad=15)

                st.pyplot(fig)

                # Custom prediction
                st.header("5. Instant Valuation")
                st.info("This feature works best for evaluating data involving prices.")
                with st.form("prediction_form"):
                    custom_input = st.number_input(f"Enter {selected_feature}", 
                                                min_value=float(df[selected_feature].min()),
                                                max_value=float(df[selected_feature].max()))
                    
                    if st.form_submit_button("Estimate Value"):
                        try:
                            prediction = model.predict([[custom_input]])
                            st.success(f"Estimated {target_col}: ${prediction[0]:,.2f}")
                        except Exception as e:
                            st.error(f"Prediction failed: {str(e)}")

                # Download section
                st.header("6. Export Results")
                if st.button(" Download Full Report"):
                    try:
                        zip_buffer = io.BytesIO()
                        with zipfile.ZipFile(zip_buffer, "w") as z:
                            # Save model
                            model_path = "regression_model.pkl"
                            joblib.dump(model, model_path)
                            z.write(model_path)
                            
                            # Save metrics
                            metrics = f"MAE: {mae:.2f}\nR²: {r2:.2f}"
                            z.writestr("performance_metrics.txt", metrics)
                            
                            # Save plots
                            fig.savefig("regression_plots.png")
                            z.write("regression_plots.png")
                            
                            # Save cleaned data
                            df.to_csv("processed_data.csv", index=False)
                            z.write("processed_data.csv")

                        st.download_button(
                            label="⬇ Download ZIP Package",
                            data=zip_buffer.getvalue(),
                            file_name="regression_report.zip",
                            mime="application/zip"
                        )
                    except Exception as e:
                        st.error(f"Export failed: {str(e)}")

        except Exception as e:
            st.error(f"""
            ❗ Critical error loading data: {str(e)}
            
            Possible solutions:
            1. Check file encoding
            2. Verify CSV format
            3. Ensure valid column headers
            """)
            st.stop()

    else:
        st.info("Please upload a CSV dataset to begin analysis")

    st.markdown("---")
    st.caption("© 2025 AI Suite - Regression Model Module v2.0")