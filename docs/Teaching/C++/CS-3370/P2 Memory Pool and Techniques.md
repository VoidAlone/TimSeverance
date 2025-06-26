### Introduction

The purpose of this project is to learn and understand more advanced techniques in managing memory. Memory Pooling is used for even more efficient allocation and initialization than what is provided to us with the new keyword. This project will allow us to practice the following techniques:

- operator new overloading
- operator delete overloading
- placement new
- type punning

### Class Overview

#### Pool Deep Explanation

MyObject will have an inline static member, Pool, that accepts MyObject types. This allows us to share the pool between MyObjects

Pool is an expanded version of what you did for project 1. Only this time, we're adding one more layer of memory management, and so our pool is a double pointer array. In other words, our pool will have elements that point to pointers that point to arrays. 

When we first start our main, we'll invoke allocate which will then check to see if we have space to store an element. If we don't, we create a new block in our pool, and then link all of the spaces in our block (array) by having pointers that point to the next free space available. We can remove objects in any order we like, which is why we have to keep track of which spots are free. At first, each next just points to the next space, but as we remove objects at random, that sequential ordering can and will change.

We will use an implicit/logical linked list to manage where we can store everything. Keep in mind that we're managing a Heap with our pool. So what this means, is that we're going to have spaces in memory, that are reserved by our arrays (blocks). Each space in our blocks can be a living space for our MyObjects, but until those spots our occupied, we will treat each space as a pointer to the next free space. This is why we will use Unions as a cleaner option for type punning.

Our blocks will be of type element, which is a union. We will be able to treat each space in our blocks as either a "next" (think back to "next" in your linked list project in 2420, only it's not in an object, it's just a pointer to some other free space), or as a MyObject. 

In main.cpp, we'll have an array of MyObjects. That array doesn't care about where they are on the heap, it just has pointers to objects that live on the heap.

##### Public Functions

- allocate
	- this function will call expand if necessary
	- save the address pointed to by the head for storing the new object
	- move the linked list head to the next free spot 
	- return the saved address
	- not responsible for object creation, only space allocation
- deallocate
	- store the address of what the head is pointing to, at the location of the object we're deallocating (this links things)
	- points the head itself to that object's address so that we can allocate an object at this location
- profile
	- prints address of free spots 

##### Private Functions

- expand - has 2 scenarios
	- Scenario 1: If nothing has been allocated to the pool, we simply create a new "block" or pointer array. This array can go anywhere in memory. We get the pointer to the array we've just made, and save it in our Pool double pointer array. You can think of this new array as a new row
	- Scenario 2: If we've run out of spaces in our row (we hit nullptr), we simply do the same process as before, but we must increase the double pointer array for our pool, which means creating a temp array, copying the pointer pointers over, allocating new space, then copying them over to the new double pointer array with increased size.
	- Finally, we invoke link()
- link
	- Invoked when we call expand
	- After a new block is available, we have free space, as well as a tail pointer.
	- We link our "tail" pointer to the first index of the new array, and then move it along with our next pointer until we reach the end.
	- Each index will contain a pointer to the next free slot (at first, it'll just be the address for the next free index)
	- The last one we do will be a nullptr.
	- Set our head at the beginning of the new block of the pool

#### MyObject

This class is a dummy object for our project, with an id and a name. It's also all written for you.

We're keeping its constructor and overloaded new private so that no one can instantiate MyObject themselves. We're making it so that if we want a MyObject, it HAS to go to the pool. Otherwise, we'd be able to create a new object, and it would just go put on the heap automatically. 

MyObject the following public functions

- delete
	- invokes pool.deallocate
- create
	- invokes the new keyword for MyObject. More on this below.
	- new invokes pool.allocate. This provides us with an address only. 
	- The address is given to the compiler, which invokes the constructor and stores object there
- profile
	- pool.profile
- operator <<
	- we choose how the object gets printed out to console.
	- similar to python's __ str __ 