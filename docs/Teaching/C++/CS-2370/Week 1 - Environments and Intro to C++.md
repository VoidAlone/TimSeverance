### Setting Up an Environment

For Windows:

Windows is a bit of a pain to set up a proper C++ environment. You have a few options 

1) WSL
2) An IDE with an environment (Visual Studio, JetBrains, etc.)
3) MSYS2 

A really straightforward option is to just use WSL. You can install any linux distro of your choosing and then with that distro's package manager, you can install all the C++ tooling you like. 

The next straightforward option is to just use Visual Studio or similar IDEs that provide all the necessary dependencies, tooling, environment variables etc to develop, compile, and run a C++ project.

The third option is to use MSYS2 or similar products. MSYS2 is a compatibility layer that provides a unix-like environment for windows. It provides bash shell and does the necessary translation between unix-like and windows commands and file paths. It comes with the pacman package manager, and is fairly nice for C++ dev on windows. It's a solid alternative to WSL. 

With the WSL or MSYS2 option, you will be able to set up whichever text editor you prefer. So for those of you who prefer VSCode or whatever, this will likely be your best option.

Here is a link for setting up VSCode for C++ development using the GCC (GNU Compiler Collection) with the mingw toolchain via MSYS2 (Compatibility Layer)

[Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)

If you have the opportunity to use Linux, your development experience will be significantly more straightforward and unambiguous. Microsoft and XCode tend to obfuscate a lot of the tooling in a way that just ends up confusing students most of the time.

### Compilers

There are 3 mainline options you can pick for compilers.

1) GCC
2) LLVM
3) MSVC

**GCC (GNU Compiler Collection)**
This is a wonderful compiler collection brought to you GNU (GNU's Not Unix). It comes with compilers for Fortran, Ada, Objective-C, C, C++, and D. Do not confuse GCC as the collection with gcc (the C compiler) and g++ (the C++ compiler). gcc and g++ are both part of GCC. These compilers are fairly standard, and have really great performance.

**LLVM**
It used to stand for Low Level Virtual Machine, but no longer means that, and is now a general purpose framework that modularizes frontend and backend components for compilers. Languages implemented in LLVM provide a front end that translates to an IR (intermediate representation) that is then handled in the backend. Clang is the C++ compiler for the LLVM project.

**MSVC**
This is microsoft's compiler. I don't know much about this one, other than it obviously has its own libraries and quirks. It has different preprocessor macros, and requires microsoft's tooling to use (Visual Studio). Ew.

### Tooling

I want to talk about the tools of your environment.

In order to have a decent development experience you need several tools. Many of you who have used JetBrains, Visual Studio, or VSCode will either have all of the tooling already built in, or will download some extension that magically makes your dev experience nice.

You will find that C++ is a complex beast when it comes to tooling, and so it helps to be aware of what components you're using.

**1) Syntax highlighting**
You will generally have a tool like treesitter that provides general syntax highlighting. This just makes it visually easier to read and colors different identifiers and keywords.

**2) Language Server**
A language server is what provides things like in-editor error messages, red squiggles, code suggestions, etc. It usually provides some capability to autocomplete based off of context as well. Microsoft's general language server solution for their products has generally been "Intellisense." Microsoft developed the LSP (Language Server Protocol) which provides a unified way for language developers and text editors to implement a language server that can talk to a text editor. There are a few language servers available for C++, but the generally best language server is Clangd from the LLVM project.

**3) Debug Adapter**
Debug Adapters are also a technology brought to us by Microsoft (Debug Adapter Protocol) and again provides a unified way for language developers and text editors to communicate in a standard way. In my case, I will be using lldb also from the llvm project. GCC provides its own debugger, GDB, but its capabilities as a debug adapter are limited (particularly with integrated terminal interaction for standard input)

**4) Task Runners**
Task runners come in many forms especially for C++. Microsoft once again has implemented a somewhat standardized way of running tasks. Running a task usually involves setting compiler flags for things like warnings, compiling, linking, assembling etc. Once a task has been run, a debugger (or you from the command line) can then execute the compiled program. 

Most of this is bundled all together in tools like Visual Studio, or in the C++ extension in VSCode. You don't really need to think a lot about how these things work if you're using those tools, which can really hurt you when they stop working or aren't working correctly. Being equipped with this knowledge will help you as you implement your projects. 

Most of the projects we will do in this class are not very complex. The difficulty will come from the novelty of the language, and from your unfamiliarity with the tooling.
### Day 1

