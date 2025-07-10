### Topics

In-Degree / Out-degree

Adjacency Matrix

String Concatenation

Set Partitions

- There's a question that asks you to figure out the representation of a set partition in the set builder notation. If you're iffy on set builder, you should still be fine, just think logically about how we represent equalities on a number line.

Floor / Ceiling Functions

Subsets

- Remember that if a set is an element of a set, the elements of that set are not elements of the main set.... A = {1, {2}} Then 2 is not an element of A, and {2} is not a subset of A. {{2}} is a subset of A.

Set builder notation:

Set Operations

- Union = Combination of elements

- Intersect = Elements that are in common

- Difference = A - B = Elements only in A

- XOR / Symmetric Difference = Elements that are not in common

- Complement = Elements outside of the set.

Strings

- 3.6 Talks about string notation

- 4.1 Talks about operations on strings

Functions:

- g: R -> R . g(x) = |x| 

	-  g maps every real number to a real number, specifically it maps all real numbers to the absolute value of itself.

- One-to-one, onto, bijection

- Well-defined: all elements have one and only one mapping.

- Identity Function (4.5)

- Inverse of Functions

Logarithms

- One question on log expressions and equivalences

Hasse Diagram

Composition of Functions

Composition of relations

Equivalence Relation

Partial, Strict, Total Orders

Graph Powers

### Written Questions

Transitive Closure (4.5)

- You'll be given a digraph, you need to be able to to determine the powers of the graph and show the transitive closure (basically the union of all the different powers of the digraph)

- Check out 4.5.4 PA to easily calculate the transitive closure

Adjacency Matrix, Boolean Matrix Multiplication (4.6)

- Convert a digraph to an adjacency matrix

- Multiply the matrix against itself to find G2

- A x B would see you multiple r1 of A against c1 of B, then c2 of B, c3 of B, then move to r2 of A and so on. 

- When performing the multiplication, you multiply the corresponding elements of rows and columns (r_1_1 and c_1_1, r_1_2 and c_1_2, etc) and then boolean add the results. In other words, if any of the multiplications result in a 1, you'll have a 1 for the resulting matrix coordinate. Row 1 and Column 1 correspond to index \[1,1\] in the matrix.

Power sets (2.2)

- Remember that power sets is the set of every combination of elements in the set.

- Remember that the number of elements in a power set (cardinality) is 2^n. So if there are 3 elements in a set, the power set will have 2^3 elements.

Composition of Functions (3.5)

- Functions map elements from a domain, to targets in the range (not necessarily every element of the range).

- If we compose one function of another function, the input into the composition will yield an output from the inner function, and then the output will be consumed as input for the outer function. g o f is g(f(x))

Inverse of Functions (3.4 & 3.5)

Set operations (2.3 & 2.4)

- You'll be asked to perform some unions and intersect, and subtract sets from other sets.

Identity Proof (2.5)

- You'll be given a cheat sheet in the appenix, and you'll just need to demonstrate using the form where you present known facts as hypotheses, then introduce identities, and show which lines you're applying the rules to. (See 2.5.3 PA)
