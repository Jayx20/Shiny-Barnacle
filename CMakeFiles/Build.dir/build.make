# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Jordan\Desktop\Unnamed Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Jordan\Desktop\Unnamed Project"

# Include any dependencies generated for this target.
include CMakeFiles/Build.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Build.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Build.dir/flags.make

CMakeFiles/Build.dir/src/main.cpp.obj: CMakeFiles/Build.dir/flags.make
CMakeFiles/Build.dir/src/main.cpp.obj: CMakeFiles/Build.dir/includes_CXX.rsp
CMakeFiles/Build.dir/src/main.cpp.obj: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Build.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Build.dir\src\main.cpp.obj -c "C:\Users\Jordan\Desktop\Unnamed Project\src\main.cpp"

CMakeFiles/Build.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Build.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jordan\Desktop\Unnamed Project\src\main.cpp" > CMakeFiles\Build.dir\src\main.cpp.i

CMakeFiles/Build.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Build.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jordan\Desktop\Unnamed Project\src\main.cpp" -o CMakeFiles\Build.dir\src\main.cpp.s

CMakeFiles/Build.dir/src/VectorUtil.cpp.obj: CMakeFiles/Build.dir/flags.make
CMakeFiles/Build.dir/src/VectorUtil.cpp.obj: CMakeFiles/Build.dir/includes_CXX.rsp
CMakeFiles/Build.dir/src/VectorUtil.cpp.obj: src/VectorUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Build.dir/src/VectorUtil.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Build.dir\src\VectorUtil.cpp.obj -c "C:\Users\Jordan\Desktop\Unnamed Project\src\VectorUtil.cpp"

CMakeFiles/Build.dir/src/VectorUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Build.dir/src/VectorUtil.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jordan\Desktop\Unnamed Project\src\VectorUtil.cpp" > CMakeFiles\Build.dir\src\VectorUtil.cpp.i

CMakeFiles/Build.dir/src/VectorUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Build.dir/src/VectorUtil.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jordan\Desktop\Unnamed Project\src\VectorUtil.cpp" -o CMakeFiles\Build.dir\src\VectorUtil.cpp.s

CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.obj: CMakeFiles/Build.dir/flags.make
CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.obj: CMakeFiles/Build.dir/includes_CXX.rsp
CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.obj: src/Graphics/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Build.dir\src\Graphics\Renderer.cpp.obj -c "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\Renderer.cpp"

CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\Renderer.cpp" > CMakeFiles\Build.dir\src\Graphics\Renderer.cpp.i

CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\Renderer.cpp" -o CMakeFiles\Build.dir\src\Graphics\Renderer.cpp.s

CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.obj: CMakeFiles/Build.dir/flags.make
CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.obj: CMakeFiles/Build.dir/includes_CXX.rsp
CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.obj: src/Graphics/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Build.dir\src\Graphics\Mesh.cpp.obj -c "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\Mesh.cpp"

CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\Mesh.cpp" > CMakeFiles\Build.dir\src\Graphics\Mesh.cpp.i

CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\Mesh.cpp" -o CMakeFiles\Build.dir\src\Graphics\Mesh.cpp.s

CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.obj: CMakeFiles/Build.dir/flags.make
CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.obj: CMakeFiles/Build.dir/includes_CXX.rsp
CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.obj: src/Graphics/ShaderClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Build.dir\src\Graphics\ShaderClass.cpp.obj -c "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\ShaderClass.cpp"

CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\ShaderClass.cpp" > CMakeFiles\Build.dir\src\Graphics\ShaderClass.cpp.i

CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jordan\Desktop\Unnamed Project\src\Graphics\ShaderClass.cpp" -o CMakeFiles\Build.dir\src\Graphics\ShaderClass.cpp.s

# Object files for target Build
Build_OBJECTS = \
"CMakeFiles/Build.dir/src/main.cpp.obj" \
"CMakeFiles/Build.dir/src/VectorUtil.cpp.obj" \
"CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.obj" \
"CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.obj" \
"CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.obj"

# External object files for target Build
Build_EXTERNAL_OBJECTS =

Build.exe: CMakeFiles/Build.dir/src/main.cpp.obj
Build.exe: CMakeFiles/Build.dir/src/VectorUtil.cpp.obj
Build.exe: CMakeFiles/Build.dir/src/Graphics/Renderer.cpp.obj
Build.exe: CMakeFiles/Build.dir/src/Graphics/Mesh.cpp.obj
Build.exe: CMakeFiles/Build.dir/src/Graphics/ShaderClass.cpp.obj
Build.exe: CMakeFiles/Build.dir/build.make
Build.exe: CMakeFiles/Build.dir/linklibs.rsp
Build.exe: CMakeFiles/Build.dir/objects1.rsp
Build.exe: CMakeFiles/Build.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Build.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Build.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Build.dir/build: Build.exe

.PHONY : CMakeFiles/Build.dir/build

CMakeFiles/Build.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Build.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Build.dir/clean

CMakeFiles/Build.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Jordan\Desktop\Unnamed Project" "C:\Users\Jordan\Desktop\Unnamed Project" "C:\Users\Jordan\Desktop\Unnamed Project" "C:\Users\Jordan\Desktop\Unnamed Project" "C:\Users\Jordan\Desktop\Unnamed Project\CMakeFiles\Build.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Build.dir/depend

