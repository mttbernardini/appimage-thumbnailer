#!/bin/bash

if [[ "$CI" == "" ]]; then
	echo "Caution: this script is supposed to run inside a (disposable) CI environment"
	echo "It will alter a system, and should not be run on workstations or alike"
	echo "You can export CI=1 to prevent this error from being shown again"
	exit 3
fi

packages=(
	# libappimage deps
	libfuse-dev
	desktop-file-utils
	ca-certificates
	gcc-multilib
	g++-multilib
	make
	build-essential
	git
	automake
	autoconf
	libtool
	patch
	wget
	vim-common
	desktop-file-utils
	pkg-config
	libarchive-dev
	librsvg2-dev
	librsvg2-bin
	liblzma-dev
	cmake
	lcov
	gcovr

	# gnome-part deps

	# kde-part deps
)

apt-get update
apt-get -y --no-install-recommends install "${packages[@]}"
