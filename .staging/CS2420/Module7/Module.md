# Module 7 - Graphs and Topological Sort

## Big idea

Graphs let us model relationships.

If trees are good for hierarchy, graphs are good for networks.

Examples:

- roads between cities
- friendships in a social network
- dependencies between programming tasks
- course prerequisites

## Core vocabulary

- Vertex or node: an item in the graph
- Edge: a connection between two nodes
- Directed edge: connection has a direction
- Undirected edge: connection works both ways
- Path: a route through edges
- Cycle: a path that loops back to where it started

## Directed acyclic graphs (DAGs)

A DAG is a directed acyclic graph.

That means:

- edges have direction
- there are no cycles

These are especially useful when one thing must happen before another.

Examples:

- build systems
- project dependencies
- ETL pipelines
- prerequisite chains

## Topological sort

Topological sort produces an ordering of the nodes in a DAG so that every dependency appears before whatever depends on it.

In other words:

If there is an edge from `X` to `Y`, then `X` must appear before `Y` in the ordering.

### Why this matters

Suppose these tasks exist:

- write code
- compile
- run tests
- deploy

You cannot deploy before writing code.
You usually should not run tests before compiling.

Topological sort gives an order that respects those dependency rules.

## A simple example

If we have edges:

- `A -> C`
- `B -> C`
- `C -> D`

Then a valid topological order might be:

`A, B, C, D`

or

`B, A, C, D`

Notice that multiple correct answers can exist.

The important part is that `C` comes after both `A` and `B`, and `D` comes after `C`.

## Important restriction

Topological sort only works on graphs with no directed cycles.

Why?

Because a cycle creates impossible dependency logic.

Example:

- `A` must come before `B`
- `B` must come before `C`
- `C` must come before `A`

That cannot be satisfied.

## Teaching intuition

One of the most useful ways to think about a topological sort is:

"Give me a legal order to do the work."

That makes it much easier to connect the graph idea to real tasks students already understand.

## What to remember

- Graphs model relationships, not just sequences or hierarchies
- DAGs model dependency systems
- Topological sort gives a valid dependency-respecting order
- Multiple topological orders may exist
- Cycles break topological sorting because they create impossible prerequisites
