cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CCACHE_PROGRAM NAMES ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools")

project(tcr)

enable_testing()

add_subdirectory(third_party/googletest)
add_subdirectory(third_party/fml)
set(GOOGLETEST_PATH "third_party/googletest")
set(BENCHMARK_ENABLE_TESTING FALSE)
add_subdirectory(third_party/googlebenchmark)
set(SDL_SHARED FALSE)
set(SDL_STATIC TRUE)
set(SDL_TEST FALSE)
add_subdirectory(third_party/sdl)
add_subdirectory(third_party/glm)

include(GoogleTest)

add_library(tcr
  src/allocation.cc
  src/allocation.h
  src/color.cc
  src/color.h
  src/formats.cc
  src/formats.h
  src/texture.cc
  src/texture.h
)

target_compile_options(tcr
  PRIVATE
    -Werror
    -Wall
    -Wextra
    -Wno-unused-parameter
    -Wno-missing-field-initializers
    -Wno-unused-private-field
)

target_compile_definitions(tcr
  PUBLIC
    -D_CRT_SECURE_NO_WARNINGS
)

target_link_libraries(tcr
  fml
  glm::glm
)

target_include_directories(tcr
  PUBLIC
    src
    third_party/stb
)

add_executable(tcr_unittests
  src/unittests.cc
  src/playground.cc
  src/playground.h
)

target_link_libraries(tcr_unittests
  tcr
  gtest_main
  SDL3::SDL3
)

get_filename_component(TCR_ASSETS_LOCATION assets ABSOLUTE)
configure_file(src/fixtures_location.h.in fixtures_location.h @ONLY)
target_include_directories(tcr_unittests PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

gtest_discover_tests(tcr_unittests)

add_executable(tcr_benchmarks
  src/benchmarks.cc
)

target_link_libraries(tcr_benchmarks tcr benchmark::benchmark)
target_include_directories(tcr_benchmarks PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
