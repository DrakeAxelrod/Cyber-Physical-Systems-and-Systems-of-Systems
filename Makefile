SHELL := /usr/bin/env bash

all: build run verify lint doc clean

lint:
	@echo Linting Project
	clang-tidy  src/solution.cpp src/steering-angel-generator.cpp src/steering-angle-generator.hpp \
		-header-filter=.* --fix-errors -p build/*/**

doc:
	@echo Generate Documentation
	doxygen doxygen/Doxyfile

build:
	@echo building Project
	docker build -t group5/cyphy:latest -f Dockerfile .

run:
	@echo Running Project
	bash ./scripts/run-docker-container.sh

verify:
	@echo Verifying Project
	docker build -t group5/verifier:latest -f Dockerfile.verifier .

clean:
	@echo Cleaning up the project :D
	rm -rf build
	rm -rf doxygen/public

secret:
	@echo Secret
	echo "Secret command :D"

.PHONY: all build lint doc
