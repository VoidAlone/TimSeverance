### P1: Strategy Queue

The queue class for project 1 wants us to write a generic class that separates the storage from its interface. 

The interface consists of the following methods: add, get, remove, size, clear. This interface partly defines the queue ADT.

Disallow copy and assignment of queue objects. I.e, if we were using C++, we'd use the delete keyword on our copy constructor and assignment operator.

ChangeImpl is our method for swapping out objects for underlying storage. This is the same kind of method that we see in the strategy pattern in the reading that takes a concrete data type, and then assigns the concrete data type to a field of the queue class.

For our implementation, we're going to create our own hierarchy of custom storage types. You don't have to go all out with these like you might in 2420, but these storage types represent the "family of algorithms" that the strategy pattern looks to encapsulate. 

Remember that in the strategy pattern, we have a class that is "composed" of an instance of an encapsulated algorithm. 

To clarify, yes, we could simply swap out the underlying storage with built in types, but this would really only leverage composition, without fully practicing the concept of the strategy pattern. This is why we're spinning our own data structures. 

The premise is simple though, we'll have a pointer to whatever our data type is, and the type of that pointer will be the generic QImpl type. Our list and stack data types will implement the QImpl interface. 

To make things easy, remember that we're just creating a mapping from our high level class (ie interface) to the underlying implementation. So, Queue has a method add, QImpl will also have an add method. Queue will call the add method of its QImpl pointer, which will in turn actually add the item to the data structure.

![[Drawing 2025-01-21 03.08.10.excalidraw 1.png]]

### Strategy Pattern Applied
Remember that we're encapsulating what varies, favoring composition over inheritance, avoiding repeating ourselves, and programming to an interface, not an implementation. These properties together yield a lot of different patterns, but in certain contexts, those principles take different forms.

#### It can be used in complex systems

[Quake Defrag Hangtime](https://www.youtube.com/watch?v=9lOlPq_Ys3U)

[Counter Strike Surf](https://www.youtube.com/watch?v=3E9TOZrSYIA)

[Titanfall Air Strafe](https://www.youtube.com/watch?v=iS6QKAdny8U)