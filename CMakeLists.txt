cmake_minimum_required(VERSION 2.6)

project(node--)

find_package(Boost)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "boost not found.")
endif()

find_library(GC gc REQUIRED)
if(NOT EXISTS ${GC})
    message(FATAL_ERROR "libgc not found.")
endif()

find_library(PTHREAD pthread REQUIRED)
if(NOT EXISTS ${PTHREAD})
    message(FATAL_ERROR "libpthread not found.")
endif()

find_library(GTEST gtest REQUIRED)
if(NOT EXISTS ${GTEST})
    message(FATAL_ERROR "libgtest not found.")
endif()

include_directories(
	include
	deps/boost/include
)

# gtest
add_executable(nodec-gtest
	gtest/gtest_main.cpp
	gtest/gtest_immutable.cpp
	gtest/gtest_mutable.cpp
	gtest/gtest_singleton.cpp
	gtest/gtest_value.cpp
	src/array.cpp
	src/http_server.cpp
	src/no_exceptions.cpp
	src/string.cpp
)

target_link_libraries(nodec-gtest
	gtest
	pthread
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

