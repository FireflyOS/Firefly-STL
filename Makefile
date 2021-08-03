-include ../../flags.mk

build:
	$(CC) $(STL_CXX_FLAGS) -c $(STL_CXX_FILES) $(STL_CXX_CSTDLIB_FILES)
