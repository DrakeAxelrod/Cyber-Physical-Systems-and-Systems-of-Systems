#!/bin/bash

# PATH_TO_BUILD_SCRIPT=/opt/sources/2022-group-05/bin/build.sh
function print_stage() {
    local sep="======================================================"
}

echo "THE SCRIPT HAS RUN"

# working dir once started is /opt/sources

# lcov --capture --directory build/CMakeFiles/Cyphy.dir --output-file coverage.info

# To read the coverage.info file
# genhtml build/CMakeFiles/coverage.info

# install lcov
# sudo apt install lcov