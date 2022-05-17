#!/bin/bash

# /opt/sources

# lcov --capture --directory SensorReading-Runner.dir/src --output-file coverage-runner.info

function declare_section() {
    echo "================================================================================"
    echo "$@"
    echo "================================================================================"
}

function output() {
cat << EOF
$@
EOF

}

function run_code() {
    output "$(/opt/sources/build/solution-Runner)"
}

function lint() {
  clang-tidy  src/solution.cpp src/steering-angle-generator.cpp src/steering-angle-generator.hpp \
		-header-filter=.* --fix-errors -p build/*/**
}
function run_lcov() {
    local dir="/opt/sources/build/CMakeFiles/solution-Runner.dir/src/test"
    local file="/opt/sources/build/coverage.info"
    output "$(lcov --capture --directory $dir --output-file $file )"

    lcov --remove coverage.info '/usr/include/*' 'opt/sources/src/include/*' -o filtered_coverage.info &> /dev/null

    rm coverage.info && mv filtered_coverage.info coverage.info

    output "$(genhtml $file -o /opt/sources/build)"
}

function run_pmccabe() {
    local dir="/opt/sources/src"
    local file="*.cpp" #to change during sprint 2 
    apt-get install -y pmccabe #to delete once pmccabe is installed in docker
    output "$(pmccabe -vc $dir/$file)"
}

declare_section "Running Tests"

run_code

declare_section "Displaying Linting information"

lint

declare_section "Generating Code Coverage"

run_lcov

lcov --list /opt/sources/build/coverage.info

declare_section "Generating Complexity"

run_pmccabe 

declare_section "Finished Running"
