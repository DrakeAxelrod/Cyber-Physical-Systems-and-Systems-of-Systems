#!/usr/bin/env bash


./opendlv-video-h264-replay --cid=253 --name=img "$1" &
sleep 0.1
./solution --cid=253 --name=img --width=640 --height=480 --output="./csvs/${2%.*}.csv" &
