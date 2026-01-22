### Rationale

This semester (Spring 2024) I'm teaching a C++ course at UVU. Since my last C++ course (Spring 2020), I've mostly used VSCode as my daily driver for everything code related. I used Visual Studio pretty extensively at the beginning of my undergrad, and I found it fairly useful for my capstone which used C#, but I mostly chalk that up to not knowing what I was doing.

Anyway, VSCode for C++ development is a bit of a pain since, by default, you have to use MSVC to compile. This requires a whole annoying process of starting up the [Developer Command Prompt](https://code.visualstudio.com/docs/cpp/config-msvc) for VS and starting VSCode from there. I could probably create some script or something but the whole process is kind of a pain in the ass. 

Microsoft has a nice article about using other compilers, though. So I decided to go with the MSYS2 route, which provides a lot of really great tools in a UNIX like environment. It allows you to use GCC which is great for a whole lot of reasons.

### Getting Set Up

[This article](https://code.visualstudio.com/docs/cpp/config-mingw) provides some insight on setting up MSYS2 and getting VSCode configured to run C++ projects using GCC.

[This link](https://www.msys2.org/docs/terminals/) from MSYS2 provides insight on getting an MSYS2 environment set up in the new windows 11 terminal.

[This stack overflow Q/A](https://stackoverflow.com/questions/45836650/how-do-i-integrate-msys2-shell-into-visual-studio-code-on-window) provides insight on setting up Bash as your main terminal in VSCode. This is very useful since the whole point of MSYS2 is to provide a UNIXy environment with tools that you might encounter in Linux. It has pacman package manager which is cool for keeping a clean development environment. 

### GCC

One of the really nice benefits of using MSYS2 is that it's kind of a one-stop shop for a [lot of languages](https://gcc.gnu.org/onlinedocs/gcc-9.5.0/gcc/G_002b_002b-and-GCC.html#:~:text=GCC%20stands%20for%20“GNU%20Compiler,multiple%20meanings%20in%20common%20use.). GCC supports C, C++, Objective-C, Objective-C++, Ada, Fortran, D, Go, and BRIG (HSAIL).

D may be supported. Check the following link more thoroughly
https://dlang.org/install.html#get_msys

From what I've read, the Go team maintains both versions of Go. The standard go compiler compiles faster, but the GCC go compiler can leverage more powerful optimizations for faster runtime performance. GCC also runs on more architectures.

GCC doesn't necessarily leverage every tool developed for these languages, but does generally provide a solid environment for building and debugging projects in any of these languages.

### Python

It seems that MSYS2 is usually one update cycle behind python. MSYS2 maintains their own fork of python that's compliant with linux pathing. Python for windows targets windows directories specifically, so there's apparently some conflicts there, which is why the maintain their own fork of CPython.