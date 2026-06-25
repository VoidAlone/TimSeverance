# Module 2 - Sorting

## Big idea

Sorting is one of the most important recurring ideas in computer science. A sorted collection is easier to search, easier to reason about, and often easier to process with later algorithms.

Different sorting algorithms do the same job with very different tradeoffs.

## Two simple mental models

Many comparison sorts can be explained using one of these stories:

- Grow a sorted region
- Split the problem into parts, then solve the parts

Selection sort and insertion sort grow a sorted region.
Merge sort and quicksort split the problem into parts.

## Selection sort

### Core idea

Treat the list as two regions:

- left side is sorted
- right side is unsorted

Repeatedly find the smallest item in the unsorted region and swap it into the next spot on the left.

### Example

Start with:

`[5, 3, 8, 1]`

1. Find the smallest item in the whole list: `1`
2. Swap it into the first position
3. Now treat the first spot as sorted
4. Repeat on the remaining unsorted region

Result:

`[1, 3, 5, 8]`

### Why students often understand it quickly

It matches how a person might sort cards by repeatedly choosing the smallest remaining card.

### Complexity

- Time: `O(n^2)`
- Space: `O(1)`

Selection sort does about the same amount of scanning no matter what the input looks like.

## Insertion sort

### Core idea

Again treat the left side as sorted, but now take the next unsorted item and slide it backward until it lands in the correct position.

### Example

Start with:

`[5, 3, 8, 1]`

Think of `5` as already sorted.

- Compare `3` to `5`, swap backward -> `[3, 5, 8, 1]`
- `8` is already in the right place
- `1` moves left past `8`, `5`, and `3` -> `[1, 3, 5, 8]`

### Why it matters

Insertion sort is often better than selection sort when the list is already sorted or almost sorted.

### Complexity

- Worst-case time: `O(n^2)`
- Best case on already sorted data: `O(n)`
- Space: `O(1)`

This makes insertion sort a nice example of how input shape matters.

## Comparing selection and insertion sort

Both are simple, both are usually taught early, and both have quadratic worst-case behavior.

Useful difference:

- Selection sort keeps scanning for the next smallest item
- Insertion sort keeps repairing local order by moving one item backward

If the list is nearly sorted, insertion sort usually feels smarter.

## Quicksort

### Core idea

Choose a pivot value, then partition the list so that:

- smaller values end up on the left
- larger values end up on the right

Then quicksort each side recursively.

The left side and right side are not automatically sorted after partitioning. They are only separated relative to the pivot.

### Example intuition

Suppose the pivot value is `10`.

If the list is:

`[4, 12, 7, 15, 2, 10]`

after partitioning, all values less than or equal to `10` should be on one side and the larger ones on the other side.

That does not mean each side is already sorted. It means the problem has been broken into smaller sorting problems.

### Partition idea

Many in-place versions use two indices:

- one moving from the left
- one moving from the right

They look for values on the wrong side and swap them.

### Complexity

- Average case: `O(n log n)`
- Worst case: `O(n^2)`

The worst case happens when partitions are consistently terrible, such as one side getting almost everything.

### Teaching takeaway

Quicksort often feels "fast because it gets organized early." It aggressively separates the data into more manageable regions.

## Merge sort

### Core idea

Split the list in half again and again until every piece has size `1`.

A list of size `1` is already sorted.

Then merge those tiny sorted pieces back together in order.

### Example

`[5, 3, 8, 1]`

Split into:

- `[5, 3]` and `[8, 1]`

Split again:

- `[5] [3] [8] [1]`

Now merge sorted pairs:

- `[3, 5]`
- `[1, 8]`

Merge those:

- `[1, 3, 5, 8]`

### Complexity

- Time: `O(n log n)`
- Extra space: typically `O(n)`

### Teaching takeaway

Merge sort is a great example of recursion where the real sorting payoff happens on the way back up the recursive calls.

## Quicksort vs merge sort

Helpful simplified comparison:

- Quicksort partitions first, then recursively fixes the parts
- Merge sort splits first, then rebuilds in sorted order

Another useful classroom phrase:

- Quicksort tends to sort on the way down
- Merge sort tends to sort on the way back up

That is not the most formal statement in the world, but it is a very useful mental model.

## Stability and memory tradeoffs

At this stage, the main point is not to memorize every advanced property. The big point is that better runtime often comes with a cost.

- Simpler sorts are easier to write but slower on big inputs
- Faster sorts are usually more complex
- Some algorithms need extra memory to gain speed

There is rarely one universally best algorithm.

## What to remember

- Selection sort repeatedly chooses the smallest remaining item
- Insertion sort slides each new item into its proper place
- Both simple sorts are usually `O(n^2)`
- Quicksort uses pivots and partitioning
- Merge sort uses recursive splitting and merging
- Fast sorting often means `O(n log n)`, but the implementation story gets more complex
