# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SoftwareRenderer_Graphics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SoftwareRenderer_Graphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SoftwareRenderer_Graphics.dir/flags.make

CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.o: CMakeFiles/SoftwareRenderer_Graphics.dir/flags.make
CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.o -c /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/main.cpp

CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/main.cpp > CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.i

CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/main.cpp -o CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.s

# Object files for target SoftwareRenderer_Graphics
SoftwareRenderer_Graphics_OBJECTS = \
"CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.o"

# External object files for target SoftwareRenderer_Graphics
SoftwareRenderer_Graphics_EXTERNAL_OBJECTS =

SoftwareRenderer_Graphics: CMakeFiles/SoftwareRenderer_Graphics.dir/main.cpp.o
SoftwareRenderer_Graphics: CMakeFiles/SoftwareRenderer_Graphics.dir/build.make
SoftwareRenderer_Graphics: CMakeFiles/SoftwareRenderer_Graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SoftwareRenderer_Graphics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SoftwareRenderer_Graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SoftwareRenderer_Graphics.dir/build: SoftwareRenderer_Graphics

.PHONY : CMakeFiles/SoftwareRenderer_Graphics.dir/build

CMakeFiles/SoftwareRenderer_Graphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SoftwareRenderer_Graphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SoftwareRenderer_Graphics.dir/clean

CMakeFiles/SoftwareRenderer_Graphics.dir/depend:
	cd /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug /Users/amado-developer/College/Graphics/SoftwareRenderer-Graphics/cmake-build-debug/CMakeFiles/SoftwareRenderer_Graphics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SoftwareRenderer_Graphics.dir/depend

