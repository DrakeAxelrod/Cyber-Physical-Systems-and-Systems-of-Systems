SHELL := /usr/bin/env bash

all: build lint doc clean

build:
	@echo Building
	rm -rf build
	mkdir -p build
	cmake -B./build -S./
	cd build && make && make test

lint:
	@echo Linting Project
	clang-tidy \
		src/cyphy.cpp src/SensorReading.cpp \
		src/cyphy.hpp src/SensorReading.hpp \
		-header-filter=.* --fix-errors --use-color -p build/*/**

doc:
	@echo Generate Documentation
	rm -rf docs
	doxygen

clean:
	@echo Cleaning up the project :D
	rm -rf build
	rm -rf public

secret:
	@echo Secret
	echo "Secret command :D"

.PHONY: all build lint doc
