### Decorators
This re-spec is longer than the original, but I go into more detail on how the features can/should be implemented. Read the original specification first, and then read this for clarifications if needed.

### Project Spec

You are given 4 files in the project. If you are using C++, you can use the .h files, if you're using Java, you can use the Output/StreamOutput.java. Everyone else will need to re-write these in their respective language. That shouldn't be daunting, they're very small classes.

#### Output
This is your common interface/abstract class that is shared between decorators and decoratables.
Specifies the following methods:

- Write(t : Any)
- WriteString(s : String)

#### StreamOutput
This is your concrete decorate-able. In this project, we're only using one concrete. This is analogous to the Coffee types in the chapter on decorators. Only, we're just using one class rather than multiple subclasses.

Members:

- sink
	- This is a reference to an ostream object that can be written to. (will be standard out) 
Defines the following methods:

- Write(t : Any)
	- writes an object to the sink
	- the java example invokes the writestring method and passes t.toString() to get the string representation.
- WriteString(s : String)
	- writes a string to the sink

#### Decorator Base

This is where your real work begins. You will create a class that extends/implements the Output class. So it will have the same methods as Output.

If your Decorator Base is just an interface, you must ensure that each concrete class that implements the interface has a field/member (whatever keyword applies) to store the wrapped object.

If your Decorator Base is an abstract class, go ahead and make the abstract class have a field that is your referenced decorate-able.

#### Decorator Subclasses

Member:

- object_to_decorate -> Reference to the thing you're wrapping/decorating
	- For typed languages, make sure it's of type Output.

##### BracketOutput
**From Original Spec: Surrounds each line with square brackets, and adds a newline to each.**

This sublcass will likely be the easiest and a good starting point for trying out your decorators.

For both Write and WriteString you'll be doing something similar to the dungeons&patterns demo. 

write("[")
write(t)
write("]\\n")

##### LineOutput
**From Original Spec: this precedes each write with the current line number (1-based) right-justified in a field of width 5, followed by a colon and a space.(Don’t add a newline.)**

Keep track of line number in this class, add the line number and spacing and stuff directly to the t parameter you passed in. 

Invoke your object_to_decorate.write/writestring method and pass the modified t string/stream object as the parameter.

##### TeeOutput

**From Original Spec: writes to two streams at a time; the one it wraps, plus one it receives as a constructor argument**

This one is mildly confusing, but fear not. You'll just be passing your parameter t along to the object_to_decorate.write/writeline as normal.

For the extra stream, you'll want a member that is a reference to an ostream, call it tee_stream. You'll assign your paremter t to this tee_stream object as well.

This tee_stream reference will be used to write to a file. 

In short, your TeeOutput will have members object_to_decorate, which is type Output, which through method chaining will reach the ostream object "sink", and then it will have this other ostream object tee_stream which exists only in TeeOutput. 

In main, you can pass an ostream to a file output as your constructor parameter for teestream.

##### FilterOutput

**From Original Spec: writes only those objects that satisfy a certain condition (unary predicate), received as a constructor parameter.**

This part can be the most confusing especially if the term predicate is new to you. I can promise you it's not though! Unary predicates simply take a single argument, perform some boolean logic on it, and return true or false. These methods can be passed as arguments in languages where functions are first class citizens.

Filter output will take a predicate function reference in its constructor and save it to a member. That function can then be used in your write and writestring methods to determine if you should invoke object_to_decorate.write/writestring

#### Main 

In your main, you should create / do the following:

- A StreamOutput instance
	- name it whatever you want
	- pass cout for c++, stringwriter for Java, sys.stdout for python, etc as parameter for your constructor. 
	- Since StreamOutput will be the core of your decorated objects, everything will end up going down to your StreamOutput where it will write whatever was passed to your decorator from the text file into the console.
- An input stream 
	- This will be used for reading lines
- ask for input file
- decorator menu
	- while loop
	- list out which decorators
	- when a number is selected, make a new decorator instance, and pass the older decorate-able as a parameter, as well as whatever other constructor parameters are needed, and then reassign the old variable to the new value. At the start, your StreamOutput instance will be fed to a new decorator, and the name of the variable will be reassigned from the StreamOutput, to whatever the new decorator is
- Write with decorator
	- For this part, just do a while loop using your inputstream, and feed lines from it into your decorator.write method.


