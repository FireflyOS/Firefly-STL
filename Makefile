CXX_FLAGS = -I./include -std=c++17 -Wall -Wextra -Werror -pedantic -O2 -g

# all source code
SRC_DIR = .
CXX_FILES = $(wildcard $(SRC_DIR)/*.cpp)

build:
	clang++ $(CXX_FLAGS) -c $(CXX_FILES)

all: build
