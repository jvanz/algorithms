.PHONY: image meson build clean

image:
	podman build -f Dockerfile -t buildenv:latest . 

meson:
	podman run --rm -ti -v $(shell pwd):/code localhost/buildenv:latest meson build

build:
	podman run --rm -ti -v $(shell pwd):/code localhost/buildenv:latest ninja -C build

clean:
	buildah rm --all
