# Thumbnailer for AppImages

This project contains a thumbnailer for AppImages, compatible with GNOME and KDE based DEs.

For now the code is still in draft (e.g. `.DirIcon` is extracted without resizing) and has not been thoroughly tested yet.

## Building

Clone this repository. Remember to clone submodules as well for dependencies (`libappimage`):

```sh
git clone --recursive https://github.com/mttbernardini/appimage-thumbnailer
```

A `Makefile` is provided to run the build process in a isolated Docker container:

```sh
make help
```

## Roadmap

- [x] Write thumbnailer in C/C++ to make it usable by both GNOME and KDE, using `libappimage`
- [x] Set up build system and dependencies
- [ ] Set up distro packaging under the name of `appimage-thumbnailer`

---
© 2021 Matteo Bernardini

Licensed under the MIT License
