import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import zipfile
from io import BytesIO
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import silhouette_score
from sklearn.impute import SimpleImputer

def main():
    # State management
    if 'clustered_data' not in st.session_state:
        st.session_state.clustered_data = None
    if 'kmeans_model' not in st.session_state:
        st.session_state.kmeans_model = None
    if 'cluster_image' not in st.session_state:
        st.session_state.cluster_image = None

    st.title("🌌 Cluster Analyzer - Intelligent Data Segmentation")

    # File upload section
    st.header("1. Upload Your Dataset")
    uploaded_file = st.file_uploader("Drag CSV here", type=["csv"], key="cluster_upload")

    if uploaded_file is not None:
        # Encoding selection
        st.subheader("File Encoding Selection")
        encoding = st.selectbox(
            "Select file encoding (try Latin-1 if seeing errors)",
            ["utf-8", "latin-1", "iso-8859-1", "cp1252"],
            index=0
        )
        
        try:
            df = pd.read_csv(uploaded_file, encoding=encoding)
        except UnicodeDecodeError:
            st.error("""
            ❗ Failed to read file with selected encoding. Try:
            1. Latin-1 (for European characters)
            2. cp1252 (Windows Western European)
            3. iso-8859-1 (ISO Western European)
            """)
            st.stop()

        # Dataset preview
        st.subheader("Data Preview")
        with st.expander("View Dataset Structure"):
            st.dataframe(df.head(10), use_container_width=True)
            st.write(f"Shape: {df.shape}")

        # Data preprocessing
        st.header("2. Data Preparation")
        
        # Select numeric features
        numeric_cols = df.select_dtypes(include=np.number).columns.tolist()
        
        if len(numeric_cols) < 2:
            st.error("⚠️ Need at least 2 numeric features for clustering!")
        else:
            # Feature selection
            selected_features = st.multiselect(
                "Select Features for Clustering",
                numeric_cols,
                default=numeric_cols[:2],
                max_selections=3
            )
            
            # Handle missing values
            if df[selected_features].isnull().sum().sum() > 0:
                st.warning("Missing Values Detected!")
                na_strategy = st.radio(
                    "Handling Strategy:",
                    ["Remove Incomplete Records", "Impute with Mean"],
                    key="cluster_na"
                )
                
                if na_strategy == "Remove Incomplete Records":
                    df = df.dropna(subset=selected_features)
                else:
                    imputer = SimpleImputer(strategy='mean')
                    df[selected_features] = imputer.fit_transform(df[selected_features])

            # Data scaling
            scaler = StandardScaler()
            X_scaled = scaler.fit_transform(df[selected_features])

            # Cluster configuration
            st.header("3. Cluster Configuration")
            n_clusters = st.slider(
                "Select Number of Clusters",
                min_value=2,
                max_value=10,
                value=3,
                key="n_clusters"
            )

            # Model training
            kmeans = KMeans(n_clusters=n_clusters, random_state=42)
            clusters = kmeans.fit_predict(X_scaled)
            
            # Store in session state
            st.session_state.kmeans_model = kmeans
            df['Cluster'] = clusters
            st.session_state.clustered_data = df

            # Metrics calculation
            inertia = kmeans.inertia_
            silhouette = silhouette_score(X_scaled, clusters)

            # Results display
            st.header("Cluster Analysis")
            col1, col2 = st.columns(2)
            col1.metric("Within-Cluster Variance", f"{inertia:.2f}")
            col2.metric("Silhouette Score", f"{silhouette:.2f}")

            # Visualization
            st.subheader("Cluster Visualization")
            fig = plt.figure(figsize=(10, 6))
            
            if len(selected_features) == 2:
                # 2D Plot
                ax = fig.add_subplot(111)
                sns.scatterplot(
                    x=selected_features[0],
                    y=selected_features[1],
                    hue='Cluster',
                    data=df,
                    palette='viridis',
                    ax=ax
                )
                # Plot centroids
                centroids = scaler.inverse_transform(kmeans.cluster_centers_)
                ax.scatter(
                    centroids[:, 0],
                    centroids[:, 1],
                    marker='X',
                    s=200,
                    c='red',
                    label='Centroids'
                )
                ax.set_title("2D Cluster Visualization")
                ax.legend()
            
            elif len(selected_features) >= 3:
                # 3D Plot
                ax = fig.add_subplot(111, projection='3d')
                scatter = ax.scatter3D(
                    df[selected_features[0]],
                    df[selected_features[1]],
                    df[selected_features[2]],
                    c=clusters,
                    cmap='viridis',
                    s=50
                )
                
                # Plot centroids
                centroids = scaler.inverse_transform(kmeans.cluster_centers_)
                ax.scatter3D(
                    centroids[:, 0],
                    centroids[:, 1],
                    centroids[:, 2],
                    marker='X',
                    s=200,
                    c='red',
                    label='Centroids'
                )
                
                ax.set_xlabel(selected_features[0])
                ax.set_ylabel(selected_features[1])
                ax.set_zlabel(selected_features[2])
                ax.set_title("3D Cluster Visualization")
                fig.colorbar(scatter, ax=ax, label='Cluster')

            st.pyplot(fig)
            
            # Save visualization to session state
            img_buffer = BytesIO()
            fig.savefig(img_buffer, format='png', bbox_inches='tight')
            st.session_state.cluster_image = img_buffer.getvalue()
            plt.close(fig)

            # Download section
            st.header("4. Export Results")
            if st.button("Download Full Analysis Package"):
                try:
                    if st.session_state.clustered_data is None:
                        st.error("No clustered data available!")
                        st.stop()

                    zip_buffer = BytesIO()
                    with zipfile.ZipFile(zip_buffer, 'w', zipfile.ZIP_DEFLATED) as zip_file:
                        # Add clustered data
                        csv_data = st.session_state.clustered_data.to_csv(index=False)
                        zip_file.writestr("clustered_data.csv", csv_data)
                        
                        # Add visualization
                        if st.session_state.cluster_image:
                            zip_file.writestr("cluster_visualization.png", st.session_state.cluster_image)
                        else:
                            st.warning("Visualization image not found")

                    st.download_button(
                        label="⬇ Download ZIP Archive",
                        data=zip_buffer.getvalue(),
                        file_name="cluster_analysis.zip",
                        mime="application/zip"
                    )
                
                except Exception as e:
                    st.error(f"Export failed: {str(e)}")

    else:
        st.info("Please upload a dataset to begin clustering analysis")

    st.markdown("---")
    st.caption("© 2025 AI Suite - Cluster Analysis Module v1.0")