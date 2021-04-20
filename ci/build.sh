#!/bin/bash

cd "$(dirname "$0")"
docker build -t appimage-thumbnailer -f Dockerfile .
docker run -i --rm --user "$(id -u)" \
	-v "$(realpath ..):/ws" \
	appimage-thumbnailer \
	sh -xc "cmake -B build . && cmake --build build" \
