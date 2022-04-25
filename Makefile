SHELL := /usr/bin/env bash

all: build lint doc

build:
	@echo Building
	rm -rf build
	mkdir -p build
	cmake -B./build -S./
	cd build && make && make test

lint:
	@echo Linting Project
	clang-tidy src/*.cpp src/*.hpp --use-color -p build/*/**

doc:
	@echo Generate Documentation
	doxygen

.PHONY: all build lint doc
