#!/bin/bash -ex

if [ -n "$1" ]; then
	BUILD_CMD="$1"
else
	BUILD_CMD="cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -B build . && cmake --build build"
fi

cd "$(dirname "$(realpath "$0")")"
docker build -t appimage-thumbnailer -f Dockerfile .
docker run -it --rm --user "$(id -u)" \
	-v "$(realpath ..):/ws" \
	appimage-thumbnailer \
	sh -exc "$BUILD_CMD"
