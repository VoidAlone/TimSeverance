# Module 3 - Sorting

## Introduction

### Motivation

*Nothing is Free*

Last module, we discussed searching algorithms. We noted that they were typically pretty fast in the grand scheme of complexities. Lots of them are O(N) but some are faster, like Binary Search (log_2 N). One of the main takeaways was that the faster ones relied on one key factor: that the search space already be sorted. Some work had to be done elsewhere. Whether or not that work was done by us or someone else, it had to be done.

In this module, we cover those expensive sorting algorithms.

### Objectives

Cover a few sorting strategies.

## Algorithms

### Bubble Sort

Bubble sort is one of the simplest sorts we can do and serves as a good template for how some of the other sorts work. It's sort of the linear search of sorting algorithms. In other words, it's really basic.

```py  
for i in range(len(arr)):  
    for j in range(len(arr) - i - 1):  
        if arr[j] > arr[j + 1]:  
            arr[j], arr[j+1] = arr[j+1], arr[j]  
```  

The if statement is a swap (python has special syntax for in-place swaps).

We effectively are saying, if our current element is greater than the next element, switch them. As in \[...,4,3,...\] needs to become \[...,3,4,...\]

Then, our inner for loop is just walking through our collection, checking each element like this. If a current number is greater than the next, swap them. It also checks to make sure we haven't gone out of bounds.

The inner for loop guarantees that the largest number is going to filter up to the top. So, if we do one pass, the biggest number is going to be the last index. This means that the next pass, we should exclude the "sorted" region, by doing len - i - 1. We want to iterate len - i times so that we exclude the amount of numbers we've sorted, and then we also want to subtract 1 because we don't want to compare on the last number. We're effectively shrinking down the boundaries.

---
**Note:**  

In this example, we have effectively two partitions. A sorted, and unsorted space. The end of the array is sorted, and stays sorted. That portion grows as we pull next biggest numbers into it. The unsorted space shrinks as we move the next biggest number into the sorted space.

### Selection Sort

### Insertion Sort

### Merge Sort

### Quick Sort

### Buck Based Sorting

## Takeaways

## Extras  

- [visualgo Visualizations](https://visualgo.net/en)  
- [geeksforgeeks Visualizations](https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/)  
