# Module 4 - Linked Lists

## Introduction

### Motivation

Among the data structures, the list is one of the most commonly used. The list is a structure that we naturally use on a regular basis in our lives: shopping lists, class rosters, to-do lists, and more. Naturally, we tend to use real-world concepts as abstractions for complicated computational problems. The list is among the most primitive and useful data structures for this purpose.

### Objectives

- Cover array-based lists  
- Cover linked lists  

## Arrays and Array-based Lists

This type of list is very basic and like anything, comes with strong pros and cons.

By nature of how arrays work, access time is O(1) as there is no seeking required. You have a base address + offset for all locations in the array which makes it very fast to access.

Conversely, inserting an element requires shifting all elements in the array which ends up giving you O(n) move operations for an insert.

Growing an array can also result in wasted memory since you have to preallocate memory ahead of time for an array, and moving elements to the new array is always O(n).

## Objects and Pointers

In this section we'll start to see the benefit of objects.

Object orientation is not just about objects directly. Encapsulation is one of its core ideas: bundling related data and behavior together while hiding implementation details. See Extras below for more information.

## Linked Lists

### Linked List Nodes

A linked list is built from nodes. Each node stores data along with a link to another node. In a singly linked list, each node points to the next node in the sequence.

This means the list does not need to occupy one contiguous block of memory like an array. Each node can live anywhere in memory as long as the links connect the structure together.

### Linked List ADT

At the abstract data type level, a linked list supports many of the same operations as an array-based list:

- Insert
- Remove
- Search
- Traverse

The difference is in the cost of those operations. A linked list is usually very good at inserting or removing near a known position, but slower at direct access because it must follow links from node to node.

Additionally, the Linked List structure is responsible for managing the underlying implementation. The linked list is built from nodes, but an end user doesn't necessarily need to know all the intricate details of managing those nodes. They expect to be able to use methods like insert and remove without worrying about the details. So the Linked List acts as a wrapper around the underlying structure, and provides a sort of interface for interacting with it.

### Algorithms

Common linked list algorithms rely on pointer manipulation.

#### Insertion

To insert a new node, first move to the node just before the target position. Then point the new node at the rest of the list, and finally reconnect the previous node to the new node.

```text
Before:
head
 |
 v
[A|*] -> [B|*] -> [D|null]

Insert C between B and D:

Step 1: new node points forward
[C|*] -----> [D|null]

Step 2: previous node reconnects
head
 |
 v
[A|*] -> [B|*] -> [C|*] -> [D|null]
```

#### Removal

To remove a node, move to the node just before it. Then skip over the node being removed by reconnecting the previous node directly to the removed node's `next`.

```text
Before:
head
 |
 v
[A|*] -> [B|*] -> [C|*] -> [D|null]

Remove C:

Step 1: identify the node before C
[B|*] -> [C|*] -> [D|null]

Step 2: bypass C
head
 |
 v
[A|*] -> [B|*] ------------> [D|null]

After:
head
 |
 v
[A|*] -> [B|*] -> [D|null]
```

#### Search

To search a linked list, start at the head and follow `next` one node at a time until the value is found or the list ends.

```text
Searching for C:

head
 |
 v
[A|*] -> [B|*] -> [C|*] -> [D|null]
  ^        ^        ^
 check    check    found
```

## Takeaways

- Arrays provide fast indexed access.
- Array inserts and deletes are often expensive because elements must shift.
- Linked lists avoid shifting elements during many inserts and deletes.
- Linked lists trade away fast random access.

## Extras

[Alan Kay Object Orientation](https://userpage.fu-berlin.de/~ram/pub/pub_jf47ht81Ht/doc_kay_oop_en)

[Alan Kay on Messaging](https://wiki.c2.com/?AlanKayOnMessaging)

[Alan Kay OOPSLA 97](https://tinlizzie.org/IA/index.php/Alan_Kay_at_OOPSLA_1997:_The_Computer_Revolution_has_not_Happened_Yet)
