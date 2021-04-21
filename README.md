# Thumbnailer for AppImages

This project will contain a thumbnailer compatible with GNOME and KDE based DEs, to extract icons from AppImages (i.e. `.DirIcon`).

For now a proof of concept is provided in a bash script for GNOME only, using ImageMagick for resizing and the runtime from `AppImageKit`.

## Building

First clone this repository. Remember to clone submodules as well for dependencies:

```sh
git clone --recursive https://github.com/mttbernardini/appimage-thumbnailer
```

Then, there are two options. One is to run the build on your machine by installing the dependencies globally:

```sh
# this script assumes a debian-like environment, adjust it if necessary
sudo CI=1 ./ci/install-deps.sh
# build using cmake
cmake -B build .
cmake --build build
```

The other (better) option is to run the build in a disposable Docker container (getting reproducible builds), by simply running this script:

```sh
# this script assumes `docker` to be runnable by the current user, adjust it if necessary (e.g. by prepending `sudo`)
./ci/build.sh
```

## Roadmap

- [ ] Write tool in C++ to make it usable by both GNOME and KDE
- [ ] Set up build system and dependencies
- [ ] Set up distro packaging under the name of `appimage-thumbnailer`

---
© 2021 Matteo Bernardini

Licensed under the MIT License
