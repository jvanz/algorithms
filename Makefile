.PHONY: image meson build clean all preorder posorder

all: clean meson build test

image:
	podman build -f Dockerfile -t buildenv:latest .

meson:
	podman run --rm -ti -v $(shell pwd):/code localhost/buildenv:latest meson build

build:
	clear
	podman run --rm -ti -v $(shell pwd):/code localhost/buildenv:latest ninja -C build
test:
	./build/tests

gdb:
	gdb -d ./build  ./build/tests

clean:
	rm -rf build
