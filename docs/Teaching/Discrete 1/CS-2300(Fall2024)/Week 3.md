### Logical Reasoning

So far we've been building up a framework for working with logical in an algebraic format. Week 1 was sort of our arithmetic week. In introductory arithmetic, we're introduced to numbers, arithmetic expressions, and things like times tables and most of these things are so primitive that we are effectively taught them as universally true. 1+1 = 2 is just a primitively true expression. We use times tables to remember what combination of numbers yield a certain value.

In discrete, we're introduced to conjunction, disjunction, truth tables etc. Likewise, these are sort of primitive expressions and truth tables just show a mapping, or show what combination of expressions yield.

From those primitives, we can start to build up our capabilities like we did in week 2. And in week 3 we're continuing on in that format. 

Arguments have a specific format

h1
h2
therefore c

Arguments effectively translate to (h_1 ^ ... ^ h_n) -> c. In other words, an argument is a conditional statement. If hypotheses, then conclusion. What we aren't doing is saying "If my hypotheses are correct, then my conclusion is correct." We're evaluating the entire argument as a whole. So in normal human terms, people will make arguments and say "if A and B, then C must be true." Our job here is to test the validity of that claim. 

We shouldn't treat conditional expressions like an arithmetic expression where 1+1=2 and that's a given. We must test the validity of the entire expression. So, we have to evaluate the claim that 1+1 does in fact actually yield 2 (not a direct parallel but whatever).  In other words, we're not using the hypotheses to find a conclusion, we're testing the hypotheses and the conclusion all together.

So in a very primitive form we can create a true table to establish whether or not the argument is valid.

From the text:

To use a truth table to establish the validity of an argument, a truth table is constructed for all the hypotheses and the conclusion. Each row in which all the hypotheses are true is examined. If the conclusion is true in each of the examined rows, then the argument is valid. If there is any row in which all the hypotheses are true but the conclusion is false, then the argument is invalid.