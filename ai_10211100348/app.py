# main_dashboard.py
import streamlit as st
import importlib.util
from pathlib import Path
import sys

# Configuration
MODULES = {
    "🏠 Home": "home",
    "📈 Regression": "src/regression/regression",
    "🌌 Clustering": "src/clustering/clustering",
    "🧠 Neural Network": "src/neural/neural_network",
    "💬 RAG-LLM": "src/rag_llm/rag"
}

def load_module(module_path):
    try:
        module_file = Path(f"{module_path}.py")
        spec = importlib.util.spec_from_file_location(module_path, module_file)
        module = importlib.util.module_from_spec(spec)
        sys.modules[module_path] = module
        spec.loader.exec_module(module)
        return module
    except Exception as e:
        st.error(f"Failed to load module: {str(e)}")
        st.stop()

def main():
    st.set_page_config(
        page_title="AI Suite Dashboard",
        layout="wide",
        initial_sidebar_state="collapsed"
    )
    
    # Initialize session state
    if 'current_module' not in st.session_state:
        st.session_state.current_module = "🏠 Home"
    
    # Navigation buttons
    cols = st.columns(len(MODULES))
    for idx, (name, path) in enumerate(MODULES.items()):
        with cols[idx]:
            if st.button(name, key=f"nav_{idx}", use_container_width=True):
                st.session_state.current_module = name

    st.markdown("---")

    # Module routing
    if st.session_state.current_module == "🏠 Home":
        st.title("AI Suite Dashboard")
        st.markdown("""
        ### Comprehensive Machine Learning Platform
        Select a module from the navigation buttons above
        """)
        cols = st.columns(4)
        modules = list(MODULES.keys())[1:]
        for idx, col in enumerate(cols):
            with col:
                st.subheader(modules[idx])
                st.image(f"images/module_{idx+1}.png", use_container_width=True)
    else:
        module_path = MODULES[st.session_state.current_module]
        try:
            module = load_module(module_path)
            module.main()
        except Exception as e:
            st.error(f"Error in {st.session_state.current_module} module: {str(e)}")

if __name__ == "__main__":
    main()