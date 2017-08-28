

all: release debug

release:
	ninja -C out/Release

debug:
	ninja -C out/Debug

run-release:
	./out/Release/tests

run-debug:
	gdb ./out/Debug/tests
