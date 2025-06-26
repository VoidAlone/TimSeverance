## Notes for Module 1

### Intro to algorithms
Algorithms describe steps to solve some problem. Baking a cake, directions to CS401, or sorting lists can all use algorithms. Algorithms can be expressed in natural language, pseudocode, formal languages, whatever.

Computational problems are problems that can be solved with computers given some input. We use algorithms to help solve these. Some algorithms are more efficient than others, as in they take less time or space to solve a problem, or they might be inefficient but easy to implement. There are lots of different ways to solve problems, some are better than others, but most of the time they have different pros and cons.

### NP - Complete problem (Nondeterministic Polynomial time)
1. No efficient [[#algorithm]] has been found to solve it
2. No one has proven that an efficient algorithm is impossible to find
3. If it exists for one problem, then all NP-complete problems can be solved efficiently

If it's NP-Complete, don't focus on the perfect solution, just a good inefficient one.

### How Data Structures and Algorithms relate to eachother

#### Algorithms for data structures

Data structures are a way to organize, store, and perform operations on data.

Data structures require specific operation to be performed on their data. This means that there are algorithms specific to different data structures. 

For example, inserting an item into a linked list for example requires a very different algorithm than inserting into an array.  

Array insertion generally requires some variation of the following
1. Create new array\[size + 1\]
2. Copy items from old array to new array
3. Shift all items in the array forward from the position to be inserted
4. Insert item into now empty position

Linked list insertion generally requires some variation of the following

1. Nodes contain pointers to next node
2. Create new object to be inserted
3. Get "next" pointer of left node and assign to new object's "next" pointer
4. Set next pointer of left node to new object to be inserted. 
5. Objects are now linked 

#### Data structures for algorithms

Book mentions an algorithm that determines top employees, might use an array to store employee data.

### Abstract Data Types (ADT)

ADTs focus more on the what rather than the how.

Stacks, Heaps, Lists etc are examples of ADTs. When we talk about using a stack, an idea comes to mind of how data will be stored and handled without worrying about the concrete implementation. Stacks are FILO and so we understand that data coming in will be pushed to the bottom of a stack, and new data will pile on top of it. In order to reach information at the bottom, we have to remove stuff on top to get there.

What we're not thinking about is the actual programmatic implementation of how a particular stack might work. A stack can be implemented with lots of different data types.

https://cplusplus.com/reference/stack/stack/
### Efficiency

Computational Complexity can consist of time T(N) and space S(N) complexity (how fast it goes, and how much space it takes up) where N is the input. 

Algorithms are typically measured by their best, average, and worst case scenarios. Best is minimum operations, worst is max.

Space complexity include input data and additional memory allocation. Auxillary space complexity is just the additional memory allocation.

N represents input
k represents some constant number





### Topics to hit
#### 08/24/22
1. Memes / Pictures
2. Make sure everyone has zybooks, discord, python + modules
3. Questions
4. Jupyter Notebooks
5. Recursion / Compilation
6. Fibonacci sequence
7. BigOFib
8. Space and Time Complexity
9. Freestyle Coding (What did I mean by this? Getting better at coding? Coding on the fly? The dangers of not having a set plan? The benefits of flying freely and just experimenting?)
10. Orders of Ignorance / Take this Fish
11. Nothing is real. It's all made up. Nothing is sacred. We create structures to make sense of the world around us. Different paradigms make sense in different contexts. Don't lock yourself into one way of thinking.
12. Recursion, Classes, dunder/magic methods

