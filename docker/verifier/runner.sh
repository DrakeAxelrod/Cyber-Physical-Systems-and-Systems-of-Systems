#!/usr/bin/env bash

./opendlv-video-h264-replay --cid="20$3" --name="img$3" "$1" &
sleep 0.5
./solution --cid="20$3" --name="img$3" --width=640 --height=480 --output="./csvs/${2%.*}.csv" &
