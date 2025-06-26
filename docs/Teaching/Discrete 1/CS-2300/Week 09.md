### Sequences

https://www.youtube.com/watch?v=JteQEN1XPyc

https://www.youtube.com/watch?v=XHyeLKZYb2w&t=234s

Sequences are special functions that take sequential integers, indices, as the domain or input.

Geometric sequence takes a previous number and multiplies it by a common ratio. 

Arithmetic sequence involves a common difference.

m = initial index
n = final index
a_m = initial term
a_n = final term

In short, sequences are just some type of repeating pattern (arithmetic, geometric, quadratic, etc.), and we can represent those patterns in a few ways.

### Recurrence Relations

Recurrence relation is when a term is defined as a function of previous terms. 

Geometric sequences rely on the previous term can 

Dynamical System is one that changes over time. Over discrete time intervals, each state is fixed during each slice. The history of the system is defined by a sequence of states.

### Sigma / Summation Notation

Expresses the sum of terms in a sequence

Don't confuse summation notation with the series itself. 

For instance, if we want to calculate the values of a gemoetric sequence where the common ratio is 1/5, we end up with {1/5, 1/25, 1/125, ...}

If we want to represent the summation of that sequence, we can do so with summation notation

Sigma notation can be viewed as calculating one final result, and can be treated as an operand in an expression. So in zybooks, when they do the expanded form, we see  sigma notation + final value of sigma calculation

closed form for arithmetic sequence is an + (d(n-1)n)/2

closed form for geometric sequence is (a(r^n - 1))/(r-1)

#### Pulling out final term

Sum of a_k from m to n == sum of a_k from m to n-1 + a_n

#### Change of Vars in Sums

New Lower Limit:
New Upper Limit
New Expression

### Induction

#### Formal Definitions
Base Case: Establishes that a theorem is true for the first value
Inductive Step: Establishes that the theorem is true for k, which means it must be true for k+1
#### 3 Laws of Recursion
A function must call itself
A function must have a base case, or a way of stopping calling itself
A function must move towards the base case

### Induction with Recurrence Relation
We can look at recursion as either a current step and a next step, or a current step and previous step. In a recurrence relation that relies on information from a previous step, n and n-1, we can instead refer to these as k+1 and k.  We're just adding 1 to both n and n-1, but using k to represent this paradigm shift. 

### Strong Induction

Base Case shows that S(n) is true for n = a through b

Inductive Step shows that S(j) is true for all values of j in the range from a through some int >= b and then proves the theorem for k+1
