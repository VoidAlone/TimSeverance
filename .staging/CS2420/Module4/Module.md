# Module 4 - Stacks, Queues, Deques, Dynamic Arrays, and Expression Notation

## Big idea

This module is about restricted-access collections.

These structures are powerful not because they hold magical data, but because they control how data is allowed to enter and leave.

That restriction is what makes them useful.

## Stacks

A stack is a LIFO structure: last in, first out.

Think of a stack of plates.
The last plate you put on top is the first plate you remove.

### Core operations

- `push`: add to the top
- `pop`: remove from the top
- `peek` or `top`: look at the top without removing it

### Common implementations

- array-based stack
- linked-list-based stack
- list-based stack in languages with built-in dynamic arrays

The ADT stays the same even if the implementation changes.

## Queues

A queue is a FIFO structure: first in, first out.

Think of a line of students waiting for food.
The first one in line should be the first one served.

### Core operations

- `enqueue`: add to the back
- `dequeue`: remove from the front

### Why queues matter

Queues are useful whenever arrival order should be respected.

Examples:

- print jobs
- task scheduling
- breadth-first style processing

## Deques

A deque is a double-ended queue.

It allows insertion and removal from both ends.

You can think of it as a structure that is more flexible than a queue and less restrictive than a stack.

Common use:

- when you need fast work at the front and back but do not care as much about the middle

## Dynamic arrays

Dynamic arrays behave like resizable arrays.

They let us keep the convenience of indexing while also allowing growth over time.

### Important idea

Appending is often cheap, but sometimes expensive.

Most appends just place an item into available capacity.
But when the underlying array fills up, a larger array must be allocated and existing items copied over.

This is why a single append can be expensive even though appending is usually fast overall.

## Expression notation

This part of the module connects data structures to parsing and evaluation.

### Infix notation

This is the notation people usually write in math:

`1 + 2`

The operator sits between the operands.

Humans like this, but computers need rules about precedence and parentheses to remove ambiguity.

### Postfix notation

Postfix, also called Reverse Polish Notation, places the operator after the operands:

`1 2 +`

This looks less natural to humans at first, but it is easier for a computer to evaluate without worrying about precedence rules.

That is the big win: postfix removes ambiguity.

## Evaluating postfix with a stack

This is one of the best examples of why stacks exist.

Example postfix expression:

`2 3 4 * +`

Process left to right:

1. Push `2`
2. Push `3`
3. Push `4`
4. See `*`, so pop `4` and `3`, compute `3 * 4 = 12`, push `12`
5. See `+`, so pop `12` and `2`, compute `2 + 12 = 14`, push `14`

Final answer: `14`

Notice how the stack naturally holds unfinished work.

## Converting infix to postfix

This is usually done with a stack of operators.

The key idea is:

- operands can go straight to the output
- operators may need to wait on the stack until it is safe to output them

Parentheses and precedence determine that timing.

You do not need to be mystified by the shunting-yard algorithm. It is mostly a careful bookkeeping system for operator order.

## Converting postfix back to infix

This can also use a stack, but now the stack stores partial expressions.

When you see an operator:

1. Pop the right expression
2. Pop the left expression
3. Combine them into a new infix expression
4. Push that expression back

This is a great reminder that data structures do not just store numbers. They can also store partial meaning.

## Why this module matters

This module often feels simpler than linked lists or trees, but it is secretly foundational.

- Stacks show up in recursion, parsing, undo systems, and expression evaluation
- Queues show up in scheduling and traversal
- Dynamic arrays show up everywhere in real software
- Restricted access patterns teach us that constraints can create power

## What to remember

- Stacks are LIFO: push, pop, peek
- Queues are FIFO: enqueue, dequeue
- Deques support both ends
- Dynamic arrays trade occasional resizing cost for flexible growth
- Postfix notation is easy for computers to evaluate with a stack
- These structures matter because they control access, not because they store exotic data
