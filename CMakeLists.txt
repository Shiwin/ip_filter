cmake_minimum_required(VERSION 3.13)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 17)     
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CXX_STANDARD_REQUEIRED ON)
set(COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

conan_set_find_paths()

find_package(GTest REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUEIRED ON
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
  )

target_link_libraries(test_version
  helloworld
  GTest::GTest
  GTest::Main
  )

target_link_libraries(helloworld_cli
  helloworld
  )

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT shriwand@gmail.com)

include(CPack)

enable_testing()
add_test(test_version bin/test_version )
