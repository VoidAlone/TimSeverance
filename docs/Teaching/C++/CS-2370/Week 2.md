
### Evaluating Expressions

https://en.wikipedia.org/wiki/Binary_expression_tree

Last time, we talked about evaluating expressions. In most languages, we have a few unary operators, several binary operators, and sometimes a ternary operator. Ternary kind of sucks to be honest. In most situations, favor readability. Just makes things clearer.

### Type Conversions (2.13)

Implicit conversions happen between types that can naturally be coerced into the other. Ints can be converted to floats, chars can be converted to ints, etc. The term coercion is not an official term, but you might see it every now and then, and it usually just refers to implicit conversions. We can do implicit conversions with assignments as well. 

https://www.geeksforgeeks.org/casting-operators-in-cpp/

https://en.wikipedia.org/wiki/Assignment_(computer_science)
#### Casting

##### Static Cast
This is the most common type of cast. Compile-time conversion. Similar to C style cast 

##### Dynamic Cast
Used for downcasting (Parent->Child) as opposed to upcasting (Child->Parent)

##### Const Cast
Adds or removes constness depending on the state of constness.

##### Reinterpret Cast
Changes the pointer type.

##### C-Style cast
(type)expression;
(double)i;

##### Functional Cast
type(expression)
int(i); Mimics a constructor.

### Bitwise Operations

Adding binary numbers works in the same way that adding decimal numbers does. Decimal notation works on a range of 0-9 for every place of increasing or decreasing power. So, if we take the number 9, which is the limit of the range of values in the 1's position, and then add 1 to it, we overflow that position, and increment the next position. During this overflow, we wrap back around to 0, and continue up until 9. So 9 + 1 = 10. Then we get 10 + 1 = 11. And so on. 19 + 1 = 20. It works the same way in binary, but we can only hold 1 value at a time. So, when we add in binary, we simply do the following: 0 + 1 = 1. 1 + 1 = 10 (this is 2). 10 + 1 = 11 (3). And so on. 

Two's complement is a form of representing binary values that circuments a lot of shortcomings from previous binary representations, specifically in how we approach arithmetic. The only thing you really need to know is to get a negative value, you take the positive representation in binary, flip all of the bits, and then add 1. This will give you your two's complement, or standard binary representation.

https://en.wikipedia.org/wiki/Two%27s_complement

101 = -3
001 = 1

101 + 001 = 110 = -2

#### And

For a binary expression, evaluates to true when both operands are true. Evaluates to false in any other scenario.

#### OR

For a binary expression, evaluates to true when one or both operands are true. Evaluates to false when both operands are false

#### XOR
For a binary expression, evaluates to true when one and only one of the operands is true. Evaluates to false when both are true, or both are false.3

### Switch Statements


### Floating Point (2.18)

Scientific notation for decimal numbers can be something like 

300 = 3 x 10^2 

https://en.wikipedia.org/wiki/Scientific_notation

For floating point, we use a similar system but with some slight caveats and given assumptions. 

Sign is used to represent a positive or negative. Exponent is used to represent by how much to shift the point. It's the exponent attached to the 10 in decimal scientific notation, or 2 in binary scientific notation, but the main thing to remember is by how much you will shift the point by.

In order to get a full range of left and right shifts, we use 8 digits to represent the exponent, and then offset whatever that value is set to by -127. So, if you want to represent 2, then your expression would be 2 x 10 ^ 0 or 1 x 2^1. In binary, we can only use 0 or 1.

So we use the exponent to represent how much to shift, and the "mantissa" is the left hand side, or the significant digits. There's on important thing that we do though, we assume that there's always a 1 for our significant digit. Since a binary value needs to have a 1 in order to be valid, then every non-zero number is going to have at least one 1 in it. So, we just assume that the one already exists, and this allows us to get a greater range out of our digits. 

### Value Categories

https://en.cppreference.com/w/cpp/language/value_category

https://learn.microsoft.com/en-us/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=msvc-170

### Universal Initialization 

Basically just use braces for everything.

https://en.cppreference.com/w/cpp/language/initialization