FROM continuumio/miniconda3:4.12.0

RUN conda install xeus-cling -c QuantStack -c conda-forge -y && \
    conda install jupyterlab -c conda-forge -y && \
    conda clean --all -y

EXPOSE 9999

CMD ["jupyter", "lab", "--ip=*", "--port=9999", "--no-browser", "--allow-root", "--NotebookApp.token=''", "--NotebookApp.password=''"]
