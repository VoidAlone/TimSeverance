### Relations

Relation is the word we use when an element from one set maps to an element in another set.

We use the notation xRy to indicate that x relates, or maps, to y. R is the set of relations from one set to another set.

If we have a cartesian product A x B where A = {1,2} and B = {A, B}, then A x B = {(1, A), (1,B), (2, A), (2,B)}

We can represent any subset of this Cartesian Product as the set R (Relation). What we're indicating here is that we have this sort of ordered mapping, where the first element in the tuple is an element from the domain, and that the second element is from the range. So we're indicating that 1 maps to A, and it also maps to B. 2 maps to A, and it also maps to B. Keep in mind, we're not necessarily ensuring that the mappings enforce a well defined function. 

Set R doesn't have to include every element of the cartesian product. It just represents some given subset.

#### Reflexive

if all elements in the domain A map to themselves. Or in other words, for all x in A, xRx.

Example: A = {1,2} ... A x A = {(1,1), (1,2), (2,1), (2,2)} 

R = {(1,1), (2,2)}
Note: This subset R doesn't include all elements from the cartesian product, but the elements it does include follow the rule of xRx. In other words, 1 maps to 1, 2 maps to 2, and is reflexive.

R = {(1,1), (1,2), (2,1)} 
Note: This subset R doesn't include all elements from the cartesian product. And since it's missing (2,2), it is not reflexive

#### Anti-Reflexive

For all elements in the domain, it is not true that xRx. 

Example: A = {1,2} ... A x A = {(1,1), (1,2), (2,1), (2,2)} 

R = {(1,2)}
Note: This subset R has mappings (1,2) xRy. Since it has no mappings xRx, it is anti-reflexive.

R = {(1,1), (1,2), (2,1)} 
Note: This subset R has a mapping (1,1), and so it is not anti-reflexive

#### Symmetric

For all elements in the domain, xRy if and only if yRx

Example A = {1,2,3} ... A x A = {(1,1)(1,2)(1,3)(2,1,)(2,2)(2,3)(3,1)(3,2)(3,3)}

R = {(1,2),(2,1)}
Note: This subset has mappings (1,2) and (2,1), which means that xRy and yRx. 

R = {(1,2)(2,1)(1,3)}
Note: Even though this subset has mappings (1,2) and (2,1) which are symmetric by themselves, we also include (1,3), but not (3,1), so it is not symmetric.

#### Anti-symmetric

Can't be symmetric at any point. Everything else is allowed.

#### Transitive

If a maps to b, and b maps to c, then a maps to c.

Note: This isn't saying that a graph must be transitive, just that it is transitive if we have mappings from x to y, then y to z, and x to z.

### Digraphs

is a pair of Vertices and their Edges (V,E). V is a set of vertices, E is a set of directed edges that is a subset of V x V. 

#### Head / Tail
In a directed graph, u -> v, v is the head, u is the tail.

#### In/Out Degree

How many edges point to or away from a vertex

#### Walk
Can be reprsented by notation

<v0, v1, ... vi>

Length = number of edges in a walk

**Open Walk** is where first and last vertices are not the same
**Closed Walk** is when the first and last vertices are the same

**Types of Walks**
- Trail: Unique Edges
- Path: Unique Vertices
- Circuit: A closed trail. Or a closed walk with unique edges
- Cycle: A circuit greater than or equal to 1, where all vertices are unique except for the start and end. In other words, A Circuit Path.

### Composition of Relations ( 5.4 )

All relations have been represented using a digraph so far.

The composition of relations basically takes a mapping aXb and mapping bYc, and we end up with the relation aZc if we composite the relations together.

If we have some function f(x), we have our domain as input, and our targets as output. In chapter 4.5 we saw how if we compose a function with its inverse, we end up mapping our input to our input. To get there though, we put some initial input in, and receive and output. When we use that output as the input for our inverse function, we get as output, the original input.

The composition of relations more or less just shows these mappings in digraph form, rather than in a pure functional form. 

In 5.4, when we compose S with R, or S o R, we're looking at the digraphs that represent the mapping, or results of applying a function to input from a set. R is the result of some function, and S is the result of some function. When we get S o R, we're essentially calculating S(R(x)). and demonstrating that relationship as x(S o R)y. 

So if we pass a to the composition S o R, we're saying, okay if we put a into R, we get the result d, when we get d and pass it into S, we get C. So that's why a maps to c in S o R.

#### Graph Powers and Transitive Closure

In this section we can think about things almost geographically. The power of a graph represents how many steps in a walk we can take, or how many times a function is composed of itself. If I can go from a to d in a step, and I can go from d to a in a step, then I can go from a to d back to a in two steps, or vice versa. 

We're essentially saying, given a certain number of steps, what destinations can I get to? Thinking back to composition of functions, we can see the composition of a function with its inverse as a walk of 2. 

If we have 4 vertices, then we can calculate up to 4 mappings. We describe all of these mappings as G^1, G^2, G^3, G^4 etc. These mappings are calculated by either visually determining which nodes you can get to given a number of walks indicated by the superscript of the graph G, or by composing the functions with each-other. Again, digraphs just graphically represent the relationships between inputs and outputs of a function. 

We can calculate this by doing G o G for Gen 2, then G o G2 for gen 3 and so on.
R^k = R o R^(k-1). 

The Transitive Closure is just describing the combination of all of the possible walks for a given power of a graph. So if we have G^1, G^2, G^3, and G^4, we're combining all of these graphs together, to indicate all of the transitive walks for a given graph. This is indicated with G^+

When we're describing a transitive closure, we're saying "okay, take all of the possible combinations of walks that could exist over all generations, or number of steps, and combine them into a single digraph"

So then it describes every possible way to traverse, but rather than having to speculate how to get there over a number of steps, we just instead say "okay, if you can get to A from C by walking through D or B, we can just instead simplify things and show that it's possible to get to A from C.
#### Matrices

Another form to represent mappings. We can use matrix operations on these mappings to manipulate them in ways that might be useful in different applications.
#### Partial Order

Relation R on set A is a partial order if it is reflexive, transitive, and anti-symmetric. 

#### Strict Order

Irreflexive, assymetric, and transitive

#### Equivalence Relations
Reflexive, symmetric, and transitive

### Directed Acyclic Graphs

A digraph with no cycles.