
### [LOGIC SYMBOLS](https://en.wikipedia.org/wiki/Glossary_of_mathematical_symbols#:~:text=a%20category.-,Basic%20logic,-%5Bedit%5D)
### Predicates

Predicates are functions that can take 1 or more variables that returns the result of a logical statement. In programming, we often refer to functions as predicate functions when they specifically return a bool.

[C++ named requirements: Predicate](https://en.cppreference.com/w/cpp/named_req/Predicate)

Domain: set of all possible values for a variable

Predicates can be true for all input, but they're still considered to be a predicate and not a proposition simply because it has a variable.

### Universal Quantifiers

While a predicate is still a predicate, and not a proposition because it has a variable, if we make a statement about the predicate itself, then this is a proposition, or a universal quantifier. We're talking about the function itself, rather than the result of the function. In this sense, when we say "for all x, P(x)" we're asserting that either P(x) is true for every x, or it there is some scenario where P(x) yields false. In other words, rather than relying on the assignment of a variable to determine the truth, we're just looking at every possible combination of variables from the domain, and this ends up making the entire thing a proposition again because:

$∀xP(x) = P(a_1) ∧ P(a_2) ∧ P(a_3) ∧ ... ∧ P(a_k)$

So going back to the statement where we say P(x) = x + 1 > 1 and let's limit the domain to just 1 and 2

| x   | P(x) |
| --- | ---- |
| 1   | T    |
| 2   | T    |

| P(1) (x) | P(2) (y) | x ^ y (z) |
| -------- | -------- | --------- |
| T        | T        | T         |
| T        | F        | F         |
| F        | T        | F         |
| F        | T        | F         |
So, if we can show that P(x) for 1 and 2 is true, then we can see that the quantified statement is entirely true. This works because by assigning values to a predicate, it then becomes a well defined proposition, and therefore, we can combine the results of every variable in the domain the show the truth value for that Universally Quantified Statement.

#### Counter Example

It's obviously a lot of work to show that something is true for literally every value in the domain. So the idea is that we just find one scenarios where one of the propositions is false, which is sufficient to show that the universally quantified statement is false, following the rules of conjunction. If a predicate doesn't take a variable, or if the domain is 0, then the universally quantified function is true.

### Existential Quantifiers

This works the same way as the Universal Quantifier, but rather than saying "EVERY" P(x) we say "Some" P(x) is true, or more accurately, some x exists that makes P(x) true. Existential Q's can take the form 

$∃xP(x) = P(a_1) ∨ P(a_2) ∨ P(a_3) ∨ ... ∨ P(a_k)$

You'll notice a trend throughout this class, that really we're just thinking of every possible combination of outcomes. This comes in the form of conjunction vs disjunction for example, and then their subsequent truth tables that show all possible truth values given a way that we can express a logical statement. Universal seeks to find one instance where x results in a false statement rendering the entire statement false, whereas Existential seeks to find one instance where x results in true rendering the entire statement true.

### De Morgan's Law

The same rules that we can use to distribute negation into conjunctive or disjunctive statements can obviously be applied to Quantified statements because as we saw before, those quantified statements can simply be viewed as massive propositions. 

### Nested Junk

In 1.10.1 we can see that a matrix can be really useful for representing the domains for each variable for a predicate. 

In the examples where they talk about Everyone sending an email to Everyone or "for all x, for all y, x sent an email to y" where the domain for x and the domain for y is every employee.

We get 

| -     | Tim | Alex | Devin |     |
| ----- | --- | ---- | ----- | --- |
| Tim   | T   | T    | T     |     |
| Alex  | T   | T    | T     |     |
| Devin | T   | T    | T     |     |
This is why the statement is false when someone doesn't also send a message to their self.

If we want to express this more naturally then we can create a more complex statement as demonstrated in zybooks where for every person and every recipient, if someone is not theirself, they sent an email to everyone UxUy((x != y) -> M(x,y)).

