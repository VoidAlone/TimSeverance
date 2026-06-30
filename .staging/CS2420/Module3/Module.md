# Module 3 - Linked Lists

## Big idea

A linked list stores data as a chain of nodes instead of one big contiguous block of memory.

Each node stores:

- some data
- a reference or pointer to another node

This changes how insertion, removal, traversal, and indexing behave compared to arrays.

## Why linked lists exist

Arrays are great when you want fast indexing.

Linked lists are great when you want flexible insertion and removal without shifting many elements.

The tradeoff is important:

- arrays are friendly to direct indexing
- linked lists are friendly to relinking

## Singly linked lists

In a singly linked list, each node points to the next node.

Example shape:

`[A] -> [B] -> [C] -> None`

If you are at `A`, you can reach `B`, then `C`.
But from `B`, you cannot directly move back to `A` unless you stored that information somewhere else.

## Doubly linked lists

In a doubly linked list, each node has two links:

- `next`
- `prev`

Example shape:

`None <- [A] <-> [B] <-> [C] -> None`

This costs more memory per node, but it makes some operations easier because you can move in both directions.

## Traversal

Traversal means visiting nodes one by one.

In a singly linked list, traversal usually starts at the head and keeps following `next` until `None`.

### Iterative traversal

This is often the most direct approach:

1. Start at `head`
2. Process the current node
3. Move to `current.next`
4. Stop at `None`

### Recursive traversal

Recursion can also walk the list one node at a time, but it uses extra call stack space.

## Insertion

### Insert at front

Very common and very cheap.

If the new node is `N` and current head is `H`:

1. `N.next = H`
2. `head = N`

### Insert in the middle

Suppose you want to insert `N` between `A` and `B`.

1. `N.next = B`
2. `A.next = N`

That is the core linked-list move: reconnect the chain.

### Insert in sorted order

If the list must stay sorted, walk until you find the correct location, then relink.

This is a good example of a data structure operation being partly about traversal and partly about pointer updates.

## Removal

To remove a node, you usually need to bypass it.

If the chain is:

`A -> B -> C`

and you want to remove `B`, then set:

`A.next = C`

In languages with manual memory management, you also need to free or delete the removed node after unlinking it.

## Searching

Linked lists do not support fast direct indexing the way arrays do.

To find a value, you typically have to walk node by node.

- Search time: `O(n)`
- Access by index: `O(n)`

That is one of the biggest reasons arrays and linked lists feel so different in practice.

## Sorting linked lists

You can sort linked lists, but some array-based strategies do not transfer cleanly.

Why?

- arrays make random access easy
- linked lists make sequential access easy

So a sorting algorithm that loves jumping to arbitrary indices may feel awkward on a linked list.

Merge sort is often a natural fit for linked lists because linked lists are already good at splitting and reconnecting chains.

## Classes, interfaces, and organization

Linked lists are often where students really begin writing data structures as classes.

That means this module is also about software design ideas:

- organizing responsibilities across classes
- separating public behavior from internal implementation
- exposing operations like `append`, `remove`, `find`, and iteration

## Iterators and the iterator pattern

An iterator gives us a standard way to move through a collection without exposing every internal detail.

This matters because users of the list should usually care about:

- what values are in the list
- how to visit them one at a time

They should not always need to manually manage raw node pointers.

In Python, this connects to methods like `__iter__` and `__next__`.
In C++, this connects to iterator objects and traversal conventions.

## Magic methods and special behavior

In Python, classes can implement special methods to behave more naturally.

Examples:

- `__init__` for construction
- `__str__` for readable output
- `__iter__` and `__next__` for iteration

These methods are not unique to linked lists, but linked lists are a great place to practice them because they make your custom structure feel like a real container.

## What to remember

- A linked list is a chain of nodes
- Singly linked lists move forward; doubly linked lists move both ways
- Insertions and removals are about relinking nodes
- Searching and indexing are usually linear time
- Iterators help users traverse collections cleanly
- The implementation details matter more here than they did with abstract containers like lists and stacks
