### Copying Data

#### C++ Standard Copy Algos

copy

- Copies the elements in the range `[first,last)` into the range beginning at result.
- Used for copying data from one container to another. Things like arrays, strings, etc.
- Can be used on custom types.
- Compensates for type sizes
- just use this one

copy_backward

- Copies the elements in the range `[first,last)` starting from the end into the range terminating at result
- Does what copy does, but backwards.

copy_n

- Similar to copy but specifies first, and then n elements to copy from first.

#### C Standard Copy Algos

memcpy
- Used for copying raw data
- Copies n bytes
- No interpretation

strcpy
- Copies strings until it encounters null character
- Assumes the destination buffer is large enough. 
- Unsafe for the above reason, buffer overflow is dangerous and can be exploited

strncpy
- Specifies characters to copy
- Ensures that the destination is adequate.
- Adds nulls if the consumed data is shorter than specified which can cause other problems

strlcpy
- truncates results to fit the destination buffer
- avoids overflow




### Vals, Refs, and Ptrs (Parameters)
When writing functions, there are a few ways that we can handle the data we work with.

Pass-by-value copies the data from whatever was passed to the function into the parameter name. There's a small amount of overhead with this. Any changes to the parameter are not reflected outside. If you want those changes, you've gotta return it.

Pass-by-reference is almost always what you want. It creates an alias which is essentially just a name binding to data. This allows us to make changes to the object or data outside of the function, and has no overhead. 

Const Reference is the better alternative to passing by value. It makes the data readonly (so we get similar behavior as values since updates don't apply), we we get the aliasing that requires no overhead/copying that pass-by-value does.

Pass-by-pointer is when you're working with pointers specifically and need to pass them into a function. You don't always need pointers, think about their life-time (how long they'll be around for, and how long you need them for). Sometimes it's worth it to create objects on the stack, and a lot of times we really just need references.

### Project 1 Help

#### First Attempt Mistakes

- Rushing in without a plan. Write out comments and documentation on what your gameplan is. Draw things out, [review how a circular buffer behaves](https://en.wikipedia.org/wiki/Circular_buffer).
	- To my and your defense, the spec doesn't lay everything out explicitly
- Good naming conventions. Make sure that your naming conventions are clear. It's even worth-while to copy values to new variables with better names if your context switches, just to be sure you know what you're doing with your vars.
- Forgetting that we're doing things circularly. We don't want to treat it like the simple array that it is. We're treating it as though the beginning and end are connected. This is critical.
- Decide now how you want to handle incrementation, and keep in mind what your offsets will be when iterating. Read/Write then Advance after operation, you don't want to step on your toes.
- If you write and advance, you don't want to overwrite your data, and you don't want to read into bogus region.

#### Useful things to know

- Use std::copy or std::copy_n for swapping out data between arrays
- Expand() isn't a given, but you'll need to implement it. This will be crucial to inserting data
- Shrink will share a lot of the same type of logic as expand. You can copy a fair amount of code as far as copying data goes.
- You really only need to use one pointer in this project, and that's just for your array that you allocate on the heap, which allows you to size it dynamically. You will also need another pointer if you want to use a temporary array to copy data over while you resize your main array.
- BE SURE TO DELETE POINTERS AFTER YOU'RE DONE USING THEM
- The project requires you to allocate space in chunks. You can determine how many chunks you need by dividing the number you want to store, by the CHUNK size (8 per chunk) and then use a ceiling function to round up to the next whole chunk.
- Feel free to add console output. Also feel free to add small tests in your main. Just remember that it'll be run against an original main on our end.