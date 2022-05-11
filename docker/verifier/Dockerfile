# First stage for building the software:
FROM drakeaxelrod/cyphybuilder:0.0.1 as builder
LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

ENV DEBIAN_FRONTEND noninteractive
ADD ../../ /opt/sources
WORKDIR /opt/sources

RUN rm -rf build && \
  mkdir build && \
  cd build && \
  cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/tmp .. && \
  make && make test && /opt/sources/scripts/build.sh && make install

FROM python:latest
LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

RUN pip3 install numpy

COPY . /opt/sources/main.py
COPY --from=builder /tmp/bin/solution /opt/sources/


CMD [ "python3", "/opt/sources/main.py" ]
