# Thumbnailer for AppImages

This project will contain a thumbnailer compatible with GNOME and KDE based DEs, to extract icons from AppImages (i.e. `.DirIcon`).

For now a proof of concept is provided in a bash script for GNOME only, using ImageMagick for resizing and the runtime from `AppImageKit`.

## Building

Clone this repository. Remember to clone submodules as well for dependencies:

```sh
git clone --recursive https://github.com/mttbernardini/appimage-thumbnailer
```

A `Makefile` is provided to run the build process in a isolated Docker container:

```sh
make help
```

## Roadmap

- [ ] Write tool in C++ to make it usable by both GNOME and KDE
- [ ] Set up build system and dependencies
- [ ] Set up distro packaging under the name of `appimage-thumbnailer`

---
© 2021 Matteo Bernardini

Licensed under the MIT License
