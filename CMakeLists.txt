cmake_minimum_required(VERSION 2.6)

# Setup
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests testlcd.cc lcd.cc)
target_compile_options(runTests PRIVATE -Werror -Wall -Wextra)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
