#!/bin/bash -ex

cd "$(dirname "$(realpath "$0")")"
docker build -t appimage-thumbnailer -f Dockerfile .
docker run -i --rm --user "$(id -u)" \
	-v "$(realpath ..):/ws" \
	appimage-thumbnailer \
	sh -exc "cmake -B build . && cmake --build build"
