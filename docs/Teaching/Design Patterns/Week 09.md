Topics:

Midterm, Adapter, Façade, NullObject.

### Midterm

There's a separate study guide for the midterm over at [[Midterm Study Guide]]

### Adapter

Adapter is a really straight forward pattern. It leverages composition, so structurally, it'll feel the same as strategy pattern, but the intent is different.

Let's say we have a set of classes with a common interface. The interface has a method "do_something()." A bunch of classes implement that interface just fine, but then we have a class or something from another library, that virtually does the same kind of stuff, but slightly differently. Maybe it's method is "do_something_cooler()." These objects are incompatible, and in the instance we want to treat this ExternalClass the same way as our InternalClass, it doesn't work. So we can fix this by making an adapter. 

```
ExternalClassAdapter(InternalClass):
	def __init__(self, external):
		self.adapted_object = external

	def do_something():
		self.adapted_object.do_something_cooler()
```

It can simply be as simple as invoking the other method's call, or doing some modifications to make the return value of that call fit the return expected.

### Façade 

This pattern is sort of the basis of an API. Generally with an Application Programming Interface, the idea is to provide a a common interface. Interface in this context means a simplified, standardized "control panel" or interface that a developer can interact with. It's an interface for the human rather than the language. An API is usually a much more simplified entry point to an underlying library that allows developers to interact with library code without having to know the underlying implementation.

Façade aims to do this by providing a single entry point for a lot of potentially complex engine code. Examples that we might see relate to doing some kind of video conversion or something. There are a lot of processes that happen under the hood, that an end user doesn't really need to or want to know about. So rather than leaving the responsibility up to the user, we create a Facade. It lets us effectively just make a single call, and that call is responsible for kickstarting a lot of processes. So ConvertVideo(video, format) kicks off a chain reaction of all the necessary conversions from codecs to audio. But the end user just had to go ask the cashier what they wanted, and that's all they need to worry about.

### NullObject

NullObject is beyond cool, but potentially dangerous. It helps us to resolve situations with potentially dangerous null references.

Consider a tree structure that we're traversing recursively. With a simple linked list like you did in 2420, or even a homogeneous tree structure like in a BST, we have one single type of node object, and it's fairly straight forward to see when we're at the end of a branch. We check for null, and if it's null we do nothing or return whatever. If it's not null, we do some work.

Now imagine you have a huge tree consisting of all kinds of object types, as one might find in an AST for a compiler. Or perhaps you even have a file explorer like we'll see with future project/homework. It may be difficult and dangerous to do nullchecks or to assume work will be done. Nullchecks are a pain to write and account for, especially as we add new object types. So instead of doing nullchecks every time, we can simply create a NullObject. It implements the same base as all of the other objects in the tree, but it's basically a dummy. It safely does nothing, and even allows us to return when it's encountered.

NullObject isn't necessarily a onestop shop for removing nullchecks. We may still need to do certain checks or behaviors if something is null. And sometimes, if something is null, a part of our program has gone terribly wrong. However, in the context of trees especially where a branch just abruptly ends, we can expect that kind of behavior, and gracefully handle it with nullobjects that can do work. Additionally, because we've encapsulated nullness in an object, we can do better encapsulated logical behavior around our null values, rather than handling that across every class that might or might not be null.

### Principle

Principle of least knowledge. Talk only to your immediate friends.

Also known as the law of Demeter.

If we follow the original concepts of OOP, especially in regards to encapsulation, this rule is almost a given.

Each unit should have only limited knowledge about other units: only units "closely" related to the current unit.

Each unit should only talk to its friends; don't talk to strangers

Only talk to your immediate friends.

This makes sense if we think about encapsulation. Remember the original definition of encapsulation. Encapsulation is information hiding, according to SmallTalk. We normally think of it as just bundling related data, but it's specifically bundling data and hiding it. 