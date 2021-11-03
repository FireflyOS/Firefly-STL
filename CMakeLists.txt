file(GLOB_RECURSE STL_SRC_FILES "*.cpp")
include_directories("../")
set(CMAKE_CXX_FLAGS "-I ../ -Wno-c99-extensions -m64 -std=gnu++17 -Wall -Wextra -pedantic -Werror -g -O2 -nostdlib -fno-builtin -fno-PIC -mno-red-zone -fno-stack-check -fno-stack-protector -fno-omit-frame-pointer -ffreestanding -fno-exceptions -fno-rtti -mno-sse -mno-sse2 -mno-80387 -mno-mmx -mno-3dnow")
add_library(STL ${STL_SRC_FILES})