## Principles

### Encapsulate What Varies

The parts of your code that are likely to change can be pulled aside into their own classes/modules. This allows us to avoid messing with other code that doesn't need to change. Additionally, many times, code that changes can be better identified as another class or type of thing, which lends itself well to encapsulation.

### Favor Composition over Inheritance

Classes consist of data and functions to operate on them. Generally, it's a bad idea to have a single class that's responsible for defining all of the behavior it needs. A car consists of an engine, which can be defined as an object unto itself with its own specification. The car can then use the engine, but it doesn't really need to know how it operates. 

This principle doesn't mean to never use inheritance. Inheritance is still wildly useful for defining families, but it can paint us into a corner, especially in languages with single inheritance, or in instances where two supertypes share similar properties that can conflict.

### Program to an interface, not an implementation

Program to a supertype. We can leverage polymorphism, one of the basic key features of object orientation. If we design all of our classes in a way where they share common functionality, they can all be treated as that supertype, which means we can interact with our objects abstractly. 

### Strive for loose coupling 

Loosely coupled objects require very little knowledge of eachother which means that when you change one, it generally doesn't affect the other. This is the main point of this principle. When we make changes to our code, we want to avoid breaking our whole codebase. Sometimes it's unavoidable, but generally, if we keep most of the other design principles in mind, they can help us design loosely coupled classes. 

### Classes should be open for extension, closed for modification

Focus on the areas that change. By following general OOP guidelines, you'll be able to properly identify areas of your code that will generally remain the same. By removing the parts that change, and encapsulating them, you can generally obey this rule. There's overhead that comes with this in the form of more abstraction, and more classes usually, but it allows for better flexibility and neater maintenance. 

### Dependency Inversion Principle 

SOLI(D)

Depend upon abstractions, not concrete classes

At first, this principle sounds a lot like “Program to an interface, not an implementation,” right? It is similar; however, the Dependency Inversion Principle makes an even stronger statement about abstraction. It suggests that our high-level components should not depend on our low-level components; rather, they should _both_ depend on abstractions.

### Don't Repeat Yourself

This one is a pretty small principle, but the general idea is that we don't want to write redundant code. It's a waste of time, and if that code needs to change, we have to be precise about changing it everywhere it occurs, otherwise things can break. Therefore, we generally encapsulate this kind of code. If similar code is needed everywhere, it makes sense to have that code come from a single source, and if it's likely to change, then encapsulating it helps us to obey Encapsulate What Varies.

## Patterns

### Strategy

### Observer

### Decorator

I was wrong, decorator is in the exam, but the question was really vague until I thought about it. That's been corrected.

Just remember that your decorator takes the form of

Interface/Common Type. (Output)
```python
class Output(ABC):
	def write(self, s):
		...
```

Subclass that does something. (StreamOutput)
```python
class StreamOutput(Output)
...
	def write(self, s):
		self.sync.write(s)
```

Decorator that implements the interface, and has a member for wrapping other objects of that interface type. (BracketDecorator)

```python
class BracketDecorator(Output):
	def __init__(self, o : Output):
		self.wrappee = o
		
	def write(self, s):
		self.wrappee.write("[" + s + "]\n")
```


```python
def main():
	s = StreamOutput(sys.stdout)
	s = BracketDecorator(s)
```
### Factories

**How do we make factories?**

Remember that there are 3 factories. Simple, Method, Abstract. 

Simple factory is more of an idiom, and just refers to the encapsulation of runtime decision making about class creation into a separate class. Generally, you'll have one single family of related objects.

Factory method is more about providing an abstract method that can be defined in subclasses to create necessary objects, so that the class itself can determine what kind of objects it needs created at runtime.

Abstract factory is about having many families of related objects, and encapsulating the creation of related objects into a family of factories. Decision making can be done in main or wherever to determine the types of factories you might need, but the idea is encapsulating many families of objects, and then creating a family of factories that are able to create related objects. Think of the 3x3 matrix representation of Furniture organized by Art Style.

### Singleton

**How do we make a singleton?**

Private constructor, private static class instance, public/global GetInstance method.

GetInstance acts like our constructor and is responsible for either returning the static instance if it exists, or creating a new object, assigning it to the static instance, and then returning the instance.

**Benefits / Stuff we get for free**

Lazy instantiation. We're able to defer object creation until later. This can save resources like time and space. It also saves us in instances where we sometimes create an object but don't actually need it. 

**Problems**

Multithreading:

Why is multithreading a problem with this pattern?

Three ways to fix:

1) Plain ole synchronization/locking
	Just throw a normal lock around the check for an instance. Can cause bad performance, but if it's not a high traffic area, don't sweat it. Focus on optimization later.

2) Eager Instantiation
	We define the static instance to have an instance at compile time. This has its pros because the object is ready to go, no resource management at all, but it takes away from the benefit of this pattern, which is lazy instantiation.

3) Double-check locking
	This allows you to potentially avoid locking the resource altogether. Synchonization has overhead, so doublechecking can help quite a bit. You may end up only hitting the lock once, and any other time is a plain O(1) conditional.

## OO Basics

Abstraction

Encapsulation

Polymorphism

**Inheritance**

There will be a question about Inheritance and overriding, and the problems that can occur with expected output. I've provided some files to play with in the Canvas Announcement.

[Object Slicing in C++](https://www.geeksforgeeks.org/object-slicing-in-c/)

[Why Slicing doesn't Happen in other language](https://www.geeksforgeeks.org/what-is-object-slicing-and-why-it-does-not-happen-in-c-sharp/)

[Method Hiding](https://www.geeksforgeeks.org/method-hiding-in-c-sharp/)

