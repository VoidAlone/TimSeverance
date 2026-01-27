# Containers, Functions, and References

## Vectors

So at this point, you've already handled project 5.33 (Rosters using Vectors)

It goes without saying that project is generally a poor example of how you might actually store data in C++, but the goal of the project was aimed at getting you comfortable with loops and data structures. That's it.

We haven't covered this yet, but remember that with Vectors, the <> syntax you see is for templates. This allows you to generically handle data types for any instance of the structure. So a Vector<String> is obviously a Vector of strings. This works by replacing every instance of some template parameter with the actual type you passed in for the instantiation.

Vectors are something of a dynamic array, which we'll implement later. Before then, we'll end up talking about objects, pointers, and templates. Just be aware that under the hood, it's all memory addresses. There's nothing special about a Vector compared to an array other than wrapping it with advanced functionality to make it easier to interact with. Under the hood, it's all the same.

[Generics in other languages](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/types/generics)

[Templates in C++ - Geeks](https://www.geeksforgeeks.org/cpp/templates-cpp/)

[Templates in C++ - Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170)

## Functions

Some key things to be aware of for Functions:

1) Forward Declarations
2) Parameter Passing
3) In vs Out parameters
4) How are arrays passed to a function?

### **Forward Declaration**

We've done this regularly in the form of global variables and whatnot throughout the semester. You'll see with templates coming up that we're making use of the same mechanism. The idea though is that in order to compile, we need to make assurances that a symbol we want to use exists somewhere. We can make this work by simply declarating the thing first. This can come in the form of declaring variables and functions.

By forward declaring we're just saying "hey, you can count on this to exist later on during run time. For now, during compilation, just assume that it's all good."

### **Parameter Passing**

This is going to be the biggest thing we talk about honestly

1) Pass-by-value
2) Pass-by-reference (variant: const reference)
3) Pass-by-pointer
4) Pass-by-assignment ([python](https://www.geeksforgeeks.org/python/pass-by-assignment-in-python/))

**Pass-by-Value**

```cpp
void F(int passed_value){}
```

Also known as pass-by-copy, this mechanism is the most basic form of parameter passing, and all of you have done this. 

When a function is called, we need somewhere to store information about a function. We create an activation record, and we create enough spaces in the activation record to store things like local variables. When we consume parameters, we store that information in the stack frame, and so the most straightforward mechanism for this is to simply copy down the data from whatever was passed into a parameter, and store it in that local var on the frame.

This means that whatever you pass in by value is a copy. This comes with obvious downsides in that it costs cycles to copy data, and also any changes made to the copied data, will obviously not reflect outside of the scope of the function. 

**Pass-by-reference**

```cpp
void F(int& passed_reference) {}

void F(const int& pass_const_reference){}
```

Pass-by-reference and more specifically Pass-by-const-reference are going to be your main bread and butter in C++. This is almost always how you should pass parameters unless you're dealing with simple data, or you explicitly want a mutable copy.

The mechanism works about the same as it does with pass-by-value, the main difference being rather than an address being allocated in the stack frame for a local variable, you have a reference/alias allocated there. 

PBR is very efficient, since they require no copying of data. The parameter is directly bound to whatever was passed in as that parameter.

You will frequenly hear PBR parameters as out parameters. This is because whatever change is made to the parameter in the function applies to the bound object outside the function. So, you may sometimes see a function that has a return function or not, but it also specifically mutates values outside the function. This is probably pretty icky for the functional programming people. 

The best option for most scenarios is PBCR. We'll address this more in class but it has very desirable properties.

#### What is a reference?

A reference, also referred to as an alias, is similar to some kind of const pointer. There are neat compiler tricks and things to make them work efficiently, but references work similar to pointers by being bound to an address rather than data.

References have a few rules (there's always a cost to things)

1) They must be defined at declaration.
2) They cannot be reassigned
3) They do not have their own address. They share the address of the data they're bound to

**Pass-by-pointer**

