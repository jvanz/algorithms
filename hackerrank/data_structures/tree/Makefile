

all: release debug

gyp:
	gyp build.gyp --depth=.

release:
	ninja -C out/Release

debug:
	ninja -C out/Debug

run-release:
	./out/Release/tests

run-debug:
	gdb ./out/Debug/tests

clean:
	ninja -C out/Release -t clean
	ninja -C out/Debug -t clean
