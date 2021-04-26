DOCKER_IMAGE := appimage-thumbnailer
DOCKER_RUN   := docker run -i --rm --user "$$(id -u)" -v "$$(realpath .):/ws"
BUID_TYPE    := RelWithDebInfo

.PHONY: help image deps ci package shell

help:
	@echo "## available targets ##"
	@echo "image          build Docker image for reproducible and isolated builds"
	@echo "deps           install dependencies locally (not necessary if building in Docker)"
	@echo "ci             build project using cmake (in Docker container)"
	@echo "package        generate packages using cpack (in Docker container)"
	@echo "shell          run bash in Docker container for development inspection"
	@echo
	@echo "## settable variables#"
	@echo "IGNORE_DOCKER  run targets in host machine rather than Docker container"
	@echo "DOCKER_IMAGE   name of Docker image (default: appimage-thumbnailer)"
	@echo "BUILD_TYPE     cmake build type (default: RelWithDebInfo)"

image:
	docker build -t $(DOCKER_IMAGE) -f ci/Dockerfile ci/

deps:
	bash ci/install-deps.sh

ci: $(if $(IGNORE_DOCKER),,image)
	$(if $(IGNORE_DOCKER),,$(DOCKER_RUN) $(DOCKER_IMAGE)) bash -exc "cmake -DCMAKE_BUILD_TYPE=$(BUID_TYPE) -B build .; cmake --build build"

package: $(if $(IGNORE_DOCKER),,image)
	$(if $(IGNORE_DOCKER),,$(DOCKER_RUN) $(DOCKER_IMAGE)) bash -exc "cd build; cpack -V"
	mkdir -p packages/
	-mv build/*.deb packages/
	-mv build/*.rpm packages/

shell: image
	$(DOCKER_RUN) -t $(DOCKER_IMAGE) bash
