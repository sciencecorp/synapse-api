UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)
ifeq ($(UNAME_S),Darwin)
	ifeq ($(UNAME_M),arm64)
		TRIPLET := arm64-osx-dynamic
	else
		TRIPLET := x64-osx-dynamic
	endif
else
	TRIPLET := x64-linux
endif

.PHONY: all
all: clean configure build

.PHONY: clean
clean:
	rm -rf build
	rm -f cli

.PHONY: configure
configure:
	cmake --preset dynamic -DVCPKG_TARGET_TRIPLET=${TRIPLET}

.PHONY: build
build:
	cmake --build --preset debug --target libsynapse

.PHONY: install
install:
	cmake --install build

.PHONY: lint
lint:
	cpplint --recursive .
	find src -name "*.cpp" | xargs clang-tidy -p build

