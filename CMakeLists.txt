cmake_minimum_required(VERSION 2.6)

project(node--)

include_directories(
	include
	deps/boost/include
)

# gtest
add_executable(nodec-gtest
	gtest/gtest_main.cpp
	gtest/gtest_immutable.cpp
	gtest/gtest_mutable.cpp
	gtest/gtest_noncopyable.cpp
	gtest/gtest_value.cpp
	src/array.cpp
	src/http_server.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

target_link_libraries(nodec-gtest
	gtest
)

set_target_properties(nodec-gtest
	PROPERTIES COMPILE_FLAGS "-DNODEC_GTEST_BUILD_ERRORS")

# with shared_ptr
add_executable(nodec-with-sp
	src/array.cpp
	src/http_server.cpp
	src/main.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

set_target_properties(nodec-with-sp
	PROPERTIES COMPILE_FLAGS "-fno-rtti -fno-exceptions") 

# with boehm gc
add_executable(nodec-with-gc
	src/array.cpp
	src/http_server.cpp
	src/main.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

target_link_libraries(nodec-with-gc
	gc
)

set_target_properties(nodec-with-gc
	PROPERTIES COMPILE_FLAGS "-fno-rtti -fno-exceptions -DNODEC_USE_BOEHM_GC")
