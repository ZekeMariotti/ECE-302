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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code

# Include any dependencies generated for this target.
include CMakeFiles/mainXMLParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainXMLParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainXMLParser.dir/flags.make

CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o: CMakeFiles/mainXMLParser.dir/flags.make
CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o: XMLParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o -c /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/XMLParser.cpp

CMakeFiles/mainXMLParser.dir/XMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainXMLParser.dir/XMLParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/XMLParser.cpp > CMakeFiles/mainXMLParser.dir/XMLParser.cpp.i

CMakeFiles/mainXMLParser.dir/XMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainXMLParser.dir/XMLParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/XMLParser.cpp -o CMakeFiles/mainXMLParser.dir/XMLParser.cpp.s

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o: CMakeFiles/mainXMLParser.dir/flags.make
CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o: mainXMLParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o -c /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/mainXMLParser.cpp

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/mainXMLParser.cpp > CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/mainXMLParser.cpp -o CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s

# Object files for target mainXMLParser
mainXMLParser_OBJECTS = \
"CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o" \
"CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o"

# External object files for target mainXMLParser
mainXMLParser_EXTERNAL_OBJECTS =

mainXMLParser: CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o
mainXMLParser: CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o
mainXMLParser: CMakeFiles/mainXMLParser.dir/build.make
mainXMLParser: CMakeFiles/mainXMLParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mainXMLParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainXMLParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainXMLParser.dir/build: mainXMLParser

.PHONY : CMakeFiles/mainXMLParser.dir/build

CMakeFiles/mainXMLParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainXMLParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainXMLParser.dir/clean

CMakeFiles/mainXMLParser.dir/depend:
	cd /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code /home/zeke/Desktop/ECE302/ECE-302/Project3/p3_starter_code/p3_starter_code/CMakeFiles/mainXMLParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainXMLParser.dir/depend

