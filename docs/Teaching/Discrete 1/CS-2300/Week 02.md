
## Day 1

Labor Day
## Day 2

### Predicates

- A statement that is a function of one or more variables.
- Because it is a function, it is not a proposition until the input has been specified. 
- "x is an odd number" is ambiguous until x has been assigned. "5 is an odd number" is a well defined statement, and then it becomes a proposition.
- Can become a proposition with Universal Quantifier
- Variable x is unbound until a quantifier is introduced (because it can take on any value)
- **A statement is only a proposition when its variables are bound**
### [LOGIC SYMBOLS](https://en.wikipedia.org/wiki/Glossary_of_mathematical_symbols#:~:text=a%20category.-,Basic%20logic,-%5Bedit%5D)

#### Universal Quantifier ( ∀ )
- ∀x P(x) -> For all x, P(x) or For every x, P(x)
- ∀x means that P(x) is true iff P(x) is true for every single value in the domain of x.
- ∀x P(x) is equivalent to P(n1) ^ P(n2) ^ ... ^ P(nk)
- Because P(a1) is well defined, and is therefore a proposition, we can see that this is a compound proposition, which can result in a single well defined truth value. 

#### Existential Quantifier ( ∃ )
- ∃xP(x) -> An x exists such that P(x) is true. There is at least one value in the domain of x that makes P(x) a true statement
- ∃x means that P(x) is true iff P(x) is true for at least one value in the domain of x
- ∃xP(x) is equivalent to P(n1) v P(n2) v ... v P(nk)

### Quantifiers
- Highest precedence
- Variable x becomes bound by quantifiers

#### De Morgan's Law For Quantifiers

- ¬∀x F(x) where F(x) means x can fly and the domain of x is the set of all birds.
- ¬∀x F(x) is evaluated as ¬(∀x F(x)) because of order of operations.
- ∀x F(x) is equivalent to P(n1) ^ P(n2) ^ ... ^ P(nk) which means that only one of these values needs to be False, in order for the entire Quantified Statement to be false. 

F(x) -> x can fly
X is the set of 2 birds
For every x, x can fly ->

F(Bird1) ^ F(Bird2)

|   |   |   |   |
|---|---|---|---|
|Bird1 Can Fly (p)|Bird2 Can Fly (q)|P ^ Q|! (P ^ Q)|
|True|True|T|F|
|True|False|F|T|
|False|True|F|T|
|False|False|F|T|

So the statement isn't that No birds can fly, the statement is that Not all birds can fly, because the statement can be true when one can fly while the other cannot. It can be true as well when no birds can fly, but that statement would only truly be applicable if our truth table yielded false for one bird being able to fly, and the other not being able to fly.

Since this statement is equivalent to not all birds can fly, then the statement "There exists a bird that cannot fly" is equivalent as well.


