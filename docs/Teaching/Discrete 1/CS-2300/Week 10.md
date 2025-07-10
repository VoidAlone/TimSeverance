
#### Program Correctness

We can verify that a program works right by breaking down different portions into individual sections and testing those sections. We can define some condition before testing to be true, and then verify that a condition is true after the algorithm's execution. 

#### Loop Invariants

If we have a while loop like this:

while(condition):
	do something / condition_change
	end_iteration

The loop condition is the portion that we use to determine execution of the while loop. If true, it continues, if not it stops.

The loop invariant is something that is true at the beginning and end of each iteration of the loop. It is effectively the "do_something" portion of the loop, or the body of the loop. We can use mathematical induction to show that our program runs correctly. This gives us a formal set of tools to work with rather than just "well, it seems to be working right for the cases I've given it." 

Deductive reasoning -> From general hypotheses to a specific conclusion
Inductive reasoning -> From a specific hypothesis to general conclusions

#### Recursive Definitions

Basis: shows that element(s) are in the set
Recursive rule: how to construct more elements from what we have
Exclusion statement: things that can't be made in the recursive rule or basis don't belong

[Stacks and Reverse Polish Notation](https://www.youtube.com/watch?v=7ha78yWRDlE)

[Parsing](https://www.youtube.com/watch?v=bxpc9Pp5pZM)

#### Binary Strings / Trees




