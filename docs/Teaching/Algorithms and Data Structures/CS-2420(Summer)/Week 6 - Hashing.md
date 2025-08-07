## Hash Stuff

### Keywords:
 Hash Table
	- DS that stores unordered items into a location in an array. A map with hashing.
 Key
	- First item in key pair value, used to map to an index
 Bucket
	- Each element in the array is a bucket
 Collision
	- Numbers can have same hash values, and end up being mapped to the same location. Can be resolved with chaining or open addressing
 Chaining
	- Items that map to the same bucket can be stored by using a structure in that bucket
 Open Addressing
	- Linear Probe 
	- Quadratic Probe
	- Double Hash
 Resizing
	- Load Factor = items / buckets
 Clustering
 Hash Functions (computes the correct location)
	- Modulo Hash
		- key % size_of_array
	- Mid-square hash
	- Mid-square with binary
	- Multiplicative string hash function
 Direct Hashing
	- Always provides O(1) time complexity, but creates O(n+1) or O(n) space complexity because each key gets mapped to its direct index value. No collisions, but takes a TON of space

### Applications
Cryptography
Data integrity (integrity can't be garanteed, but but corruption can be garanteed)

### Big Idea

We're just mapping a value to a stored position based on a key. The easiest way to do this is by taking the key, mangling it in some way to correspond with an index or position in our structure, and then storing its associated value there.

The most straight forward way to do this is by mapping the key to a numeric value, then modding it by the size of an array, which maps it to a position in the array.

The important thing is that we can always find our value based on our key. So, we want to always be able to pass our key through some kind of function, and get the same result.

The whole section is about mapping values, and we do a lot of mangling to get unique mappings.

### Collision Resolution 

To handle collisions, we can do a few things. Probing and double hashing

**Linear Probing** is easy because we can check if a bucket (index) is occupied, and if it is, we just iteratively walk through the list until an empty spot is found. To search for an item in a map using linear probing, if it's not in the expected bucket, we just keep walking forward until we find it, or the list is empty. There's an optimization we can do. If we distinguish buckets as either "empty since start" or "empty after removal" then we can search until we find an "empty since start" which means the item was never added, otherwise, that bucket would have been occupied at some point since we're doing a linear insert.

**Quadratic Probing** is the same idea as linear probing, but with better performance because things don't get clustered. The mechanisms for inserting/searching/removing are all the same, but in addition to iteratively walking through, we use a formula to determine the position to check next. 

formula : (hash_value + const1\*i +const2\*i^2) mod table_size

You can pick any constants you want, but avoid using multiples of the size of the array you're storing to, or else you'll end up getting the same index over and over.

**Double Hashing**

Similar to quadratic probing, but we use two different hashing algorithms to get a result

Formula: (H1 + i\*H2) mod tablesize

We still iteratively look for a new position when resolving the collision.

### Resizing

Pretty easy, you have a newly sized array, we usually pick a next prime number for our size (to optimize our collision handling). Once we've made the new data structure, it's as simple as walking through the old one, and remapping the values to the new one. Since our underlying storage is an array (or sometimes a tree), we can just traverse normally. This is one of those moments when the DS we're working with has certain constraints in a context, but at the end of the day, it's a basic DS under the hood. We don't need special hash-map type constraints when resizing, because we just have to move everything over, which will always be an O(N) operation. So we can just now treat it like the underlying storage it is. Once everything is moved over, we go back to pretending that it's different, ie, we apply the constraints of a hash map to the structure to get certain benefits out of it.

We can use a load factor which can basically be arbitrarily chosen. We can base it off number of filled buckets, number of collisions during an insert, or the size of a linked list in a bucket if using chaining.

### Hash functions

[Nothing here yet, check the book if needed]

### A summary

This whole section is about mapping, and by extension hashing, and collision resolution. A hash map is pretty straight forward. 

The idea is to try and spread everything out as much as you can. By making more complex hashing algorithms, you can sort of spread out the resulting hash value, which gives you a better chance of not colliding. When you resolve collisions, more complex resolutions result in more spread out results so there's less clustering, and less operations performed to find the result. When storing to a data structure, a large array is preferable, because there are more locations to store to, and less likely chance for collision.

The great takeaway is the same thing we've been learning, better results comes at a cost, and we're usually either talking about speed or space. The bigger the array, the less likely you are to collide, and therefore have quicker lookup times. The less space you take up, the more likely you are to collide, thereby decreasing performance, but saving space.

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