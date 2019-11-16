If you want to build this project yourself:

##### Keep in mind I haven't put much effort into making this project work on other peoples computers. Still, I think the instructions below have a decent chance of working.

You will need a few things to build the project. I tried to make the process as simple as possible, for my own sake.
I will explain how to get all of these things below, but as an overview: 

1. Firstly, you need **CMake** which creates a Makefile.
2. You need the `make` tool to use that Makefile to build the project.
3. Lastly, you will need to have tools to compile C and C++ code, as well. I use `gcc` and `g++` on both windows and linux.

For windows, CMake has an installer you can just search for and run. For the other tools, you can find and download **mingw-w64**. mingw-w64 contains `gcc`, `g++`, and `make` (under the name of `mingw32-make`). You can install it anywhere and add the bin directory to your PATH. This should allow you to run `gcc`, `g++`, and `mingw32-make` (something we will need later) from cmd.

For linux, you should be able to just `apt install gcc g++ make cmake`, replacing `apt` with your systems package manager if needed. (you can build these things from source too, but if you are doing that I think you already know about all this stuff!)  

So, to build:
* Firstly, copy *CMakeLists_Windows.txt* or *CMakeLists_Linux.txt*, and rename it to *CMakeLists.txt* (use the file appropriate for your OS)
* CMake needs to know where to find your C and C++ compiler. I found it easiest to set the `CC` environment variable to `gcc`, and the `CXX` variable to `g++`. (these are variables that CMake looks for).
  * I believe you can also modify *CMakeLists.txt*, adding the lines `set(CMAKE_CC_COMPILER yourpathhere)` and `set(CMAKE_CXX_COMPILER yourpathhere)`, replacing `yourpathhere` with the paths to a C compiler and C++ compiler. (something like *"C:/mingw64/bin/gcc.exe"*).
* Run the cmake command, followed by the path of this project's root. This usually means opening cmd/terminal in the Shiny-Barnacle folder, and running `cmake .` which runs cmake in the current directory.  
* CMake should hopefully create a file called *Makefile* (and a bunch of other files). After *Makefile* is created, you will need to run `make` from the same folder you ran cmake in. (this is where the C and C++ compilers are used.)

If all of this actually worked correctly, it should produce an executable file called Build!

It might be worth nothing that I left the .vscode_SAMPLE folder, which you could rename to .vscode if you use visual studio code. I doubt the files will really be useful in any other build environment - but you could see tasks.json if you want to see the commands I use to quickly compile the project on windows.