# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/app.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/app.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/app.cpp
CMakeFiles/main.dir/src/app.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/app.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/app.cpp.o -MF CMakeFiles/main.dir/src/app.cpp.o.d -o CMakeFiles/main.dir/src/app.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/app.cpp

CMakeFiles/main.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/app.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/app.cpp > CMakeFiles/main.dir/src/app.cpp.i

CMakeFiles/main.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/app.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/app.cpp -o CMakeFiles/main.dir/src/app.cpp.s

CMakeFiles/main.dir/src/b2e_camera.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_camera.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera.cpp
CMakeFiles/main.dir/src/b2e_camera.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/b2e_camera.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_camera.cpp.o -MF CMakeFiles/main.dir/src/b2e_camera.cpp.o.d -o CMakeFiles/main.dir/src/b2e_camera.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera.cpp

CMakeFiles/main.dir/src/b2e_camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_camera.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera.cpp > CMakeFiles/main.dir/src/b2e_camera.cpp.i

CMakeFiles/main.dir/src/b2e_camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_camera.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera.cpp -o CMakeFiles/main.dir/src/b2e_camera.cpp.s

CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera_controller.cpp
CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o -MF CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o.d -o CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera_controller.cpp

CMakeFiles/main.dir/src/b2e_camera_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_camera_controller.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera_controller.cpp > CMakeFiles/main.dir/src/b2e_camera_controller.cpp.i

CMakeFiles/main.dir/src/b2e_camera_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_camera_controller.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_camera_controller.cpp -o CMakeFiles/main.dir/src/b2e_camera_controller.cpp.s

CMakeFiles/main.dir/src/b2e_device.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_device.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_device.cpp
CMakeFiles/main.dir/src/b2e_device.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/b2e_device.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_device.cpp.o -MF CMakeFiles/main.dir/src/b2e_device.cpp.o.d -o CMakeFiles/main.dir/src/b2e_device.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_device.cpp

CMakeFiles/main.dir/src/b2e_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_device.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_device.cpp > CMakeFiles/main.dir/src/b2e_device.cpp.i

CMakeFiles/main.dir/src/b2e_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_device.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_device.cpp -o CMakeFiles/main.dir/src/b2e_device.cpp.s

CMakeFiles/main.dir/src/b2e_game_object.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_game_object.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_game_object.cpp
CMakeFiles/main.dir/src/b2e_game_object.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/b2e_game_object.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_game_object.cpp.o -MF CMakeFiles/main.dir/src/b2e_game_object.cpp.o.d -o CMakeFiles/main.dir/src/b2e_game_object.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_game_object.cpp

CMakeFiles/main.dir/src/b2e_game_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_game_object.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_game_object.cpp > CMakeFiles/main.dir/src/b2e_game_object.cpp.i

CMakeFiles/main.dir/src/b2e_game_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_game_object.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_game_object.cpp -o CMakeFiles/main.dir/src/b2e_game_object.cpp.s

CMakeFiles/main.dir/src/b2e_model.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_model.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_model.cpp
CMakeFiles/main.dir/src/b2e_model.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/b2e_model.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_model.cpp.o -MF CMakeFiles/main.dir/src/b2e_model.cpp.o.d -o CMakeFiles/main.dir/src/b2e_model.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_model.cpp

CMakeFiles/main.dir/src/b2e_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_model.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_model.cpp > CMakeFiles/main.dir/src/b2e_model.cpp.i

CMakeFiles/main.dir/src/b2e_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_model.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_model.cpp -o CMakeFiles/main.dir/src/b2e_model.cpp.s

CMakeFiles/main.dir/src/b2e_pipeline.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_pipeline.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_pipeline.cpp
CMakeFiles/main.dir/src/b2e_pipeline.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/b2e_pipeline.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_pipeline.cpp.o -MF CMakeFiles/main.dir/src/b2e_pipeline.cpp.o.d -o CMakeFiles/main.dir/src/b2e_pipeline.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_pipeline.cpp

