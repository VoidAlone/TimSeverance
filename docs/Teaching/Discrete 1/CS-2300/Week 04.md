
## Mathematical Definitions

### Even/Odd

Even: x = 2k (x and k are both integers)
Odd: x = 2k + 1

The definition for even is any number that is a multiple of 2, or can be evenly divided b y 2.

Parity is if a number is even or odd

### Rational

y != 0
r = x / y

Any number divided by any number as long as the divisor is not zero

This can be seen as the proof for a quotient
### Divides

x | y reads x divides y. In other words y / x. It's flipped and we're talking about the divisor.

This can be seen as the proof for the divisor

x divides y iff
x != 0
y = kx

There's a distinction between this proof and last is that r does not have to be an integer. For this proof, we're talking about whether or not an integer divides another integer, when k is an integer.

3 * 4 = 12. Or in other words, 12 / 4 = 3. 4 divides into 12.

4 | 12 -> k * 4 = 12. When k is 3, this is true.

Anyway, rather than proving the quotient, we're proving the divisor 

## Proofs

### Vocab

Theorem: a mathematical statement that can be proven to be true. Not to be confused with theory which is a scientific model that has been well tested and generally proven to be accurate.

Proof: logical steps that follow previous steps that arrive to a final true statement.

Axiom: a true statement. Used in proving

**Thus / Therefore**
We've used the word Therefore as the concluded statement in an argument up until now, but generally speaking, in the context of formal proofs, Therefore just follows from previous statements and does not necessarily indicate a conclusion. In formal proofs, the square can be used as the terminal character.

**Let**
For creating variable names

**Suppose**
Also for introducing variables. 

**Since / because we know that...** 
Invokes a previous statement


### Syntax

■ / T: Tautology

□ / ⊥: Contradiction

Theorem: some statement

Proof:
	Some statement
	Another Statement
	Conclusion ■

### Proof By Exhaustion

We've kind of done this one a few times in class. When our domain is small enough, then it might be prudent to walk through each element individually. 

Theorem: If n is an element of the set {-1, 0, 1} then n squared equals the absolute value of n.

Proof:
	Check the equality for every element in the set
	...


### Common Mistakes in Proofs

Generalizing From Examples. This is not an exhaustive proof, and just because it works for one example, does not necessarily mean that it works for all examples.

Skipping Steps

Circular Reasoning

Assuming facts that have not yet been proven

### Direct Proofs

Can be shown in the form of a conditional statement, p -> c where p is the set of hypotheses, and c is a conclusion.

### Proof by Contrapositive

Converse: If Q then P
Contrapositive: If !Q then !P
Inverse: If !P then Not Q

Proof by Contrapositive proves a conditional theorem p -> c by showing the contrapositive !c -> !p is true.

Work out truth table for each of these

### Proof by Contradiction (Indirect Proof)

Show that when the theorem is false it leads to a conclusion that is not true.

### Proof by Cases

Break the domain down into difference cases. All elements of the domain have to be assigned to a case. For Universal Quantifiers, proof by case can be used to show the validity of a statement.

Without loss of generality (WLOG) means that the proofs for different cases are so similar that they can be merged into one case.