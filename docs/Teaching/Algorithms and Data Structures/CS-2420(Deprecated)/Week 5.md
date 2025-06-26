## Topics to hit

- Review P2 instructions
- Algorithms are recipes
	- more than one way to do it
	- experience will help you synthesize recipes on your own
- [John von Neumann](https://en.wikipedia.org/wiki/John_von_Neumann) created merge sort. Dude was a literal genius... mathemetician, physicist, engineer, computer scientist. Don't beat yourself up for not being able to perfectly come up with the idea on your own in your second year of CS
- Lots of implementations of sorts that all have pros and cons. There's rarely a "best" way to do anything
- Memory implementations

### How to hit the project
- Set up all your defs first
- Get is_sorted written first
- knock out selection and insertion sort
- tackle quicksort and mergesort

### [Quicksort](https://en.wikipedia.org/wiki/Quicksort)

https://www.geeksforgeeks.org/quick-sort/

all numbers less than or equal should be in left partition
all numbers greater than or equal should be in right partition
low index crawls towards end, high index crawls towards beginning
as these indices moves, they will determine the ends and beginnings of the partitions which aren't always equal size
left index will travel right until it hits a value that shouldn't be in the low partition, if the right index finds something that shouldn't be in the right partition, they swap, otherwise, they meet in the middle which indicates that all the elements are in the correct partitions

As we move elements into their correct partitions, eventually we get to a partition of size two. The elements will be swapped into low and high partitions, and split again. At this point, the partitions will be size 1 and we're done. However, at this point, because they were split into low and high, the elements are now properly in order. Recursively we move up towards the top where everything will end up sorted by nature of just moving partitions of size 2 into high and low. we're going until all partitions are size 1, so we just loop until that happens. right_partition_begin can also be called the low_index. It starts at the left and works its way to the right and eventually becomes the beginning of the right partition. The opposite happens for left_partition_end. It starts at the end, and works its way to the left and ultimately becomes the ending of the left partition.

### [Mergesort](https://en.wikipedia.org/wiki/Merge_sort)

https://www.geeksforgeeks.org/merge-sort/

Creates a list and splits it in half. Both halves are both recursively split until we reach a list of size 1 or 0. We can handle this in a few ways, but zybooks does it where we keep track of which regions we're in, and reorder the regions so the order doesn't get messed up.

Once the lists are ready to be merged, we walk one at a time in each list and insert the least item into the current index and then move forward.

If we get to the end of a list, we just insert the rest of the elements from the remaining list into the temp.

We then copy all of the items into the original in the region we're in.

### 09/21/22

Merge Sort and Quicksort work very similar

Merge sort Recursively splits, and then sorts on the way back up

Quicksort splits and partially sorts on the way down

Both Algorithms essentially partition their lists

Recursive quicksort can be faster than recursive mergesort with the use of tail recursion, which can allow the compiler to optimize and minimize stack depth.

Iterative versions can be used for both

Zybooks mergesort copies the list, and then inserts the sorted list into a region of the original list. We don't really care that it's overriding because as we recursively split, if we're keeping track of which zones we're splitting into with i,j,k, we'll never override information we need.