CMakeFiles/main.dir/src/b2e_pipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_pipeline.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_pipeline.cpp > CMakeFiles/main.dir/src/b2e_pipeline.cpp.i

CMakeFiles/main.dir/src/b2e_pipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_pipeline.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_pipeline.cpp -o CMakeFiles/main.dir/src/b2e_pipeline.cpp.s

CMakeFiles/main.dir/src/b2e_renderer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_renderer.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_renderer.cpp
CMakeFiles/main.dir/src/b2e_renderer.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/b2e_renderer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_renderer.cpp.o -MF CMakeFiles/main.dir/src/b2e_renderer.cpp.o.d -o CMakeFiles/main.dir/src/b2e_renderer.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_renderer.cpp

CMakeFiles/main.dir/src/b2e_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_renderer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_renderer.cpp > CMakeFiles/main.dir/src/b2e_renderer.cpp.i

CMakeFiles/main.dir/src/b2e_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_renderer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_renderer.cpp -o CMakeFiles/main.dir/src/b2e_renderer.cpp.s

CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_swap_chain.cpp
CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o -MF CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o.d -o CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_swap_chain.cpp

CMakeFiles/main.dir/src/b2e_swap_chain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_swap_chain.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_swap_chain.cpp > CMakeFiles/main.dir/src/b2e_swap_chain.cpp.i

CMakeFiles/main.dir/src/b2e_swap_chain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_swap_chain.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_swap_chain.cpp -o CMakeFiles/main.dir/src/b2e_swap_chain.cpp.s

CMakeFiles/main.dir/src/b2e_window.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/b2e_window.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_window.cpp
CMakeFiles/main.dir/src/b2e_window.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.dir/src/b2e_window.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/b2e_window.cpp.o -MF CMakeFiles/main.dir/src/b2e_window.cpp.o.d -o CMakeFiles/main.dir/src/b2e_window.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_window.cpp

CMakeFiles/main.dir/src/b2e_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/b2e_window.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_window.cpp > CMakeFiles/main.dir/src/b2e_window.cpp.i

CMakeFiles/main.dir/src/b2e_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/b2e_window.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/b2e_window.cpp -o CMakeFiles/main.dir/src/b2e_window.cpp.s

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/main.cpp
CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.cpp.o -MF CMakeFiles/main.dir/src/main.cpp.o.d -o CMakeFiles/main.dir/src/main.cpp.o -c /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/app.cpp.o" \
"CMakeFiles/main.dir/src/b2e_camera.cpp.o" \
"CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o" \
"CMakeFiles/main.dir/src/b2e_device.cpp.o" \
"CMakeFiles/main.dir/src/b2e_game_object.cpp.o" \
"CMakeFiles/main.dir/src/b2e_model.cpp.o" \
"CMakeFiles/main.dir/src/b2e_pipeline.cpp.o" \
"CMakeFiles/main.dir/src/b2e_renderer.cpp.o" \
"CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o" \
"CMakeFiles/main.dir/src/b2e_window.cpp.o" \
"CMakeFiles/main.dir/src/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/app.cpp.o
main: CMakeFiles/main.dir/src/b2e_camera.cpp.o
main: CMakeFiles/main.dir/src/b2e_camera_controller.cpp.o
main: CMakeFiles/main.dir/src/b2e_device.cpp.o
main: CMakeFiles/main.dir/src/b2e_game_object.cpp.o
main: CMakeFiles/main.dir/src/b2e_model.cpp.o
main: CMakeFiles/main.dir/src/b2e_pipeline.cpp.o
main: CMakeFiles/main.dir/src/b2e_renderer.cpp.o
main: CMakeFiles/main.dir/src/b2e_swap_chain.cpp.o
main: CMakeFiles/main.dir/src/b2e_window.cpp.o
main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/build.make
main: /opt/homebrew/lib/libglfw.3.4.dylib
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build /Users/aatostapper/Documents/Dev/Vulkan/Base2-Engine/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

