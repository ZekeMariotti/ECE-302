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
CMAKE_SOURCE_DIR = /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code

# Utility rule file for submission.

# Include the progress variables for this target.
include CMakeFiles/submission.dir/progress.make

CMakeFiles/submission:
	/usr/bin/cmake -E tar cfv /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code/hw5_postfix_prefix.zip --format=zip postpre.cpp algebraic_expressions.cpp algebraic_expressions.hpp

submission: CMakeFiles/submission
submission: CMakeFiles/submission.dir/build.make

.PHONY : submission

# Rule to build all files generated by this target.
CMakeFiles/submission.dir/build: submission

.PHONY : CMakeFiles/submission.dir/build

CMakeFiles/submission.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/submission.dir/cmake_clean.cmake
.PHONY : CMakeFiles/submission.dir/clean

CMakeFiles/submission.dir/depend:
	cd /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code /home/zeke/Desktop/ECE302/ECE-302/HW5/postfix_prefix_starter_code/postfix_prefix_starter_code/CMakeFiles/submission.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/submission.dir/depend

