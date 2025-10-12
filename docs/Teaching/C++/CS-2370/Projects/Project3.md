# Notes, tips, and tricks for P3 - Bits

## Friend keyword

The friend keyword is used for when you're overloading a non-member function for
your class. This is essential because we're literally defining the function of
another class. For example, the equality operators or ostream output operator
are all functions defined in other libraries. Since these functions do not have
definitions for our object, we need to overload those function library methods
so that they can handle our object. 

The big thing is that since it's relevant to our class, we define it in the body
of our class. Make no mistake, it doesn't belong TO our class though. We're
simply defining it in respect to our class.

This is why we need the friend keyword. Our class's member data is generally
private. If such data is private, the functions that we overload DON'T have
access to our class data. Again, we're overloading ANOTHER class's functions to
be able to handle our class. As such, it doesn't have access to our data.

Friend simply designates another class/class method as being able to access
private data. Another class can't declare itself a friend and suddenly gain
access to that private data. The class in question has to be willing to provide
that private info.

[C++ Friend (Microsoft docs)](https://learn.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-170)

## IType (lead up to templates/generics)

IType is a simple lead up to templates. The idea is code reuse. Basically, it's
kind of a pain at best to modify code all over the place, and dangerous at
worst. The idea is, if we want our class to be able to handle a variety of data
types, we don't want to hardcode data types. But because C++ is statically
typed, we HAVE to declare what type something is going to be.

This is where this project uses IType and binds it to the "unsigned long long"
data type. We're just renaming it. This is a step closer to modular code. Rather
than changing every instance of where we want to use an int vs a ulong, we can
just specify one spot that says "everywhere you see IType, it's actually this
type."

Imagine if you wanted to use ints instead, but now you have to go through and
replace every instance where ulong is. Let's say you want to switch it back.
Well, we also use ints for other things like indices, and parameters, so it
starts to become confusing as to which ints we actually want to change to ulong,
       and which are supposed to stay ints.

We're still limited though, if we want to be able to support bit operations on
ints AND ulongs, we have to define two separate header files to account for
that, even if we're still using IType. These class definitions are still bound
to our declaration ```using IType = unsigned long long;```

This is where templates will eventually make things easier, and are the basis
for making it easier to handle all kinds of types in c++. We'll get to that
later though.

## Enum as a constant

The other line that's weird is the NBITS portion. This is simple an old
idiomatic way of declaring a named constant. Our NBITS is getting the number of
bytes, then multiplying the byte count by the amount of bits in a byte, and this
gets us the total number of bits in a given number like "unsigned long long."
We're just using this enum idiom to set that constant for us.

## Bits

Okay this is the real part that matters. For most bit operations, remember to
refer to chapter 3 in zybooks. However, there may be some hiccups, especially
when figuring out the solution to rotate, which is the hardest function in this
project.

As an example, let's check out "void Set(int pos)"

```cpp
void set(int pos){
                        //bits -> 1101, pos -> 1
    IType x = 1;        //...0001
    x = x << pos;       //...0010
    bits = bits | x;    //1101 | 0010 -> 1111;

    //one-liner version
    bits |= IType(1) << pos;
};
```

Here is an example doing some bitwise operations in C++. You can
easily turn this into a one-liner but for the sake of clearly understanding
what's going on, I'm going to write it out line by line. We suppose bits is set to
something like 1101. We want to set the first (0 indexed) bit with the least
significant bit being 0th indexed. We then create a 1 out of the type we're
representing bits with, bit shift to get our mask. In this case, we want to set
bit at index 1 to be 1, so we move that 1 over to position 1. We then 'or' the
bits with the mask and that sets the bit we want.

## Rotate

I won't give you code for this one (it's just a few lines and pretty easy)

However, the logic can be tricky to work out. Consider a right rotation. If we
want to rotate bits to the right, some of them will fall off the right side, 
and will have to be moved in from the left. 00101 shifted right by one should
become 10010. Every bit is shifted right by 1, and the 1 bit on the right most
side falls of, and rotates back to the left-most side.

So, in considering how to save bits and move them from one side to the other, we
can think of the bits as two partitions.

If we want to shift 10101 to the right by 2, you can think of the pre-shift bits
like this

Pre-rotate:

| Left | Right |
| --- | --- |
| 101xx | xxx01 |

The left side represents the bits we'll keep, and the right side represents the
bits that will fall off. We're shifting right by two, so 101 will occupy the
right partition, and 01 will occupty the left after our rotate is complete.

Post-rotate:

| Left | Right |
| --- | --- |
| 01xxx | xx101 |

Result: 01101

So, since we're pushing the right side off, they'll roll back around, and be on
the left. Effectively we can just think about this like we're swapping
partitions. So we move our right side to the left, and our left side to the
right. 

We can do this in one swing by 'or'ing these two operations.

The left side must be shifted by 2. This gives us the following

```10101 >> 2 -> 00101```

We can see that we lose two bits because we pushed them off the right side, and
now 0's occupy the empty space as a result of the rightward bitshift.

Now, we have to consider how to move our right side bits to the left. Well, we
know that they really need to be moved over left by 3. More specifically, the
bits need to be moved over by NBITS - n; In our case, 5-2 -> 3.

```10101 << 3 -> 01000``` 

The bits that "fell off" were our "01" bits. So, we need to push them over to
fill in the gap left by moving our previous bits to the right by 2. Refer to the
chart above if that part isn't clear.

### Negative rotates

Left and right rotates are equivalent, we just have to compensate for the
direction.

Consider our right rotation on 10101 by 2. We get 01101. We could get the same
result by rotating this number left by 3. That's effectively what we did in
our second step.

So if a positive rotate by 2 is the same as a negative rotate by 3, we can think
of it like this: Where NBITS = 5, and n = -3 

n + NBITS = rot -> -3 + NBITS = 2

So, for a negative rotation (e.g. you passed -3 to rotate) you can apply the same 
logic as above, just perform this converstion operation on your position 
parameter, n, first e.g. n += NBITS;
