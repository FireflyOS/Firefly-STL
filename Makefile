CXX_FLAGS = -m64 -std=c++17 -Wall -Wextra -pedantic -Werror -g -O2 -nostdlib -fno-builtin -fno-PIC -mno-red-zone -fno-stack-check -fno-stack-protector -fno-omit-frame-pointer -ffreestanding -fno-exceptions -fno-rtti

# all source code
SRC_DIR = .
CXX_FILES = $(wildcard $(SRC_DIR)/*.cpp)
CXX_CSTDLIB_FILES = $(wildcard $(SRC_DIR)/cstdlib/*.cpp)

build:
	clang++ $(CXX_FLAGS) -c $(CXX_FILES) $(CXX_CSTDLIB_FILES)

all: build
