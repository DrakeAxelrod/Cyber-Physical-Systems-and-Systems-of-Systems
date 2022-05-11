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
# Group5

# First stage for building the software:
FROM drakeaxelrod/cyphybuilder:0.0.1 as builder
LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

ENV DEBIAN_FRONTEND noninteractive
ADD . /opt/sources
WORKDIR /opt/sources

RUN rm -rf build && \
  mkdir build && \
  cd build && \
  cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/tmp .. && \
  make && make test && /opt/sources/scripts/build.sh && make install

FROM python:latest as verifier
LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

RUN pip3 install numpy && pip3 install seaborn && pip3 install matplotlib

COPY ./docker/verifier/ /opt/sources/
COPY --from=builder /tmp/bin/solution /opt/sources/

RUN python3 /opt/sources/main.py

# Second stage for packaging the software into a software bundle:
FROM drakeaxelrod/cyphyrunner:0.0.1
LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

ENV DEBIAN_FRONTEND noninteractive

WORKDIR /usr/bin

RUN apt-get update -y && apt-get upgrade -y

# COPY --from=builder /tmp/bin/solution .
COPY --from=verifier /opt/sources/ .

ENTRYPOINT ["/usr/bin/solution"]
