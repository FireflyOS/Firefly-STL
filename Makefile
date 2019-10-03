CXX_FLAGS = -I./include -target x86_64-unknown-elf -m64 -std=c++17 -Wall -Wextra -Werror -pedantic -O2 -g

# all source code
SRC_DIR = .
CXX_FILES = $(wildcard $(SRC_DIR)/*.cpp)

build:
	clang++ $(CXX_FLAGS) -c $(CXX_FILES)

all: build
