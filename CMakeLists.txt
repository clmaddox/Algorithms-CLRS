# CMakeLists files in this project can
# refer to the root source directory of the project as ${ALGORITHMS_CLRS_SOURCE_DIR} and
# to the root binary directory of the project as ${ALGORITHMS_CLRS_BINARY_DIR}.
cmake_minimum_required (VERSION 3.9.1)
project(ALGORITHMS_CLRS VERSION 1.0.0 LANGUAGES CXX)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")

# Conan setup
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_compile_options(-W -Wall -Werror)

# Soring Library
set(SORTING_LIB sorting)
set(SORTING_INCLUDE_DIR ${ALGORITHMS_CLRS_SOURCE_DIR}/sorting/include)
set(SORTING_SOURCE_DIR ${ALGORITHMS_CLRS_SOURCE_DIR}/sorting/src)
set(SORTING_INCLUDES ${SORTING_INCLUDE_DIR}/insertionSort.hpp)
set(SORTING_SOURCES ${SORTING_SOURCE_DIR}/insertionSort.cpp)

add_library(${SORTING_LIB} ${SORTING_SOURCES})
target_include_directories(${SORTING_LIB} PRIVATE ${SORTING_INCLUDE_DIR})

# Sorting Tests
set(SORTING_TEST sorting_tests)

add_executable(${SORTING_TEST} ${ALGORITHMS_CLRS_SOURCE_DIR}/unittest/insertionSortTest.cpp)
target_include_directories(${SORTING_TEST} PRIVATE ${SORTING_INCLUDE_DIR}
                                                   ${CONAN_INCLUDE_DIRS_BOOST})
target_link_libraries(${SORTING_TEST} ${CONAN_LIBS_BOOST})
target_link_libraries(${SORTING_TEST} ${ALGORITHMS_CLRS_SOURCE_DIR}/lib/lib${SORTING_LIB}.a)
