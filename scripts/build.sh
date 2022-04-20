#!/bin/bash

# /opt/sources

# lcov --capture --directory SensorReading-Runner.dir/src --output-file coverage-runner.info

function declare_section() {
    echo "================================================================================"
    echo $@
    echo "================================================================================"
}

function output() {
cat << EOF
$@
EOF
}

function run_code() {
    output $(/opt/sources/build/SensorReading-Runner)
}

function run_lcov() {
    local dir="/opt/sources/build/CMakeFiles/SensorReading-Runner.dir/src"
    local file="/opt/sources/build/coverage.info"
    output $(lcov --capture --directory $dir --output-file $file)
    output $(genhtml $file -o /opt/sources/build)
}

declare_section "Running build.sh"

run_code &> /dev/null

declare_section "Generating Code Coverage"

run_lcov &> /dev/null

lcov --list /opt/sources/build/coverage.info 2>/dev/null

declare_section "Finished Running"
