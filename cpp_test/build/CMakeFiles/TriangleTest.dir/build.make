# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/atulkrsngh/cpp/cpp_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/atulkrsngh/cpp/cpp_test/build

# Include any dependencies generated for this target.
include CMakeFiles/TriangleTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TriangleTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TriangleTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TriangleTest.dir/flags.make

CMakeFiles/TriangleTest.dir/triangle.cpp.o: CMakeFiles/TriangleTest.dir/flags.make
CMakeFiles/TriangleTest.dir/triangle.cpp.o: ../triangle.cpp
CMakeFiles/TriangleTest.dir/triangle.cpp.o: CMakeFiles/TriangleTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atulkrsngh/cpp/cpp_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TriangleTest.dir/triangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TriangleTest.dir/triangle.cpp.o -MF CMakeFiles/TriangleTest.dir/triangle.cpp.o.d -o CMakeFiles/TriangleTest.dir/triangle.cpp.o -c /home/atulkrsngh/cpp/cpp_test/triangle.cpp

CMakeFiles/TriangleTest.dir/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TriangleTest.dir/triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atulkrsngh/cpp/cpp_test/triangle.cpp > CMakeFiles/TriangleTest.dir/triangle.cpp.i

CMakeFiles/TriangleTest.dir/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TriangleTest.dir/triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atulkrsngh/cpp/cpp_test/triangle.cpp -o CMakeFiles/TriangleTest.dir/triangle.cpp.s

CMakeFiles/TriangleTest.dir/triangle_test.cpp.o: CMakeFiles/TriangleTest.dir/flags.make
CMakeFiles/TriangleTest.dir/triangle_test.cpp.o: ../triangle_test.cpp
CMakeFiles/TriangleTest.dir/triangle_test.cpp.o: CMakeFiles/TriangleTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atulkrsngh/cpp/cpp_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TriangleTest.dir/triangle_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TriangleTest.dir/triangle_test.cpp.o -MF CMakeFiles/TriangleTest.dir/triangle_test.cpp.o.d -o CMakeFiles/TriangleTest.dir/triangle_test.cpp.o -c /home/atulkrsngh/cpp/cpp_test/triangle_test.cpp

CMakeFiles/TriangleTest.dir/triangle_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TriangleTest.dir/triangle_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atulkrsngh/cpp/cpp_test/triangle_test.cpp > CMakeFiles/TriangleTest.dir/triangle_test.cpp.i

CMakeFiles/TriangleTest.dir/triangle_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TriangleTest.dir/triangle_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atulkrsngh/cpp/cpp_test/triangle_test.cpp -o CMakeFiles/TriangleTest.dir/triangle_test.cpp.s

# Object files for target TriangleTest
TriangleTest_OBJECTS = \
"CMakeFiles/TriangleTest.dir/triangle.cpp.o" \
"CMakeFiles/TriangleTest.dir/triangle_test.cpp.o"

# External object files for target TriangleTest
TriangleTest_EXTERNAL_OBJECTS =

TriangleTest: CMakeFiles/TriangleTest.dir/triangle.cpp.o
TriangleTest: CMakeFiles/TriangleTest.dir/triangle_test.cpp.o
TriangleTest: CMakeFiles/TriangleTest.dir/build.make
TriangleTest: /usr/local/lib/libgtest_main.a
TriangleTest: /usr/local/lib/libgtest.a
TriangleTest: CMakeFiles/TriangleTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/atulkrsngh/cpp/cpp_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TriangleTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TriangleTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TriangleTest.dir/build: TriangleTest
.PHONY : CMakeFiles/TriangleTest.dir/build

CMakeFiles/TriangleTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TriangleTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TriangleTest.dir/clean

CMakeFiles/TriangleTest.dir/depend:
	cd /home/atulkrsngh/cpp/cpp_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/atulkrsngh/cpp/cpp_test /home/atulkrsngh/cpp/cpp_test /home/atulkrsngh/cpp/cpp_test/build /home/atulkrsngh/cpp/cpp_test/build /home/atulkrsngh/cpp/cpp_test/build/CMakeFiles/TriangleTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TriangleTest.dir/depend
