-include ../../flags.mk

build:
	rm stdio.o cstd.o || echo ""
	$(CC) $(STL_CXX_FLAGS) -c $(STL_CXX_FILES) $(STL_CXX_CSTDLIB_FILES)
