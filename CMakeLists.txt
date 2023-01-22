cmake_minimum_required (VERSION 3.20)

# Back compatibility for VERSION range
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy (VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project (
  data-tools
  VERSION 0.0.0
  DESCRIPTION "functional data structures and high-level constructs in c++"
  LANGUAGES CXX)

# Set cmake as import path for Find*.cmake files
include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Check if GTests is installed. If not, install it

option (PACKAGE_TESTS "Build the tests" OFF)

add_definitions ("-DHAS_BOOST")

if (PACKAGE_TESTS)
  include(CTest)
  find_package(GTest REQUIRED)
  enable_testing()
  add_subdirectory(test)

endif ()

# Add Library source files here

add_library (
  data-tools STATIC
  source/data/tools/types.cpp
  source/data/tools/valid.cpp
  source/data/math/limit.cpp
  source/data/tools/size.cpp
  source/data/tools/empty.cpp
  source/data/tools/sequence.cpp
  source/data/tools/fold.cpp
  source/data/tools/remove.cpp
  source/data/tools/contains.cpp
  source/data/tools/container.cpp
  source/data/tools/element.cpp
  source/data/tools/shuffle.cpp
  source/data/tools/sort.cpp
  source/data/tools/entry.cpp
  source/data/tools/insert.cpp
  source/data/tools/values.cpp
  source/data/tools/set.cpp
  source/data/tools/indexed.cpp
  source/data/tools/map.cpp
  source/data/tools/bi_tree.cpp
  source/data/tools/iterable.cpp
  source/data/tools/sequence_iterator.cpp
  source/data/tools.cpp
)

target_include_directories (data-tools PUBLIC include)

target_link_libraries (
  data-tools
  #CONAN_PKG::boost
)

get_target_property (OUT data-tools LINK_LIBRARIES)
message (STATUS ${OUT})

# Set C++ version
target_compile_features (data-tools PUBLIC cxx_std_20)
set_target_properties (data-tools PROPERTIES CXX_EXTENSIONS ON)
target_compile_options (data-tools PUBLIC "-fconcepts" "-fmodules-ts")

