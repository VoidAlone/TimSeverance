## Hash Stuff

### Keywords:
#### Hash Table
	- DS that stores unordered items into a location in an array
#### Key
	- First item in key pair value, used to map to an index
#### Bucket
	- Each element in the array is a bucket
#### Collision
	- Numbers can have same hash values, and end up being mapped to the same location. Can be resolved with chaining or open addressing
#### Chaining
	- Items that map to the same bucket can be stored by using a structure in that bucket
#### Open Addressing
	- Linear Probe 
	- Quadratic Probe
	- Double Hash
#### Resizing
	- Load Factor = items / buckets
#### Clustering
#### Hash Functions (computes the correct location)
	- Modulo Hash
		- key % size_of_array
	- Mid-square hash
	- Mid-square with binary
	- Multiplicative string hash function
#### Direct Hashing
	- Always provides O(1) time complexity, but creates O(n+1) or O(n) space complexity because each key gets mapped to its direct index value. No collisions, but takes a TON of space

### Applications
Cryptography
Data integrity (integrity can't be garanteed, but but corruption can be garanteed)

## Equality, Hashability, Identity

### Is vs ==
is keyword checks if two variables point to the same object in memory
\=\= operator checks for equality

These two are not the same but in some instances give the same results. Literals like numbers and characters for instance are usually only allocated once in memory. Therefore, if we say 5 is 5, this is true because the pointer for 5 is at the same spot as the pointer for 5, because there is only one object for 5. When we say 5 == 5 this is true because the values are equal to eachother.

By default, equality comparisons for objects refers to their identity which is a unique number (probably associated with memory idk). So that's why if we have two new objects even with the same attributes, they are not equal, because they are not the same object.

However, by overriding the \_\_eq\_\_() dunder method, we can check for equality of members.

Because is checks if pointers look at the same object in memory, then it should go without saying that if we do something like

a = generic_object()
b = generic_object() 

a is b yields false, and a == b yields false. Meanwhile

a = generic_object()
c = a

when we use is and equality

a is c
a == c

we'll get true either way, because the identifier will be the same, as well as the pointer, as well as the attributes because c and a are the same object. So it will always be equal.

However, if we override eq for a class, to check for something like a name member, then equality comparisons might yield different results than is comparisons.

for instance

a = generic_object("1")
c = generic_object("1")

where "1" is stored to a member self.num and

\_\_eq\_\_(self, other):
	return self.num == other.num

then

a == c yields true while
a is c yields false

because a is c translates to 

id(a) == id(c) -> False


### Hashability

Hashability and mutability are typically coupled together. The idea with hashability, is that we want an object to yield the same hash during the entirety of its lifetime. 

As you know, there are lots of ways to compute the hash for something. 

Integers are straight forward. If we want to store an int, we can something simple like int % table_size to get us an index in the array to put the value. This is straightforward, and there are several variants of this hash technique that can help with collision

Strings can use a similar method to calculate a unique value from each character, and then get us the index

Summing up all the ascii_values of a string like "apple" would give us a number like 97+112+112+108+101 which yields 530. We can then use 530 % table_size to find an index, and varaiations on this algorithm to reduce and handle collision

However, python in particular uses identity to create a hash. Because of the fact that literals and immutable objects are typically only allocated once, doing something like

a = "apple"
b = "apple"

is about the same as going

a = "apple"
b = a

In both of these instances, a and b are both pointing to a string object that contains a string "apple" as well as a unique identifier and a position in memory. Python utilizes the identity of an object to figure out its hash. 

Here's an example of a problem though. Imagine we have a list called lyst

lyst = ['h','e','y']

now let's imagine that we use the python default of using the id to hash the key (idk let's imagine some bogus number like 1234)

now let's say lyst = ['h','e','y','o']

Well, the lyst object is the same still, so its id is the same, and so we run into a problem where hey and heyo are not the same, yet, by using this lyst, even though it's changed, it'll still access the same key. 

However, if we want to access by object not structure, lyst is the same object, but because the structure is changed, or mutated, now the object itself won't match any key in the dictionary.

Now here's another problem

lyst = ['h','e','y']
lyst2 = ['h','e','y']

Even though they both have the same characters, the ids of these two objects are different, and so we'll end up having two different entries for a list that's structurally the same.

In this insance, by using mutable objects, we run into the problem of not being able to rely on the object itself. So we have to rely on the structure of the list. 

The key takeaway here is that we have to be absoulely sure about what we're using for the key. If we want to access a dictionary based on a unique object that contains information, then that'll be different that wanting to access a dictionary based on the information that the object contains. 

**Do we want to use the object itself as the key, or the information that the object contains? lyst1 vs "hey"**

Is != Equality

### Identity

A is B is equivalent to id(A) == id(B)

### Takeaway

Most ideas in programming are lies or guidelines to help people navigate the unknown. 

For instance, if we're driving on a windy cliffside, we all probably agree to NEVER drive off the side of the road. We even put guard rails up so that we can't do it. However, that's only true if your car doesn't have the ability to fly, which is usually the case.

Likewise, people say to only use immutable objects for a dictionary key because it can't change, but saying that something CAN change does not mean it WILL change. At the end of the day, if you generate a key based on a value, and that value will never change, well then it's really no problem to use that mutable object as a key.

### Dictionary Key Issues

We can use two main features of an object to determine the hash key

An ID, or a Value.

By default, some languages use the ID to determine the hash. Immutables like strings, numbers, and tuples have one object allocated every time that thing is referenced (there is only one instance of 5 or "asdf" at a time). 

Objects like lists will have a unique id every time we create a new one. So if we want to compare lists [1,2,3,4] and [1,2,3,4], it won't work because by default it checks ID. So we have to do a structural compare.

If we're anticipating on using an object to access a list, and we're using structure instead of ID, you should not change its data, or else obviously it won't be able to be accessed.

If you're using an ID instead of structure, you'll have to use the same list the entire time, but the problem with this is if we want to have different states for that list. Changing a list outside of a dictionary, will change the list in the dictionary.