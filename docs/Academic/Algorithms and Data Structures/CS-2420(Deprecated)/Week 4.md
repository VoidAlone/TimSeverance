## Topics to hit

### 09/12/22

pytest
for loops
difficulties with the project
how can I help
selection sort
insertion sort

### 09/14/22

Arrays are just dedicated start and end points in memory. So it doesn't matter necessarily matter if we virtually "split" the array, or "split" the array in memory, because at the end of the day, they're both just different levels of abstraction.

Quick and Merge sorts both use a main function, with a helper function that does most of the heavy lifting.

#### Quick Sort
A collection is sorted when all elements to the left of a selected item value is less than or equal to that item, and when all elements to the right are greater than or equal to that item.

Splits the sort space with a pivot point and recursively sorts.  

Pivot point can be any value in the list.

Zybooks chooses the pivot to be the value at the midpoint of the array. Partions are left and right halves.

We have to move all values smaller than the pivot point value into one partition, and all greater or equal values to the other partition.

The trick is that the values in the low and high partition aren't sorted, it's just that they are less than or equal to or greater than or equal to the value that is selected as partition value

Quicksort uses a helper function, called Partition. Partition gets all the elements less than the pivot point to the left, and all the elements greater than the pivot point on the right. This may include swapping the pivot value to some index other than middle, but that doesn't matter, because all that we care about is making sure values ltet are on the left, and values gtet are on the right.

low and high, i and j move towards the middle swapping values if needed.

Quicksort just calls Partition, where we move low values to the left partition, and high values to the right partition, and then recursively calls itself with low and high partitions until the partitions are only size 0 or 1.

Time Complexity: $(n+1) * \frac{n}{2}$ and O(N<sup>2</sup>)

with N-1 levels for partitioning.

Average case is O(N log N) (log base 2, but the base doesn't affect the behavior of the graph)


#### Merge Sort

Split down the middle recursively until you get lists of size 1

Lists of size 1 are already sorted

We use index i for low point of left side, j for high point of left side, j+1 for low point of right side, k for high point of right side

We then compare least values from left and right lists, and add smallest value to new index in our master array. 

Time Complexity 
