# Week 3

## Sorting

### Selection Sort
Sorted and unsorted regions

Looks for smallest element element in unsorted region

#### Implementation
i is the current or first index in the unsorted region. 
j is the selector index that searches for the smallest value in the unsorted region
smallest_index marks which index contains the smallest value and is initialized with i. 

if element at j is less than the element at smallest_index, smallest index is then assigned to j

We save the value at i to a variable called "temporary"
insert the value at smallest_index into index i.
We then save the value in the temporary variable to the smallest_index
Thus doing a swap.

#### Analysis
Time Complexity: $(n-1) * \frac{n}{2}$ and O(N<sup>2</sup>) (Always)

Space Complexity: O(1)

### Insertion Sort
Sorted and unsorted regions

Moves to first element in unsorted region, and backtracks through each index swapping places until it's in the right spot.

#### Implementation

i marks the current index, which is the first element in the unsorted region. (starts at 1st not to be confused with 0th)
j gets set to the current index so we can back track
If the value at j-1 is greater than the value at j then
- we save element at j to temp
- Move element from j-1 to index j
- Move value from temp to j-1
- Decrement j

Repeat until j-1 is not less than element at j
Continue outer loop

#### Analysis
Time Complexity: $(n-1) * \frac{n}{2}$ and O(N<sup>2</sup>)

Space Complexity: O(1)

Insertion sort has some benefits over selection sort. Insertion sort has a runtime of O(N) for sorted or nearly sorted inputs, as it will only have to do a comparison on each outer loop.

## Topics to Hit

### 09/07/22
- Important Dates
- Memes
- Project 1 Q&A / Review
- Sorting Algorithms
	- One Note Examples
	- Youtube video
