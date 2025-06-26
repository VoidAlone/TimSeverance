### General Behavior

Switch Cases

Integer Division

Pass by value 
Pass by reference 
Pass by const reference

What are arrays? 
How are arrays treated when passed in functions

Forward declaration

Default parameters

What are header guards for?

We talked about stack frames (activation record). What goes in them, and what isn't in them?

Initializer list syntax for constructors

Exceptions and exception handling

String formatting (setw and setfill)

Inheritance. C++ has multiple inheritance.

### Privacy

- Public: Anyone can access

- Private: Can only be accessed within the class itself

- Protected: Can be accessed by anyone that inherits from the class, but is private otherwise.

### Classes

Polymorphism. The ability of an object to behave differently depending on its type. With inheritance and interfaces, an object can act differently. 

What is encapsulation? 

IS-A vs HAS-A. This refers to inheritance/type vs composition/data members. 

#### Abstract Classes

- virtual keyword
- 
- override keyword
- 
- pure virtual: virtual return_type identifier() = 0; //whatever class has a pure virt method will be a pure virt class and can't be instantiated

- if you have a pure virtual abstract base class, you've gotta use override to implement the abstract method in your concrete subclass.

#### UML

There are a few questions that use UML. Be familiar with the arrow types, and be familiar with the bold/italic/

### Templates

See cppreference on differences between instantiation between function template and class template.

How does instantiation for templates work? 

### Iterators

Find() function. Know how it works.

Relationship between iterators and pointers

### Anonymous/Lambda functions

Be familiar with the syntax

### Predicate functions

They're just boolean functions, and are usually passed directly to other functions as a parameter, like the find() functions

### Data structures

push_back() and pop_back() methods for vector. Be familiar with their return type, param type, and what they do.

pair class and its methods

map class (c++ dictionary) and its methods

set class and its methods