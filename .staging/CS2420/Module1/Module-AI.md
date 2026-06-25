# Module 1 - Algorithms, ADTs, Complexity, and Searching

## Big idea

This course is really about two connected questions:

1. How should we organize data?
2. How should we operate on that data?

Data structures give us ways to store and organize information. Algorithms give us step-by-step ways to do work with that information. The same job can often be done many ways, and the "best" way depends on what we care about: speed, memory, simplicity, or ease of implementation.

## Algorithms and computational problems

An algorithm is just a repeatable recipe for solving a problem.

- A cake recipe is an algorithm.
- Directions to class are an algorithm.
- A search through a list is an algorithm.

A computational problem is a problem we want a computer to solve given some input.

Example:

- Input: a list of student scores and a target score.
- Problem: determine whether the target score appears in the list.
- Possible algorithms: linear search, binary search, jump search.

## Data structures and algorithms work together

The structure you choose changes the algorithm you use.

Example: insert the value `7`

### In an array-like structure

If the spot is already occupied, items may need to shift right before `7` can be inserted.

This is why insertion in an array can be expensive.

### In a linked list

You do not shift many elements. Instead, you reconnect links.

If node `A` should come before the new node and `B` currently comes after `A`, then:

1. New node points to `B`
2. `A` points to the new node

Same goal, very different work.

## ADTs: the what, not the how

An Abstract Data Type (ADT) describes behavior without committing to one concrete implementation.

Examples:

- List
- Stack
- Queue
- Heap

When we say "use a stack," we usually mean:

- items are added with `push`
- items are removed with `pop`
- only the top is directly available
- order is LIFO: last in, first out

We are not yet saying whether that stack uses an array, a linked list, or something else.

That separation is powerful because it lets us think clearly about behavior before getting lost in implementation details.

## Complexity and efficiency

When we analyze an algorithm, we usually care about two resources:

- Time complexity: how the amount of work grows
- Space complexity: how the memory use grows

We usually describe growth in terms of input size `n`.

### Common viewpoints

- Best case: the luckiest input
- Average case: typical behavior
- Worst case: the most expensive input

In this course, worst case is often the default unless we say otherwise.

### Time vs Big O

Raw time analysis might give an expression like:

`T(n) = (n^2 - n) / 2`

Big O simplifies that growth story to:

`O(n^2)`

So Big O is not the same thing as the exact runtime formula. It is a way of describing the dominant growth behavior.

### Space vs auxiliary space

- Space complexity can include the input and extra memory
- Auxiliary space focuses on the extra memory used beyond the input itself

## A practical intuition for common growth rates

- `O(1)`: same amount of work no matter the input size
- `O(n)`: work grows in direct proportion to the input size
- `O(log n)`: work grows slowly because the problem shrinks each step
- `O(n^2)`: usually nested loops over the data
- `O(2^n)`: growth explodes quickly

### Logs and exponents intuition

One useful teaching intuition:

- Exponents are tied to repeated multiplication and explosive growth
- Logarithms are tied to repeatedly shrinking by division

That is why binary search is logarithmic: every step throws away about half the remaining search space.

That is also why the naive recursive Fibonacci algorithm is exponential: each call branches into more work.

## Recursion

Recursion means a function solves a problem by calling itself on a smaller version of that problem.

Three useful rules:

1. A recursive function must call itself
2. It must move toward a base case (stopping point)
3. It must have a base case (stopping point)

### Example idea

Factorial:

`factorial(4) = 4 * factorial(3)`

Eventually we need a base case such as:

`factorial(1) = 1`

Without a base case, recursion does not know when to stop.

Without progress toward the base case, recursion gets stuck repeating the same problem.

## Searching

### Linear search

Linear search checks items one by one.

Example: looking for `42` in

`[8, 3, 42, 19, 7]`

You read left to right until you find it or run out of list.

- Worst-case time: `O(n)`
- Space: `O(1)`

This works even when the data is unsorted.

### Binary search

Binary search only works when the data is already sorted.

Example:

`[2, 5, 9, 13, 21, 30, 44]`

If you want `21`, check the middle first.

- If middle is too small, throw away the left half
- If middle is too large, throw away the right half
- Repeat on the remaining half

Because the search space keeps getting cut in half:

- Worst-case time: `O(log n)`
- Space: often `O(1)` iteratively

### Jump search

Jump search is another technique for sorted data. Instead of checking every item, it jumps ahead in blocks and then does a smaller linear search within the right block.

You do not need to memorize it as deeply as linear and binary search, but it is a good reminder that there are many ways to trade simplicity for speed.

## A note on hard problems

Some problems are believed to be hard to solve efficiently. You may hear about NP-complete problems.

For this class, the practical takeaway is simple:

- some problems probably do not have fast exact solutions we know how to use
- in those cases, a good reasonable solution can still be useful

Do not let the perfect answer block your understanding of the useful answer.

## What to remember

- Data structures organize data; algorithms operate on it
- ADTs describe behavior without forcing one implementation
- Big O describes growth, not exact instruction counts
- Recursion needs a base case and progress toward it
- Linear search is simple and works on unsorted data
- Binary search is much faster, but only on sorted data
