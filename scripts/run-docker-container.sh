#!/usr/bin/env bash

xhost + && docker run --rm -ti --net=host --ipc=host -e DISPLAY=$DISPLAY -v /tmp:/tmp group5/cyphy:latest --cid=253 --name=img --width=640 --height=480 --output="/opt/sources/verification-results/csvs/${2%.*}.csv" --verbose 
