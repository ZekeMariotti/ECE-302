# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code

# Include any dependencies generated for this target.
include CMakeFiles/sortedListTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sortedListTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sortedListTests.dir/flags.make

CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.o: CMakeFiles/sortedListTests.dir/flags.make
CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.o: test_sorted_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.o -c /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code/test_sorted_list.cpp

CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code/test_sorted_list.cpp > CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.i

CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code/test_sorted_list.cpp -o CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.s

# Object files for target sortedListTests
sortedListTests_OBJECTS = \
"CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.o"

# External object files for target sortedListTests
sortedListTests_EXTERNAL_OBJECTS =

sortedListTests: CMakeFiles/sortedListTests.dir/test_sorted_list.cpp.o
sortedListTests: CMakeFiles/sortedListTests.dir/build.make
sortedListTests: CMakeFiles/sortedListTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sortedListTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sortedListTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sortedListTests.dir/build: sortedListTests

.PHONY : CMakeFiles/sortedListTests.dir/build

CMakeFiles/sortedListTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sortedListTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sortedListTests.dir/clean

CMakeFiles/sortedListTests.dir/depend:
	cd /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW8/priority_queue_starter_code/priority_queue_starter_code/CMakeFiles/sortedListTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sortedListTests.dir/depend

