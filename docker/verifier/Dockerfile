FROM python:latest
LABEL maintainer="<%= group5 %>"

RUN pip3 install numpy

COPY verifier.py /verifier.py

EXPOSE 9900

CMD [ "python3", "verifier.py" ]