#### Anatomy of a basic C++ program

```
#include <iostream>
#include "my_thing.h"

using namespace std;

int main(){
	cout << "Hello World" << endl;
	return 0;
}
```

```
#include <iostream>

int main(){
	std::cout << "Hello World" << std::endl;
	return 0;
}
```

```
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(){
	string x;
	cout << "Hello World" << endl;
	cin >> x;
	return 0;
}

def my_class:
	def __init__(self):
		self.x = 5

	def __str__(self):
		return self.x

...

y = my_class()
print(y)
z = str(y)

```

`#include <iostream>`
For you all, this is somewhat equivalent to `import x` in python. The include keyword is used to import header files which are essentially files that contain declarations and definitions for classes, structs, functions, and variables. In C++ 20, we now have the import keyword for modules, which works somewhat similarly, except that modules are precompiled and eliminate a lot of overhead that comes with headers. https://learn.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-170

Why would we still use headers? As it states in the microsoft docs above, macros, preprocessor directives, and non-exported names are not visible to external code. In other words, if you want to make those things accessible to others, then headers are nice for that. 

Why don't we need a semi-colon on this type of statement? Essentially the includes are preprocessor directives and run before actual compilation. In other words, a separate program from the compiler reads these lines, and has its own way of parsing these types of directives. After the preprocessor runs, then the compiler takes over, and has a separate set of rules, and requires the use of the semi-colon as a delimiter, since it doesn't care about whitespace.

`using namespace std;`
What are namespaces? It's just an extra layer of scope. Let's say we have two families of classes that are unrelated, but feature the same type of verbage. For instance, Games and Music Streaming. Both of these systems might have functionality called Play, Pause, Stop, whatever. Since these two names make sense within their own context, it's somewhat of a given that they'll have functions with names that clash. So, what we can do is specify a namespace, or essentially say that a certain collection of Classes, Functions, etc, all belong to a certain scope, and when we use that scope, we be certain that Games.Play is different from Music.Play or something like that. It's just a way to group up common names so that they don't conflict.

A more concrete example, is as a library writer, you might want to overload cout, or cin, or write functions or classes that have the same name as functions or classes that are defined in the standard library. As such, defining a namespace, allows us to differentiate between independent libraries.

`int main()`{ ... }
In C++, everything is typed, and so since main is a function, and the entry point to our C++ program, we say that its type is int, so we can return integers depending on code execution. When we return 0, this essentially just says that everything ran, and we're done.  https://en.cppreference.com/w/c/language/main_function

`cout << "Hello World" << endl;`
cout is gonna feel weird to you all. And it kind of is. Most languages have something equivalent to print(), console.writeline(), console.log(), etc. The difference here is that cout is actually an object, and the `<<` operator is just that: an operator. In python we can overload magic methods (dunder methods) like \_\_eq\_\_() or \_\_str\_\_(). In python, eq usually takes the form fo x == y, while str is in a function format like str(x). In these scenarios, and in compilers, and interpreters, sometimes operators can translate directly to an operation, while in other scenarios, it's syntactic sugar. For us, the << operator is a nice sugar that is secretly a function that acts like an operator like +, -, <, etc. Python's print function, is also a bit of sugar. It's a function that essentially just acts as a nice little wrapper for doing sys.stdout.write() or something of that nature. Likewise, in C++, cout is the standard output ostream object that we can write with. Using << is similar to using cout.write() but it comes with some more safety features, and is an operator instead of a full method that we have to write out.  https://docs.python.org/3/library/functions.html#print

#### Remembering the difference between << and >> for cout and cin

It can be pretty tricky remembering which operators to use when doing using cin and cout, especially coming from python where we have "print" and "read"

Remember that cin and cout are OBJECTS. That means that store information. When determining which direction your chevrons should go, remember where the direction is flowing. 

A cout object is going to pipe information to standard output (like your terminal). SO, that means that we want to direct that information from something like a string, to cout. In other words: 
`cout << "something"`. Despite it being output, the flow of direction is not towards the string, or "out" from cout. The string is going INTO the cout object.

Likewise, cin receives input from a terminal or some source, and STORES that input, into ANOTHER object. So it's "piping" information from itself, to a program object. Thus `cin >> my_string;`


### Day 2

Ints
[Floats](https://en.wikipedia.org/wiki/IEEE_754)
Const
Auto


###  Compiling with C++

https://bytes.usc.edu/cs104/wiki/gcc



