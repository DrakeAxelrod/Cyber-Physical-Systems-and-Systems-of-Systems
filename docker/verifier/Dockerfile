FROM python:latest
LABEL maintainer="<%= group5 %>"

RUN pip3 install numpy

COPY main.py /main.py

EXPOSE 9900

CMD [ "python3", "main.py" ]
