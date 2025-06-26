
## Day 1
### Introduction

Discrete Math is where you'll really start to get into the science aspects of computer science. It is a CS course after all.

### What is Discrete Math?

Discrete math is a branch of mathematics that employs unique tools and disciplines like logic, graph theory, and combinatorics to analyze objects with a finite nature. These tools have practical applications in computer science


### Notes for Module 1

Logic is formal reasoning with an emphasis on making precise statements.

#Propositions are statements that are either true or false. They are the most basic element in logic.

Questions are not propositions, but propositions can be an answer to a question.

A proposition has a truth value which can be true, false, unknown, or some value in between (like an opinion)

Important variables:

Zybooks refers to p, q, r for our variables as opposed to x, y, z. It doesn't really matter but each set of mathematics has its own unique set of symbols, even if they're somewhat analogous. Read the questions carefully, I mix up p and q all the time


## [LOGIC SYMBOLS](https://en.wikipedia.org/wiki/Glossary_of_mathematical_symbols#:~:text=a%20category.-,Basic%20logic,-%5Bedit%5D)

### Conjunction ( ∧ )

- Logical AND
- p ^ q can translate to (x AND y) or (x && y)

### Disjunction ( ∨ )

- Logical OR
- Also known as Inclusive Or
- p v q can translate to (x OR y) or (x || y)

### Exclusive Or ( ⊻ )

- The way we normally use or in English. One or the other.
- You can go to Tim's class, or you can be a loser (jk)
- Also seen as ⊕

### Negation ( ¬ )
- Logical NOT
- Reverses the truth value of proposition
- If p is True then ¬p is False

**Order of Operations**
Parenthesis, Negate, AND, OR

### Truth Tables

Entries in a truth table have 2^n rows. Each column has equal number of true and false entries. We can see alternating patterns of T and F. The main way to fill out a truth table is to fill the first column split in half, top half with T's, bottom half with F's.

When evaluating compound propositions, we should evaluate individual expressions first. For instance NOT p AND (q OR r) can be broken down into an evaluation of NOT p as a unary expression, as well as the statement within parentheses as a binary expression. Not p has its own set of values, then the evaluation of q OR r yields its own set of values, and the results of those two distinct values can be evaluated as a final binary expression.
## Conditional Statements

A compound proposition that uses a conditional operation is called a **conditional proposition**, also known as a conditional statement.

### If Then ( → )
- p → q reads as if p then q
- proposition p is the hypothesis and proposition q is the conclusion
- 
- Evaluation of this proposition is true when p and q are both true, false if p is true but q is false.
- | p | q | p → q
  | --- | --- | --- | 
  | T | T | T |
  | T | F | T |
  | F | T | T |
  | F | F | T |
- Represents a contract. 
	- If p is true, then the contract breaks when q is false.
	- Doesn't have to be fair, only indicates a contract if p is fulfilled, then q HAS to be fulfilled. Says nothing about if p ISNT fulfilled.

### Converse 
- if q then p

### Contrapositive
- if not q then not p

### Inverse
- if not p then not q

### If and Only If ( ↔ ) Biconditional Operation
- What we might traditionally think of with conditional logic or contracts
- p if and only if q, shorthand p iff q
- | p | q | p ↔ q |
  | --- | --- | --- |
  | T | T | T |
  | T | F | F |
  | F | T | F | 
  | F | F | T |
- I will mow your law if and only if you pay me: Statement is true if the lawn is mowed and I get paid, also true that if I don't mow the lawn, I don't get paid. If mow the lawn and don't get paid, contract is broken, if I get paid, but don't mow the lawn, the contract is also broken.

### Conditional Precedence

If parentheses are not given, then logical operators get precedence over conditional operators. When in doubt, just use parens.

### Tautology, Contradiction, Equivalence

| p | not p (q) | p iff q |
| --- | --- | --- |
| T | F | F |
| F | T | F |

A Tautology means that all results are true, contradiction is all results are false. Equivalence is when two statements yield the same truth results.

### De Morgan's Laws

Logical equivalences that show how to distribute negation operations inside a parenthesized expression

1. NOT (p OR q) ≡ NOT p AND NOT q
2. NOT (p AND q) ≡ NOT p OR NOT q



# Day 2

## Topics
Take This Fish/Orders of Ignorance
- Logical Math
	- https://www.youtube.com/watch?v=BrDyDQYRUxM
		- [Law of Excluded Middle From Standford](https://web.stanford.edu/~bobonich/glances%20ahead/IV.excluded.middle.html#:~:text=That%27s%20why%20it%27s%20called%20the,be%20one%20or%20the%20other)
		- [Law of Excluded Middle](https://en.wikipedia.org/wiki/Law_of_excluded_middle)
		- [Laws of Thought](https://www.britannica.com/topic/laws-of-thought)
- Multi-state machines
	- https://www.youtube.com/watch?v=fXwSFhUVFmE
- Why use base 2?
	- see above
Go Over Exercises
## Logical Math