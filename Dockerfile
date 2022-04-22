# Copyright (C) 2020  Christian Berger
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Modified by
# Drake Axelrod drake@draxel.io

# First stage for building the software:
FROM drakeaxelrod/cyphybuilder:0.0.1 as builder
# FROM ubuntu:18.04 as builder

LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

ENV DEBIAN_FRONTEND noninteractive

# Upgrade the Ubuntu 18.04 LTS base image
# RUN apt-get update -y && \
#     apt-get upgrade -y && \
#     apt-get dist-upgrade -y

# Install the development libraries for OpenCV
# RUN apt-get install -y --no-install-recommends \
#   ca-certificates \
#   cmake \
#   build-essential \
#   libopencv-dev

# Include this source tree and compile the sources
ADD . /opt/sources

WORKDIR /opt/sources

# RUN apt-get install -y --no-install-recommends \
#    ca-certificates \
#    cmake \
#    build-essential \
#    libopencv-dev \
#    lcov

RUN apt-get install -y --no-install-recommends lcov
   
RUN mkdir build && \
  cd build && \
  cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/tmp .. && \
  make && make test && make install && /opt/sources/scripts/build.sh

# # Second stage for packaging the software into a software bundle:
FROM drakeaxelrod/cyphyrunner:0.0.1
# FROM ubuntu:18.04

LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

ENV DEBIAN_FRONTEND noninteractive

# RUN apt-get update -y && \
#   apt-get upgrade -y && \
#   apt-get dist-upgrade -y

# RUN apt-get install -y --no-install-recommends \
#   libopencv-core3.2 \
#   libopencv-highgui3.2 \
#   libopencv-imgproc3.2

RUN apt-get install -y --no-install-recommends lcov

WORKDIR /usr/bin

COPY --from=builder /tmp/bin/SensorReading .
COPY --from=builder /opt/sources/build/coverage.info .

RUN apt-get install -y --no-install-recommends lcov

# This is the entrypoint when starting the Docker container; hence, this Docker image is automatically starting our software on its creation
ENTRYPOINT ["/usr/bin/SensorReading"]


# # RUN apt-get install -y --no-install-recommends \
# #   ca-certificates \
# #   cmake \
# #   build-essential \
# #   libopencv-dev \
# #   lcov
