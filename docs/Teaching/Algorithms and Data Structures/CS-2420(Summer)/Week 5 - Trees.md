### Operations

#### Removal

Case 1: No Children

- Return None

Case 2: 1 Child

- Return that child

Case 3: 2 Children

- Get the successor, copy the data, and then call removal on successor

Algorithm (We'll do some steps in place)

1) Traverse (visit left or right)
2) if found
	1) check left is none: return right
	2) check right is none: return left (will be none)
	3) successor is the left most descendant of the right child. Iteratively find the left most child, copy data.
	4) Set the root's right equal to the removal function's return value with the root's right as root, and the successor as the target
