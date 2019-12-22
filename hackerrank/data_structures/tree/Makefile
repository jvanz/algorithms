.PHONY: image meson build clean all
	
all: build test

image:
	podman build -f Dockerfile -t buildenv:latest . 

meson:
	podman run --rm -ti -v $(shell pwd):/code localhost/buildenv:latest meson build 

build:
	clear
	echo "###############################################################"
	podman run --rm -ti -v $(shell pwd):/code localhost/buildenv:latest ninja -C build

test:
	./build/tests

clean:
	buildah rm --all
