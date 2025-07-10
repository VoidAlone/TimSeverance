[Single Inheritance](https://learn.microsoft.com/en-us/cpp/cpp/single-inheritance?view=msvc-170)

[Multiple Inheritance](https://learn.microsoft.com/en-us/cpp/cpp/multiple-base-classes?view=msvc-170)

[Shadowing and Hiding](https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/)

### Overload vs Override

This is a tough one to remember for newer programmers because they sound so similar

They both have to do with polymorphism, but the scope of their effects are different.

Overriding has to do with when you have a baseclass/subclass scenario, and you want to use the same function in your subclass as your baseclass i.e. same return type, function name, and parameters. You have a function in your baseclass, and you want to override it, and use the function from your subclass instead. It looks like the exact same function, but they differ between the classes you're implementing.

Overloading, has to do with functions that have the same function name, but different functionality within the same class, ie they have different parameters and return types, but the NAME of the function remains the same within the same class for all the functions, so you have a function that has an excessive amount of functions with the same name, ie, it's overloaded.

### Virtual and Override

We use the virtual keyword when we want runtime polymorphism of a function. In other words, the function to be called is determined during runtime, rather than compile time.

Use override for clarity, but it's not explicitly required afaik.

Virtual functions be made pure virtual by doing your declaration, and assigning it to 0; 


|  | |  | |
| --- | --- | --- | --- |
| Base Class | virtual | declaration | ( = 0) |
| Sub Class | ... | declaration | override |


### Abstract

C++ is weird, we don't have an abstract keyword. If a class has any pure virtual functions, it becomes an abstract class and can't be instantiated. (Relic of the past, more modern languages have better syntax around this).

### Interfaces

https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/types/interfaces

https://en.cppreference.com/w/cpp/iterator/iterator

https://wiki.python.org/moin/Iterator

### Typing

### Composition over Inheritance (Is-a vs Has-a)


