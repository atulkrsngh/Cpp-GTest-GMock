cmake_minimum_required(VERSION 3.10)  # Specify the required CMake version
project(TriangleTest)                # Set the project name

# Find the Google Test package
find_package(GTest REQUIRED)

# Add the source files
add_executable(TriangleTest triangle.cpp triangle_test.cpp)

# Link the Google Test libraries and pthread
target_link_libraries(TriangleTest GTest::GTest GTest::Main pthread)