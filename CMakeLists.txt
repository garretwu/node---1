cmake_minimum_required(VERSION 2.6)

project(node--)

include_directories(
	include
	deps/boost/include
)

# gtest
add_executable(nodec-gtest
	gtest/gtest_main.cpp
	gtest/gtest_clonable.cpp
	gtest/gtest_immutable.cpp
	gtest/gtest_mutable.cpp
	gtest/gtest_noncopyable.cpp
	gtest/gtest_value.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

target_link_libraries(nodec-gtest
	gtest
)

# shared_ptr test
add_executable(nodec-shared_ptr-test
	test/test.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

set_target_properties(nodec-shared_ptr-test
	PROPERTIES COMPILE_FLAGS "-fno-rtti -fno-exceptions") 

# gc test
add_executable(nodec-gc-test
	test/test.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

target_link_libraries(nodec-gc-test
	gc
)

set_target_properties(nodec-gc-test
	PROPERTIES COMPILE_FLAGS "-fno-rtti -fno-exceptions -DNODEC_USE_BOEHM_GC")
