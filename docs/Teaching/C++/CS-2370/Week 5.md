### Undefined Behavior

When we talked about indexing outside of an array, we wondered what would happen. At some point, we were able to iterate a fair degree outside of the bounds of our array, and then after enough passes, we hit a segmentation fault. A segmentation fault is when we try to access a "segment" that is protected by our system. This can happen when trying to access outside of the bounds of our program, or potentially when trying to access a dangling pointer or something. In other words, we asked for resources from our system, those resources were provided, and we're usually accidentally going out of bounds.

C++ doesn't make any particular rules about accessing outside of the bounds of an array as it is considered to be undefined behavior. This is a level of the specification where no decisions were made on how to handle a specific feature of the language. In the same way that dividing by zero is undefined in mathematics, there is functionality that results in undefined behavior in C++. Treading into undefined territory is generally legal according to the compiler, but going into the wilderness can have disastrous consequences.
### Linking and compiling

If we want to just manually compile, we can simply use the compile flag -c. This creates object files. 

From here, we can then link those object files by simply passing them to g++ with an optional output flag. This is virtually the same process that we did before, just now instead of passing .cpp files to the g++ compiler, we're now passing .o files. 

So if we make changes to one file, we simply invoke 

```
g++ -c some_file.cpp
```
which produces a some_file.o file.

Then we can do

```
g++ main.o some_file.o -o main.exe
```

Obviously though, having a lot of source files would make this process more complicated. This is where we use environments like vscode and set up task and launch configurations for building a project, or in Visual Studio where a lot of that is handled automatically. The other option is to create a Make file which has its own distinct syntax.

[Simple C Makefile tut](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)

### Object orientation vs procedural

[Object Orientation is NOT about Objects...](https://www.youtube.com/watch?v=lmAarC0Zhq4&list=PLZHx5heVfgEvuveKG1T7BBSuDOTHl1eLl&index=3)
##### Can we make C emulate C++ objects (classes and structs?)

https://stackoverflow.com/questions/44102324/emulating-classes-in-c-using-structs

### Structs and Classes

Structs and Classes are the exact same thing in C++ with the main difference being in default privacy/visibility of member data. Struct member data is public by default, while class member data is private by default. Keep in mind that C++ was originally just a transpiler to C code. Naturally, a lot of the features of C carried over, which can at times feel confusing to new C++ programmers. (Go back to the introduction where I talked about what makes C++ hard). When in doubt, use C++ idioms and features. Opt for C features when you have specific needs.

8.2 Talks about returning a struct as opposed to using two reference parameters, sometimes called output parameters in c++. It can come across as confusing to see two parameters passed by reference when their only purpose to is to be modified, since functions insinuate consumption and especially if the function doesn't return anything, one might wonder what we do with the references. It's not wrong, but some could argue it's confusing.

[Input and Output Parameters in C++](https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/)

8.3 and 8.4 Fall more in line with the C style of programming when back in the day, structs were not objects, and so they had no functionality (methods). So instead, you would create groups of functions that would be able to operate on structs. We could get into a whole thing about the evolution of the "dreaded" inheritance features in object orientation. The main idea here is that object orientation is about defining new types that are able to handle messages via methods. Adding new types is trivial in object orientation, and leveraging inheritance allows for code reuse. With greater abstractions, comes greater power, but as a side effect, more responsibility and potentially more confusion. This is where the fresh undergrads tend to swear off OO for the "simplicity" of functional programming and all of the safety that it promises.

