#!/usr/bin/env bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

opendlv-video-h264-replay --cid="20$3" --name="img$3" "$1" &
sleep 0.5
solution --cid="20$3" --name="img$3" --width=640 --height=480 --output="/opt/sources/verification-results/csvs/${2%.*}.csv"

unset SOLUTION_PID
