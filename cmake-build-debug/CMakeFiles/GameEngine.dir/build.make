# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /home/danil/JetBrains/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/danil/JetBrains/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danil/CLionProjects/GE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danil/CLionProjects/GE/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GameEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameEngine.dir/flags.make

CMakeFiles/GameEngine.dir/main.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/CLionProjects/GE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameEngine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/main.cpp.o -c /home/danil/CLionProjects/GE/main.cpp

CMakeFiles/GameEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/CLionProjects/GE/main.cpp > CMakeFiles/GameEngine.dir/main.cpp.i

CMakeFiles/GameEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/CLionProjects/GE/main.cpp -o CMakeFiles/GameEngine.dir/main.cpp.s

CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.o: ../InputSystem/InputSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/CLionProjects/GE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.o -c /home/danil/CLionProjects/GE/InputSystem/InputSystem.cpp

CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/CLionProjects/GE/InputSystem/InputSystem.cpp > CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.i

CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/CLionProjects/GE/InputSystem/InputSystem.cpp -o CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.s

CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.o: ../InputSystem/CKeyboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/CLionProjects/GE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.o -c /home/danil/CLionProjects/GE/InputSystem/CKeyboard.cpp

CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/CLionProjects/GE/InputSystem/CKeyboard.cpp > CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.i

CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/CLionProjects/GE/InputSystem/CKeyboard.cpp -o CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.s

CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.o: ../CTimer/CTimer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/CLionProjects/GE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.o -c /home/danil/CLionProjects/GE/CTimer/CTimer.cpp

CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/CLionProjects/GE/CTimer/CTimer.cpp > CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.i

CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/CLionProjects/GE/CTimer/CTimer.cpp -o CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.s

# Object files for target GameEngine
GameEngine_OBJECTS = \
"CMakeFiles/GameEngine.dir/main.cpp.o" \
"CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.o" \
"CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.o" \
"CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.o"

# External object files for target GameEngine
GameEngine_EXTERNAL_OBJECTS =

GameEngine: CMakeFiles/GameEngine.dir/main.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/InputSystem/InputSystem.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/InputSystem/CKeyboard.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/CTimer/CTimer.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/build.make
GameEngine: /usr/lib/x86_64-linux-gnu/libOpenGL.so
GameEngine: /usr/lib/x86_64-linux-gnu/libGLX.so
GameEngine: /usr/lib/x86_64-linux-gnu/libGLU.so
GameEngine: /usr/lib/x86_64-linux-gnu/libglfw.so.3.2
GameEngine: CMakeFiles/GameEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danil/CLionProjects/GE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable GameEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameEngine.dir/build: GameEngine

.PHONY : CMakeFiles/GameEngine.dir/build

CMakeFiles/GameEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameEngine.dir/clean

CMakeFiles/GameEngine.dir/depend:
	cd /home/danil/CLionProjects/GE/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danil/CLionProjects/GE /home/danil/CLionProjects/GE /home/danil/CLionProjects/GE/cmake-build-debug /home/danil/CLionProjects/GE/cmake-build-debug /home/danil/CLionProjects/GE/cmake-build-debug/CMakeFiles/GameEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameEngine.dir/depend

