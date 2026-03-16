# Member methods for Vector

## Rule of 3

When we manage some resource in a class, like a pointer and the data it points to, we must manage that resource. Afterall, that's the entire contract of dynamic memory. We manually manage it.

As such, we must define a destructor to properly handle the deallocation or freeing of this resource. When we're done with it, we need to give the resource back to our runtime. If we don't, this is a memory leak. A memory leak is just occupied memory that can't be used because no one knows where it is. It's like a crypto wallet. If you lose the key, nobody's letting you into the wallet. The wallet has stuff, but nobody can access it. If you tell the runtime to give you a resource, and then your pointer (the key in this example) is lost (goes out of scope, reassigned to something else, etc), then that data is forgotten to everyone. The runtime gave you the resource, and you said you'd manage it.

The rule of 3 states if you need one of 1) Destructor 2) Copy Constructor 3) Copy Assignment, then you most certainly need to implement all 3. (Rule of 5 is an extension of this you'll cover in CS-3370)

So, since we must tell our program how to handle the cleanup of our data pointer, we also need to tell it what operations to perform for copy construction, and copy assignment. In other words, we must tell it how to copy the manually managed data from another object.


```cpp
...
~Vector()
{
    ... //What do we add here to free the resource?
}
```
This allows you to use delete as in:

SomePointer* s = new SomePointer();
delete s;

Which calls your destructor, which you must do to free the resource pointed to by a pointer

---

```cpp
/*
*   This IS a constructor. We can use the list initializer syntax to copy data.
*   Remember that list initializer syntax allows us to copy data at resource acquisition
*   RAII means Resource Acquisition Is Initialization. 
*   This means when we want to make an object, it's data is initialized as soon as it's live
*   The constructor body happens after new. 
*   Python has __new__ and __init__. You're used to init.
*   In C++, if we use the body for construction, technically, we're doing 2 init steps
*/
Vector(const Vector& other) : capacity(other.capacity), _size(other._size), data(new int[other.capacity])
{
    ... //Do a loop here to copy data from other.data to this->data
}
```
Allows you to do something like this

SomeObject o;
SomeObject s(o);

---

```cpp
/* 
*   Remember that this is NOT a constructor. That's why we do everything in the body.
*   Since it's not a constructor, there's no intializer list since there's nothing to initialize.
*   This is overloading the assignment operator, so that we can copy from one live object
*   to another live object. e.g. v1 = v2
*/  
Vector& operator=(const Vector& other)
{
    if(this == &other) return *this; //protects from self-overwriting

    delete[] data;
    capacity = other.capacity;
    _size = other._size;
    data = new int[capacity]; //we want our own memory for this object, separate from the memory of other.data
    for(size_t i = 0; i < _size; i++)
    {
        data[i] = other.data[i];
    }
    return *this;
}
```
Which allows you to do this:

SomeObject s;
SomeObject o;
s = o;

## Summary

When we have some resource, like a pointer, we have to manage it. If we just use a default constructor, default copy constructor, etc, then we will only be performing a shallow copy. In other words, our two vectors would be holding the same resource. So then if we updated one, we'd be updating the other. Most of the time, we want a new vector with its own data.

Since we manage a pointer in our Vector, that means we need the rule of 3 and write a proper destructor, copy constructor, and copy assignment operator overload so that we can properly handle that resource for new objects, and deleting objects.
