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
FROM ubuntu:18.04 as builder
LABEL group 5 "https://git.chalmers.se/courses/dit638/students/2022-group-05"

ENV DEBIAN_FRONTEND noninteractive

# Upgrade the Ubuntu 18.04 LTS base image
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get dist-upgrade -y

# Install the development libraries for OpenCV
RUN apt-get install -y --no-install-recommends \
        ca-certificates \
        cmake \
        build-essential \
        libopencv-dev \
        lcov \
        clang-tidy \
        pmccabe
