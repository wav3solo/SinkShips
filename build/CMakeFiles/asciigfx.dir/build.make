# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/illiasoloviov/Documents/GitHub/SinkShips

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/illiasoloviov/Documents/GitHub/SinkShips/build

# Include any dependencies generated for this target.
include CMakeFiles/asciigfx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/asciigfx.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/asciigfx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asciigfx.dir/flags.make

CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gfx.cpp
CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gfx.cpp

CMakeFiles/asciigfx.dir/gfx/gfx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/gfx.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gfx.cpp > CMakeFiles/asciigfx.dir/gfx/gfx.cpp.i

CMakeFiles/asciigfx.dir/gfx/gfx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/gfx.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gfx.cpp -o CMakeFiles/asciigfx.dir/gfx/gfx.cpp.s

CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/math2d.cpp
CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/math2d.cpp

CMakeFiles/asciigfx.dir/gfx/math2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/math2d.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/math2d.cpp > CMakeFiles/asciigfx.dir/gfx/math2d.cpp.i

CMakeFiles/asciigfx.dir/gfx/math2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/math2d.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/math2d.cpp -o CMakeFiles/asciigfx.dir/gfx/math2d.cpp.s

CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/scrollarea.cpp
CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/scrollarea.cpp

CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/scrollarea.cpp > CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.i

CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/scrollarea.cpp -o CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.s

CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridfont.cpp
CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridfont.cpp

CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridfont.cpp > CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.i

CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridfont.cpp -o CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.s

CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridarea.cpp
CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridarea.cpp

CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridarea.cpp > CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.i

CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridarea.cpp -o CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.s

CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridmenu.cpp
CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridmenu.cpp

CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridmenu.cpp > CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.i

CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/gridmenu.cpp -o CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.s

CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/polygon.cpp
CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/polygon.cpp

CMakeFiles/asciigfx.dir/gfx/polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/polygon.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/polygon.cpp > CMakeFiles/asciigfx.dir/gfx/polygon.cpp.i

CMakeFiles/asciigfx.dir/gfx/polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/polygon.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/polygon.cpp -o CMakeFiles/asciigfx.dir/gfx/polygon.cpp.s

CMakeFiles/asciigfx.dir/gfx/sound.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/sound.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/sound.cpp
CMakeFiles/asciigfx.dir/gfx/sound.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/asciigfx.dir/gfx/sound.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/sound.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/sound.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/sound.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/sound.cpp

CMakeFiles/asciigfx.dir/gfx/sound.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/sound.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/sound.cpp > CMakeFiles/asciigfx.dir/gfx/sound.cpp.i

CMakeFiles/asciigfx.dir/gfx/sound.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/sound.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/sound.cpp -o CMakeFiles/asciigfx.dir/gfx/sound.cpp.s

CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/joystick.cpp
CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/joystick.cpp

CMakeFiles/asciigfx.dir/gfx/joystick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/joystick.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/joystick.cpp > CMakeFiles/asciigfx.dir/gfx/joystick.cpp.i

CMakeFiles/asciigfx.dir/gfx/joystick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/joystick.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/joystick.cpp -o CMakeFiles/asciigfx.dir/gfx/joystick.cpp.s

CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/mouse.cpp
CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/mouse.cpp

CMakeFiles/asciigfx.dir/gfx/mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/mouse.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/mouse.cpp > CMakeFiles/asciigfx.dir/gfx/mouse.cpp.i

CMakeFiles/asciigfx.dir/gfx/mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/mouse.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/mouse.cpp -o CMakeFiles/asciigfx.dir/gfx/mouse.cpp.s

CMakeFiles/asciigfx.dir/gfx/util.cpp.o: CMakeFiles/asciigfx.dir/flags.make
CMakeFiles/asciigfx.dir/gfx/util.cpp.o: /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/util.cpp
CMakeFiles/asciigfx.dir/gfx/util.cpp.o: CMakeFiles/asciigfx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/asciigfx.dir/gfx/util.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/asciigfx.dir/gfx/util.cpp.o -MF CMakeFiles/asciigfx.dir/gfx/util.cpp.o.d -o CMakeFiles/asciigfx.dir/gfx/util.cpp.o -c /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/util.cpp

CMakeFiles/asciigfx.dir/gfx/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asciigfx.dir/gfx/util.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/util.cpp > CMakeFiles/asciigfx.dir/gfx/util.cpp.i

CMakeFiles/asciigfx.dir/gfx/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asciigfx.dir/gfx/util.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/illiasoloviov/Documents/GitHub/SinkShips/gfx/util.cpp -o CMakeFiles/asciigfx.dir/gfx/util.cpp.s

# Object files for target asciigfx
asciigfx_OBJECTS = \
"CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/sound.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o" \
"CMakeFiles/asciigfx.dir/gfx/util.cpp.o"

# External object files for target asciigfx
asciigfx_EXTERNAL_OBJECTS =

libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/gfx.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/math2d.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/scrollarea.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/gridfont.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/gridarea.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/gridmenu.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/polygon.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/sound.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/joystick.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/mouse.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/gfx/util.cpp.o
libasciigfx.a: CMakeFiles/asciigfx.dir/build.make
libasciigfx.a: CMakeFiles/asciigfx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library libasciigfx.a"
	$(CMAKE_COMMAND) -P CMakeFiles/asciigfx.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asciigfx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asciigfx.dir/build: libasciigfx.a
.PHONY : CMakeFiles/asciigfx.dir/build

CMakeFiles/asciigfx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/asciigfx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/asciigfx.dir/clean

CMakeFiles/asciigfx.dir/depend:
	cd /Users/illiasoloviov/Documents/GitHub/SinkShips/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/illiasoloviov/Documents/GitHub/SinkShips /Users/illiasoloviov/Documents/GitHub/SinkShips /Users/illiasoloviov/Documents/GitHub/SinkShips/build /Users/illiasoloviov/Documents/GitHub/SinkShips/build /Users/illiasoloviov/Documents/GitHub/SinkShips/build/CMakeFiles/asciigfx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asciigfx.dir/depend

