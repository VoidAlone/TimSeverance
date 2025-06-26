### Division Algorithm (6.1)

#### HW
6.1.1(a,d)
6.1.3(c,d)

### Terms

#### Basic Terms

Counting: The process of determining the number of elements in a finite set

Combination: An unordered selection of elements in a finite set (salad or skittles or whatever)

Permutation: An ordered selection of elements in a finite set (locks are actually permutation locks, not combination locks)
#### Divides
x divides y (not to be confused with x divided by y)

iff x != 0 and y = kx
where k is an integer

So if we're looking at 10/2, then we get 2 divides 10, which is true because 2 != 0, and 2 * 5 = 10.

So, 10 is a multiple of 2, and 2 is a factor or divisor of 10.
#### Linear Combination
A linear combination is a precisely what it says. It's a combination or unordered selection of elements that produces a linear selection of elements

#### Division

Factor: A number that divides another number evenly

Parts of Division

Divisor = denominator = d
Dividend = numerator = n
Quotient = answer = q
Remainder = r

Fraction Form : dividend / divisor

### Modular Arithmetic (6.2)

This form of arithmetic concerns itself with "rings" of results. The results we get from performing the modulus operation maps to values within a limited range that are essentially {0:m-1} ie n mod m

This section largely focuses on equalities that we can use. This chapter overall will focus on properties of integers and things we can do with them, and so the types of operations that we perform on different integers can take many forms. 

(x % m + y % m) % m is equivalent to (x + y) mod m. These kinds of transformations are useful in coming sections.

### Prime Factorizations (6.3)

#### HW
6.3.1(a,c)
6.3.2(a,c)
#### Fundamental Theorem of Arithmetic (Prime Factorization)
All positive integers can be expressed as a product of prime numbers in non-decreasing order
(e.g. 120 = 2 * 2 * 2 * 3 * 5)

Prime if p > 1 and 1 and p are the only factors

Composite: An integer composed of multiple factors

Multiplicity: number of times a prime occurs in the prime factorization
#### Great Common Divisor(Denominator)
largest non-zero positive integer that is a factor for two numbers x and y

#### Least Common Multiple
If x and y are factors, what is the smallest non-zero positive number in common?

#### Euclid's Algorithm

#### Euclid's Extended Algorithm


##### Preliminary Info
Okay, so to understand what we're doing in this section, we have to disambiguate some things. This section swaps out variables to signify the same concepts, which makes it hard for non mathematicians imo.

So let's start with some simple things.

In the beginning of 6.1 we were introduced to some variables, n, d, q, and r. We're given a form for division q = n div d. r = n mod d. 

We're presented with a formula n = qd + r in 6.1.2 as the the division algorithm. We can view this formula as saying that the numerator of a fraction, is equal to the quotient times the denominator + whatever remainder. This checks out if we have some fraction 5/3. We can express this fraction as being 5 = 1 * 3 + 2. Think about long division here. If you have 3⟌5, we get 1 as our q, and 2 as our r. 

Essentially what we're doing is expressing a relationship between n, d, q, and r, and organizing them in a way the solves for any given component of this relationship. 

n = qd + r is the same form as y = mx + b. In our text book, they shift to using y and x to represent n and d, and they have a bad habit of shifting our variables around.

##### The Algorithm

Okay, so jumping back to the extended form. We have to piece together some things from across all the sections so far. If we want to find the greatest common denominator, then we use gcd(x,y). Here, x is our denominator, y is our numerator. This hint of the relationship of variables is given in the paragraph under The Extended Eucliaidean Algorithm when they specify that y = dx + r. So in other words, n = qd + r -> y = dx + r. 

We know that gcd(x,y) = gcd(y mod x, x), because the book says so. We could probably prove it but we're taking their word for it. This essentially translates to gcd(r, x). Okay, with all of that out of the way, and know what our variables mean, what they map to, and how they relate to eachother, we can know figure out how to find the coefficients for the linear combination of x and y. We'll get to why that matters in a minute.

To recap: 
gcd(x,y) = gcd(y % x, x) = gcd(r, x)
n = qd + r -> y = dx + r -> 
r = y - dx -> r = n - qd -> r = y - qx


In the example in zybooks, we use gcd(675, 210) = 15. 

gcd(675, 210) -> gcd(210 % 675, 675)
gcd(210, 675) -> gcd(675 % 210, 210) 
gcd(45, 210) -> gcd(210%45, 45) 
gcd(30, 45) -> gcd(45 % 30, 30)
gcd (15, 30) -> gcd (30 % 15, 15)
gcd(0, 15). 

See 6.5.1 for further questions. Note: 45 for instance divides cleanly into 675, but not 210. So it's not the gcd. When we reach 15, that is the gcd, or the largest non-zero, positive number that cleanly divides 675 and 210. 

When we get to the end of our euclids algorithm, we have these forms we can manipulate. Remember that we can 




