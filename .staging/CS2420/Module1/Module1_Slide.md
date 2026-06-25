---
title: Module 1
sub_title: Algorithms, Data Structures, Abstraction, and Complexity
author: Tim Severance
theme:
  light: light
  dark: gruvbox-dark
options:
  list_item_newlines: 2
---

<!-- end_slide -->

## Module Goals

- What is an algorithm?
- How do algorithms and data structures relate?
- What is an abstraction or ADT?
- How do we measure efficiency?
- What does Big O tell us?
- What makes recursion work?

<!-- end_slide -->

## What Is an Algorithm?

An algorithm is a set of steps used to solve a problem.

- Recipes are algorithms
- Directions are algorithms
- Programs are algorithms

<!-- end_slide -->

## Input -> Process -> Output

- Input: ingredients, map data, list items
- Process: follow steps in order
- Output: cake, destination, answer

Computers do the same thing.

<!-- end_slide -->

## Algorithms Need Data

- Algorithms operate on data
- Data structures organize that data
- Different representations support different operations well

Core course question:

How should we organize data so work becomes easier?

<!-- end_slide -->

## Grocery List Intuition

A grocery list lets us:

- add items
- remove items
- search for items
- scan what is left

That is already a model for a data structure.

<!-- end_slide -->

## Activity: Scan a Real List

Take 1 minute and think about a paper grocery list.

- How do you physically scan it?
- Where do your eyes move first?
- How do you know an item is missing or present?
- What do you do with your hands if you find it?

Activity: Make a list identifying steps involved in find and removing an item.

<!-- end_slide -->

What seems simple is actually a lot of tiny steps.

- read the list
- move your eyes line by line
- compare each word to your target
- grab a pen
- check the cart
- go back to the right spot
- cross the item out

We usually talk at the high level: search, add, remove.
The actual algorithm underneath is much more granular.

<!-- end_slide -->

## Grocery List Search Example

Searching a list one item at a time is a linear scan.

```c++ {1-7|9-10|11-14} +exec +line_numbers
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> grocery_list = {"milk", "eggs", "bread", "bananas"};
    std::string target = "bread";

    for (const auto& item : grocery_list) {
        std::cout << "checking: " << item << '\n';
        if (item == target) {
            std::cout << "found it\n";
            break;
        }
    }
}
```

- Worst case: check every item
- Growth: `O(N)`

<!-- end_slide -->

## Common Data Structures

- Arrays
- Linked lists
- Dynamic arrays / vectors
- Stacks
- Heaps
- Hash tables
- Trees
- Graphs

<!-- end_slide -->

## Why Structure Matters

"A list is a list" is not quite true.

- Array-based lists and linked lists behave differently
- The same operation can cost very different amounts of work
- Implementation changes what is easy and what is expensive

<!-- end_slide -->

## Abstraction and ADTs

We often describe behavior before implementation.

- Search
- Add
- Remove

That high-level view is an abstraction.

<!-- end_slide -->

## Activity: What Does "Remove" Mean?

When we say "remove an item from a list," that sounds easy.

But what are the actual steps?

- find the item
- decide whether it is the right one
- figure out where it lives in the list
- change the list so it is no longer there

If this is paper:

- read
- scan
- grab a pen
- move back to the right line
- cross it out

If this is code, the same question still exists.

The high-level idea is simple.
The implementation details are where the real work lives.

<!-- end_slide -->

## ADT vs Data Structure

- ADT: what the structure should do
- Data structure: how it is actually implemented

Example:

- "List" is the idea
- Array list or linked list is the implementation

<!-- end_slide -->

## Measuring Efficiency

Different implementations have trade-offs.

We usually care about:

- Time
- Space

These are the main resources algorithms consume.

<!-- end_slide -->

## Complexity Functions

We describe growth relative to input size `N`.

- Time complexity: `T(N)`
- Space complexity: `S(N)`

Question:

What happens as `N` gets very large?

<!-- end_slide -->

## Big O Intuition

Big O describes worst-case growth.

Example: scanning a list

- Best case: item is near the front
- Worst case: item is at the end
- Worst-case work grows with the list size

So we write `O(N)`.

<!-- end_slide -->

## Linear vs Quadratic Growth

One introduction per student:

- `O(N)`

Every student introduces themselves to every other student:

- `O(N^2)`

Growth rate matters more than small timing details.

<!-- end_slide -->

## Quadratic Loop Example

If every student introduces themselves to every other student:

```c++ {1-6|8-9|10-14} +exec +line_numbers
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> students = {"Ana", "Ben", "Chris", "Drew"};

    for (const auto& student_a : students) {
        std::cout << "current student: " << student_a << '\n';
        for (const auto& student_b : students) {
            if (student_a != student_b) {
                std::cout << student_a << " introduces themselves to " << student_b << '\n';
            }
        }
    }
}
```

- For each student, loop through the class again
- Growth: about `N^2`

<!-- end_slide -->

## Asymptotic Thinking

- We care about growth, not exact stopwatch time
- We look for bottlenecks as input scales
- Big O is one form of asymptotic notation

Main idea:

As input grows, inefficient algorithms become painfully expensive.

<!-- end_slide -->

## Recursion

Recursion means a function solves a problem by calling itself.

A recursive function must:

1. call itself
2. have a stopping point
3. move toward that stopping point

<!-- end_slide -->

## Takeaways

- Algorithms describe how to accomplish work
- Data structures organize data for that work
- ADTs describe behavior without implementation details
- Time and space help us compare solutions
- Big O describes worst-case growth
- Recursion needs self-call, progress, and a base case
