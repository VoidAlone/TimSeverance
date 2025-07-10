### Terminology
Set: A usually unordered collection of objects. Technically a set is defined in terms of axioms where some element x is an element of a set S. In other words, it doesn't have anything to do with quantity of that thing, just a description of its existence in that thing.

Element: Object in a set

Roster Notation: A = {}

Cardinality: The number of items in a set

Null set / Empty set: {} A set with nothing in it. Cardinality = 0

N: Natural Numbers
Z: Integers
P: Irrational numbers
Q: Rational numbers
R: Real numbers
Superscript +/- indicates set of values that are non-zero positive or negative

Set Builder Notation: A = {x ∈ S: P(x)}. Read as follows: A is the set of all x in S, such that P(x)

Universal set: Is the set of all elements within a context

Subset ⊆: If all the elements within one set exist within another set, then those elements are within a subset of another set.

Proper Subset ⊂: Same conditions as above, but A != B

Another way you can approach it is by looking at the subset as a base for determining if something is a proper subset or if two sets are equal. A proper subset is proper because it's truly a subset, in the sense that it's not equal to the superset.
### Loose Ideas
**Subset vs Element in the context of Power Set**

The empty set is a subset of every set. 

A = { 1 }
nullset 
P(A) = { nullset, {1} }
	
	Ideas about scoping exist here
### Power Set
\
With power sets, the key takeaway is that it only contains sets. Those sets are the combination of every item contained within the original set. Nullset is a part of the power set because the nullset is technically part of every set.

The amount of items (cardinality or arity) in a power set is 2^n 

### Unions and Intersections

Intersections imply where two roads converge, or where two things meet, or where they share something in common. So, the intersection of two sets are the things they have in common, which is that nice little middle overlap slice in a venn diagram.

Unions are the combination of all things. We take a union, a combination, of things that don't necessarily belong to one another or have to do with eachother, but become one.

### Difference

This is an exclusion. It's everything I don't have in common with you. As with subtraction, a difference expression with sets is not commutative.

### Symmetric Difference
This is represented with the same symbol that we use for XOR. 

This can be summed up with (A - B) U (B - A) In other words, everything A does't have in common with B, combined with everything that B doesn't have in common with A. It is a set of pure differences. *Insert political joke here*

### Set identities

We can express set operations with logical operations. These identities allow us to perform different types of algebra on sets that we might not normally be able to. 

### Cartesian Products

2