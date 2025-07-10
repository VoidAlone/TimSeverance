### Counting

#### Product Rule

If we're determining the number of ways that a sequence of choices can be made, we can use the product rule to figure it out.

If we have some choice to make m, and then some other choice to make n, and these choices are independent of eachother, then we can view this as the cardinality, or number of choices that can be made for m, multiplied by the cardinality or number of choices that can be made for n.

In zybooks we're given an example of a menu where you pick a drink, an entree, and a side.

D = {Coffee, OJ}
M = {Pancakes, Eggs}
S = {Bacon, Sausage, Hash Browns}

We can represent the number of choices in a similar fashion to a truth table.

| D      | M       | S          |
| ------ | ------- | ---------- |
| Coffee | Pancake | Bacon      |
| Coffee | Pancake | Sausage    |
| Coffee | Pancake | Hash Brown |
| Coffee | Eggs    | Bacon      |
| Coffee | Eggs    | Sausage    |
| Coffee | Eggs    | Hash Brown |
| OJ     | Pancake | Bacon      |
| OJ     | Pancake | Sausage    |
| OJ     | Pancake | Hash Brown |
| OJ     | Eggs    | Bacon      |
| OJ     | Eggs    | Sausage    |
| OJ     | Eggs    | Hash Brown |

The number of rows is the number of combinations possible.

Alternatively, we can view this as nested for loops

for i in D:
	for j in M:
		for k in S:

This gives us three twice, twice.

The simple form is |D| * |M| * |S| = 12

#### Sum Rule

If all choices are available to use for a given selection like before, we can use the product rule. However, if our choices are partitioned, or exclusive, then we can use the sum rule.

In the book it gives an example of if we want to select a drink, but there are cold drinks and hot drinks. 

It kind of makes sense in the previous example, that our drink option was one out of the sum of drinks. If we want to though, we can nest, or encapsulate our options into categories which can numerically represent a different number of options. If we have hot and cold drinks, for a total of 5 drinks, the overall number of choices is still 2 * 2 * 5, but we can also encapsulate those 5 drinks into 2 distinct choices of either cold or hot drink and make it 2 * 2 * 2.

So, in the passwords example, if we want to make a password that can be 6-8 digits long, with various options for characters, we can view this as chars^6 + chars^7 + chars^8. This works out because we're essentially saying that there are 6 digit options, plus 7 digit options, plus 8 digit options.

Expanded further we can see this as (36x36x36x36x36x36) + (36x36x36x36x36x36x36) + (36x36x36x36x36x36x36x36)

### Bijection Rule

Remember that a function is a bijection if it is one-to-one and onto. We also know that a bijection has an inverse, and the inverse is obtained by mapping the targets to the elements of the domain.

So the bijection rule is that if there are two sets, that are a bijection, they have the same cardinality. Duh.

### Permutation and Combinations

Permutation without parameter contains each element of a finite set exactly once. The number of permutations is n! Every combination with all elements (no selection parameter given)

r-permutation P(n, r) has closed form n!/(n-r)! and is used when we select a limited number of items from the set. Yields x sequences of r objects from n objects **Order does matter**

Combination C(n,r), n choose r, closed form n!/(r!(n-r)!) is used when **order doesn't matter**. Gives an r-subset or r-combination. Yields x groups of r objects from n objects.

### Counting by complement

This one is pretty easy, if there are 10 items, 2 are red, then 10 - 2 = 8 not red items. This is counting by complement. It's everything outside of the given set.

### Permutation with repetitions

Remember that a permutation is a selection or arrangement where order matters. It's a sequence. If we have an arrangement where order matters, but duplicate elements in the resulting sequence, we can find the total number of sequences by taking the combination of spaces available and number of repeated elements and then multiplying each choice together.

Remember that a permutation has n number of elements in a set, and then we want to get a sequence of r elements (while r =< n). 

Permutation with repetitions >= Permutation >= r-permutation > r-combination

### Multiset

A set but you can have repeated items, but order still doesn't matter. The keyword here is distinguishability. Or uniqueness. If you want duplicates, but the distinction between duplicates doesn't matter, you have a multiset.

C((n+m-1), (m-1)

### Inclusion-Exclusion Principle 

| A | + | B | - | A intersect B |

This is an alternate form for finding the cardinality of the union of two finite sets. Can be used to find outcomes in combinations.

### Definitions

Counting: Determining the quantity of elements in a set

Permutation: An arrangement of elements in a set where order does matter. P(n, r) = n!/((n-r)!)

Combination: A selection of items from a set where order doesn't matter. C(n, r) = n!(r!(n-r)!)

### Extras Material

[Intuition behind permutations and combinations](https://buildingvts.com/intuition-behind-permutations-and-combinations-db6ffa5272be)

[Easy permutations and combinatiosn](https://betterexplained.com/articles/easy-permutations-and-combinations/)