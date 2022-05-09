SHELL := /usr/bin/env bash

all: build run lint doc clean

# build:
# 	@echo Building
# 	rm -rf build
# 	mkdir -p build
# 	cmake -B./build -S./
# 	cd build && make

lint:
	@echo Linting Project
	clang-tidy  src/solution.cpp src/steering-angel-generator.cpp src/steering-angle-generator.hpp \
		-header-filter=.* --fix-errors --use-color -p build/*/**

doc:
	@echo Generate Documentation
	doxygen doxygen/Doxyfile

build:
	@echo building Project
	docker build -t group5/cyphy:latest -f Dockerfile .

run:
	@echo Running Project
	bash ./scripts/run-docker-container.sh

clean:
	@echo Cleaning up the project :D
	rm -rf build
	rm -rf doxygen/public



secret:
	@echo Secret
	echo "Secret command :D"

.PHONY: all build lint doc
