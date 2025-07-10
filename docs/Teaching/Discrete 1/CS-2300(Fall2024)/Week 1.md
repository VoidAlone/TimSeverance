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

Again, these kinds of statements or propositions describe the truth value of the overall statement. In a scenario where we're describing that if x is true, then y is true: if our x is true, but our y is false, then the overall statement is false because the statement posits that y must be true when x is true. y must be fulfilled when x is fulfilled. If x is false, but y is true or false, then no rule has been broken. 

### Converse (Luigi)
- if q then p

### Inverse (Wario)
- if not p then not q

### Contrapositive (Waluigi)
- if not q then not p

### Mario, Luigi, Wario, Waluiji

From ChatGPT: 

Given the playful nature of mapping these characters to logical concepts, here's how we might align Luigi, Wario, and Waluigi to the ideas of converse, inverse, and contrapositive:

1. **Luigi as the Converse**:
    
    - **Converse** in logic: If "If A, then B" becomes "If B, then A."
    - Luigi is often seen as the converse of Mario, being similar but not identical. He shares many of Mario's traits but is often portrayed as the more cautious or secondary character. If Mario is the protagonist, then Luigi, in many ways, could be seen as the character who would step into the same role if their situations were reversed.
2. **Wario as the Inverse**:
    
    - **Inverse** in logic: If "If A, then B" becomes "If not A, then not B."
    - Wario represents the opposite of Mario in many ways—greedy, selfish, and unruly. He’s the "not Mario" in terms of character and values, embodying what Mario is not. As such, Wario can be seen as the inverse of Mario.
3. **Waluigi as the Contrapositive**:
    
    - **Contrapositive** in logic: If "If A, then B" becomes "If not B, then not A."
    - Waluigi, as the contrapositive, is a more complex reflection. He’s not just a counterpart to Luigi; he’s a twisted version that contrasts with Luigi while also maintaining a similar dynamic to Mario and Luigi’s relationship. If Luigi is Mario's converse, then Waluigi, being the opposite of Luigi and reflecting Wario's relationship to Mario, aligns well with the concept of a contrapositive—taking the original relationship and flipping it in a more complex, mirrored way.

So, in summary:

- **Luigi**: Converse of Mario
- **Wario**: Inverse of Mario
- **Waluigi**: Contrapositive of Mario (and Luigi in some sense)

This mapping keeps the characters' relationships and their oppositional nature in line with logical operations.

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

[Waluigi Copypasta](https://www.reddit.com/r/copypasta/comments/5qctnl/waluigi_represents_all_of_us/)

