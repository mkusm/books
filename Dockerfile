FROM continuumio/miniconda3:4.12.0

RUN conda install xeus-cling -c QuantStack -c conda-forge -y && \
    conda install jupyterlab -c conda-forge -y && \
    conda install jupyterlab_vim -c conda-forge -y && \
    conda clean --all -y

# turn on jupyterlab dark theme
RUN mkdir -p /opt/conda/share/jupyter/lab/settings/ && \
    echo "{\"@jupyterlab/apputils-extension:themes\":{\"theme\":\"JupyterLab Dark\"}}" > \
    /opt/conda/share/jupyter/lab/settings/overrides.json

EXPOSE 9999

CMD ["jupyter", "lab", "--ip=*", "--port=9999", "--no-browser", "--allow-root", "--ServerApp.token=''", "--ServerApp.password=''"]
