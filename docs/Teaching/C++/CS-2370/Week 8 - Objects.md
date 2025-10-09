# Objects

## What is OOP?

Alan Kay, creator of smalltalk, conceptualized Object Orientation. Over the span
of his career, he gave several talks and memos highlighting his regret of ever
calling it "object orientation." Indeed, the object model is important to
Smalltalk and OOP as a paradigm, but the message is lost as it focuses only on
objects. The real key to OOP is instead the mechanism in which objects interact, 
ie passing messages. Afterall, isolated objects aren't of much use to anyone
in a dynamic and stateful world. 

Object orientation has to do with objects that embody abstract concepts. The
model of course maps to real life with real actors like people with careers who
have certain professional knowledge. The key is, the information contained
within individuals is private and inaccessible. The idea is that if we want to
be able to complete a task and we are unable to do it ourselves, we communicate
with someone who can, and we request that they complete a task for us. This is
the real crux of object orientation: The ability to send a message to an object
who knows how to complete a job. If the same message is given to many objects,
they should subsequently know how to reply either by saying they can't, or
by giving their own unique response to the message. 

Since OOP relies on encapsulation, which is the organization of related
information, and importantly, the hiding of that information, we MUST rely on
messages to get these jobs done. Encapsulation is the core of OOP, and so
Messages work in tandem with encapuslation to make objects work.

## Dispatching

Very briefly, dispatching is the mechanism in which a method is determined to be
called. It's largely the mechanism that allows us to have runtime polymorphism.

Overriding and overloading are typically resolved at compile time. The types of
parameters can be divined, generally, by the compiler, and then optimizations
and function call resolution can happen before the program even runs. However,
in the case of objects with many types, functions with parameters revolving
around inherited types must be resolved at runtime. The way C++ handles this
is with single dispatching. In otherwords, C++ only cares about the name of
the function at runtime, and cannot resolve ambiguity at runtime. For
instance...

```cpp
void f(A& obj);
void f(B& obj);
```

where B inherits from A. This cannot be resolved by C++. While c++ supports
overloading for static types like overloads with ints and floats as parameters,
 determining the correct function call with simply default to the base type (A 
in this instance). Most languages do this by default.

The dispatcher is the runtime mechanism that determines which function to call.
This is vital for polymorphism. Since multiple dispatch is not always supported,
there are ways to get around this. In any language, the visitor pattern
generally works. Otherwise, in python, you can use the multiple dispatch
libraries that exist and use decorators to register your overloaded
functions. In C++ you can use dynamic casting to resolve the type
yourself, and then call from there.

Overloading is not dispatching, though they are related.

[Dispatching in languages](https://en.wikipedia.org/wiki/Multiple_dispatch)

[Overloading in c++](https://www.geeksforgeeks.org/cpp/function-overloading-c/)

[Multiple Dispatch Wiki](https://en.wikipedia.org/wiki/Multiple_dispatch)

[Function overload vs override](https://www.geeksforgeeks.org/cpp/function-overloading-vs-function-overriding-in-cpp/)

## Templates and Generic Programming

## Resources

https://www.codementor.io/@michaelsafyan/object-oriented-programming-in-c-du1081gw2



