### Creational Patterns

Provides mechanisms for the flexbile creation of objects 

### Factory Patterns

The Factory Pattern isn't actually just one pattern. There are a variety of factories that have different implementation features, but they are all responsible for making new objects in a flexible manner.

So far, most of our patterns have their own unique benefits but one of the main reasons we keep implementing patterns is to overcome obstacles that arise when we change certain aspects of our code. We've use interfaces, composition, and polymorphism to help us write code that is adaptive to change. This goes back to the principles of chapter 1. However, change is ever-present. This chapter focuses on hard coding new objects, and where change might impact us, and more importantly, how we end up repeating ourselves in our object creation, which violates DRY.

#### Simple Factory

Creates a class with a create(string s) method that receives a string for input, and using conditionals, creates and returns an object of a specified type.

**From the book:** 
The Simple Factory isn’t actually a Design Pattern; it’s more of a programming idiom. But it is commonly used, so we’ll give it a Head First Pattern Honorable Mention. Some developers do mistake this idiom for the Factory Pattern, but the next time that happens you can subtly show you know your stuff; just don’t strut as you educate them on the distinction.

### Factory Method

Rather than creating a class dedicated to creation, subclasses instead implement an abstract method that handles the creation of their own objects. We're not really worrying about code reuse, and we're not as concerned about user input or anything like that for this one. This pattern is more concerned about creating objects that make sense for the creating object. 

### Abstract Factory

It feels a bit circular, but this one takes properties of the other two patterns to create objects. It can get kind of big, that's what it's used for. It's meant for when you have a lot of objects that need to be created.

It expands upon the simple factory in the sense that we're going back to having a class that's responsible for building objects. But rather than having a single class with a lot of internal logic, we declare a few base classes that encapsulate a family of related objects.

So if we're building a car, we might have one factory build engines, and it's responsible for 4 cylinder, 6 cylinder, and 8 cylinder engines. Another factory might make seats, and it builds leather and cloth seats. 

The factories don't have to always make the same "brands" either. You could potentially have a factory that builds a multitude of products that are intended for different consumers. 

### Singleton

#### What the singleton is
Singleton pattern allows us to create only one instance of an object. The common approach is the add conditional logic to a constructor or initializer, or to create a private constructor that is invoked through a helper method.

For languages like C++, Java, C#, your go-to strategy will be to

- make a private static member variable (pointers work best in C++) to an instance of the class

- make a private constructor

- make a public GetInstance() method that's responsible for checking if the reference or pointer is null, and if so, invoke the private constructor and set the static member.

Python is a bit different. It doesn't have standard privacy and its init processes are a bit different. In Python, we have 3 methods at our disposal during the creation of an object. We have \_\_init\_\_, \_\_new\_\_, and \_\_call\_\_ that we can use. When we invoke a python constructor like

x = some_class(), call, then new, then init are invoked. Since none of these are private, the standard is to

- make a class variable for your instances (just don't use self.)

- and then check if a class instance exists during call or new.

Python references

https://www.geeksforgeeks.org/singleton-method-python-design-patterns/

Classic Python Singleton

```python

class Singleton:

	_instance = None

	def __new__(cls, *args, **kwargs):
		if cls._instance is None:
			cls._instance = super().__new__(cls)
			return cls._instance

# Usage

a = Singleton()
b = Singleton()

assert a is b # True

```

  

Metaclass Singleton

```python

class SingletonMeta(type):

	_instances = {}
	
	def __call__(cls, *args, **kwargs):
		if cls not in cls._instances:
			cls._instances[cls] = super().__call__(*args, **kwargs)
		return cls._instances[cls]

class Singleton(metaclass=SingletonMeta):
	pass

# Usage

a = Singleton()
b = Singleton()

assert a is b # True

```

#### Pros and Cons
Why use the singleton as opposed to static classes?

Typically static classes don't support any kind of inheritance. This makes a static class rigid in some aspects, but what we really want is flexibility.

Singletons are live objects that can hold state and are dynamic. 

### Summary 
The big trick with these factory patterns is really understanding how interfaces work, their role in defining types of objects, and what they mean to us in terms of polymorphism.

More specifically, it comes down to how much typing you want to implement. Are you gonna have one factory that makes a single family of objects, are you gonna have multiple types of objects that need their own specific versions of objects, or do you want to have factories that specialize in multiple different types of variants of one kind of product (one might do 3 kinds of engines, another factory might do 3 kinds of chairs, etc)

(simple, method, abstract respectively)