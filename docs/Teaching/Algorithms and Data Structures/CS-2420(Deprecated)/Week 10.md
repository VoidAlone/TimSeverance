## Trees

### 10/24/22

#### Topics To Cover
- Keywords
- Wrap up iterator class / mention generators
- Traversal of a List
- Trees
- Traversal of a Tree

#### Key Words
- Leaf
	- A node with no children.
- Internal node
	- A node with a least one child
- Parent
	- A node with nodes 
- Root
	- Top node that has no parents. The start.
- Level
	- Nodes with the same depth are on the same level
- Depth
	- The number of edges from the root to a given node. Root has depth 0
- Height
	- Overall depth of the tree
- Full
	- If every node contains 0 or 2 children
- Complete 
	- If all levels contain all possible nodes and all nodes in the last level are as far left as possible
- Perfect
	- If all internal nodes have 2 children and all leaves are at the same level

### 10/26/22

#### Application of Trees
- File System
- BSPs for rendering
- Parsing, AST, Code Generation

#### Binary Search Tree

Binary search trees can be poorly optimized and end up just looking like a linked list. If this is the case, then the benefits of being a binary search tree go out the window. Rather than being O(log(N)) it becomes O(N). In order to maintain optimal insertion, removal, and search times of O(log(N)), we have to balance our BST.

- Search
	1.  Check if NewNode.Value is LT or GTET CurrentNode.Value
	2.  If CurrentNode.Left / Right is not Null -> CurrentNode = CurrentNode.Left / Right
- Insertion
	1. NewNode < CurrentNode and CurrentNode.Left is Null -> CurrentNode.Left = NewNode
	2. NewNode >= CurrentNode and CurrentNode.Right is Null ->CurrentNode.Right = NewNode
- Removal
	1. Leaf ->Current.Parent.{Left / Right} = Null
	2. Node with 1 Leaf -> Current.Parent.{Left / Right} = Current.{Left / Right}
	3. Node with 2 -> Find leftmost child of right subtree, copy successor to current node, recursively remove the successor

#### AVL Tree

AVL stands for Adelson-Velsky and Landis who created it. First self balancing tree to be invented.

These trees have a "balance factor" which is used to calculate whether or not the tree is properly balanced. A balance factor is calculated by determing the height of the subtrees of a given node and subtracting those heights. Imagine Node1 has two children. The factor for a subtree is the height (where the first child counts as height = 0). If a left or right subtree does not exist, its factor is -1. For example, if a root has a child with a grandchild, then the left subtree has a factor of 1, and subsequent descendents will increase that factor.

AVL trees don't always have a perfectly minimal height, but their height is never worse than 1.5x the minimum height.

- Rotation
	- In order to actually make good use of insertion, we need to reorder the tree so that it's balanced. Rotation is a local rearrangement of a BST the keeps the proper order.
		Left-Left (Left node to Left node) Factor (2, 1) -> Solved with Right Rotation
		Right-Right (Right node to Right node) Factor (-2,-1) -> Solved with Left Rotation
		Left-Right Factor(2,-1) (Left Node to Right Node) -> Solved with Left Right Rotation
		Right-Left Factor (-2, 1) (Right Node to Left Node) -> Solved with Right Left Rotation
- Insertion
- Removal
- 

#### Red Black Trees

So named because of the ink the creators used when designating nodes

- Rules
- Rotation
- Insertion
- Removal


#### Heap

#### Priority Queue

#### Treap






