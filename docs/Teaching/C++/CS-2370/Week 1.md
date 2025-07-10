### Day 1

#### Anatomy of a basic C++ program

```
#include <iostream>

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
	return 0
}
```

```
#include <iostream>

using std::cout;
using std::endl;

int main(){
	cout << "Hello World" << endl;
	return 0;
}

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


###  Compiling C++

https://code.visualstudio.com/docs/cpp/config-mingw
https://bytes.usc.edu/cs104/wiki/gcc



