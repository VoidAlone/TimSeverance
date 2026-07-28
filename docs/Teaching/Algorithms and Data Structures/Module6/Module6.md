# Trees

## Tree Basics

Trees are everywhere, they're used for filesystems, BSPs in videogames, fast underlying representations for maps, etc.

[Quake BSP](https://www.youtube.com/watch?v=wLHXn8IlAiA)

## BST

### Insert

To insert a value into a Binary Search Tree:

1. Start at the root.
2. Compare the new value to the current node.
3. If the new value is smaller, go left.
4. If the new value is larger, go right.
5. Keep comparing until you reach an empty spot.
6. Put the new value there.

Example:

- Insert `45`
- Compare to `50`: `45` is smaller, so go left.
- Compare to `30`: `45` is larger, so go right.
- The right side is empty, so insert `45` there.

### Remove

To remove a value, first find the node. Then use one of these 3 cases.

1. Leaf node (no children)
   - Just delete it.

2. One child
   - Remove the node.
   - Connect its parent directly to its child.

3. Two children
   - Find the inorder successor.
   - The inorder successor is the smallest value in the right subtree.
   - Copy that value into the node being removed.
   - Then delete the inorder successor from its old position.

Quick examples:

- If a node has no children, removing it is easy: erase it.
- If a node has one child, the child moves up into its place.
- If a node has two children, replace it with the next bigger value from the right subtree.

#### Pointers

In python, this is all as simple as reassigning the values. Managed languages like python keep track of references so if an item isn't being pointed to anymore, garbage collection will simply remove it.

In the case of C++, generally speaking, the same logic applies, we're simply going to reassign the values (pointers) but we have the added step of needing to delete the node manually since it won't be used anymore, we need to free the space occupied by the node.

Simple example: remove `5`, which has one child (`3`).

Before:

```text
    8
   /
  5
 /
3
```

Pointer idea:

```text
if current is the parent, child is left, left->left is grandchild

temp = left->left
parent->left = left->left
delete temp 
```

After:

```text
  8
 /
3
```

### Search

### Recursion

## Balancing
