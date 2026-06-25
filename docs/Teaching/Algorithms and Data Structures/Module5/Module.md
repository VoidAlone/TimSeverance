# Module 5 - Trees

## Big idea

A tree is a hierarchical data structure made of nodes connected by edges.

Unlike a list, which is mostly linear, a tree branches.
That branching lets us organize data in ways that support efficient search and many real-world models.

Examples:

- file systems
- parse trees and abstract syntax trees
- decision structures

## Basic vocabulary

- Root: the top node
- Parent: a node with children below it
- Child: a node directly below another node
- Leaf: a node with no children
- Internal node: a node with at least one child
- Depth: how far a node is from the root
- Height: how tall the tree or subtree is
- Level: nodes at the same depth

These words matter because tree algorithms are easiest to understand when you can describe shape clearly.

## Binary trees

A binary tree is a tree where each node has at most two children:

- left child
- right child

Not every binary tree is ordered. Binary just means "at most two children."

## Binary search trees (BSTs)

A binary search tree adds an ordering rule:

- values smaller than a node go left
- values larger than or equal to a node go right

That rule is what makes searching efficient.

### Search in a BST

Start at the root.

- If the target equals the current node, stop
- If the target is smaller, go left
- If the target is larger, go right

Repeat until found or until you hit `null`.

### Why BSTs can be fast

If the tree stays reasonably balanced, each step throws away a large chunk of possibilities.

That gives us a search time around `O(log n)`.

### Why BSTs can become slow

If values are inserted in a bad order, the tree can become lopsided and start looking like a linked list.

Then operations degrade toward `O(n)`.

That is why balance matters.

## BST insertion

Insertion follows the same left-or-right logic as searching.

Walk down the tree until you find an empty child position where the new node belongs, then place it there.

Simple in idea, but the resulting shape depends heavily on insertion order.

## BST removal

Removal has three classic cases.

### Case 1: node has no children

Remove it directly.

### Case 2: node has one child

Connect the parent directly to that child.

### Case 3: node has two children

This is the interesting one.

A common strategy is:

1. Find the inorder successor, usually the leftmost node in the right subtree
2. Copy that value into the node being removed
3. Recursively remove the successor node from its old location

This keeps the BST ordering rule intact.

## Tree shape words

These terms describe structure:

- Full: every node has either 0 or 2 children
- Complete: every level is full except maybe the last, which is filled from left to right
- Perfect: every internal node has 2 children and all leaves are at the same depth

Do not panic over the vocabulary. The point is to become more precise when talking about tree shape.

## AVL trees

AVL trees are self-balancing binary search trees.

They use a balance factor to detect when one side of a node becomes too heavy.

The balance factor is based on subtree heights.

When the balance gets too far off, the tree repairs itself with rotations.

### Rotation intuition

Rotation is a local rearrangement that preserves BST ordering while improving balance.

Main cases:

- Left-Left -> right rotation
- Right-Right -> left rotation
- Left-Right -> left-right rotation
- Right-Left -> right-left rotation

The exact pointer details can feel fiddly, but the big picture is simple: rotate to keep the tree from collapsing into a line.

## Red-black trees

Red-black trees are another self-balancing BST family.

They use coloring rules plus rotations to keep the tree balanced enough for efficient operations.

For this course level, the most important takeaway is not every balancing strategy is the same. Different trees enforce balance differently.

## Heaps and priority queues

Heaps are trees designed around priority rather than full search ordering.

A priority queue uses a heap so that the most important item can be accessed efficiently.

This is a good reminder that "tree" is a broad category, not one single behavior.

## Traversal

Trees can be traversed recursively because each subtree is itself a tree.

Common recursive traversals include:

- preorder
- inorder
- postorder

For BSTs, inorder traversal is especially important because it visits values in sorted order.

## What to remember

- Trees organize data hierarchically
- BSTs use left/right ordering to support efficient search
- Bad shape can ruin BST performance
- Removal has three cases, with the two-child case being the most subtle
- AVL and red-black trees exist to keep trees balanced
- Traversal order changes what information you get from the tree
