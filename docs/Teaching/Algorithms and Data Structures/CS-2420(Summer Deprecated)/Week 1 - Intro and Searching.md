![[332191680_925154381855281_2204844396748739005_n.jpg]]

---

#
## Project 1 overview
Project 1 is just a simple introduction to implementing, testing, and submitting your projects. You'll do some way easy stuff, get some free points, and submit it. Seriously, it's 4 arithmetic functions and you get 100 points.
### Project 2 overview
Project 2 is the real start. We have 8 projects, but really it's 7. Every week, we'll start by going over the project requirements, loading up the idea in our minds, and then hitting the material with the project in mind.

---
## Notes for Module 1

### Intro to algorithms
Algorithms describe steps to solve some problem. Baking a cake, directions to class, or sorting lists can all use algorithms. Algorithms can be expressed in natural language, pseudocode, formal languages, whatever.

---

Computational problems are problems that can be solved with computers given some input. We use algorithms to help solve these. Some algorithms are more efficient than others, as in they take less time or space to solve a problem, or they might be inefficient but easy to implement. There are lots of different ways to solve problems, some are better than others, but most of the time they have different pros and cons.

---
### NP - Complete problem (Nondeterministic Polynomial time)
1. No efficient [[#algorithm]] has been found to solve it
2. No one has proven that an efficient algorithm is impossible to find
3. If it exists for one problem, then all NP-complete problems can be solved efficiently

If it's NP-Complete, don't focus on the perfect solution, just a good inefficient one.

---
### How Data Structures and Algorithms relate to eachother

---
#### Algorithms for data structures

Data structures are a way to organize, store, and perform operations on data.

Data structures require specific operation to be performed on their data. This means that there are algorithms specific to different data structures. 

---

For example, inserting an item into a linked list requires a very different algorithm than inserting into an array.  

Array insertion generally requires some variation of the following
1. Create new array\[size + 1\]
2. Copy items from old array to new array
3. Shift all items in the array forward from the position to be inserted
4. Insert item into now empty position

---

Linked list insertion generally requires some variation of the following

1. All nodes have a pointer to some "next node"
2. Create new object to be inserted
3. Get the object (B) pointed to by "next" data member of left node (A) and assign (B) to new object's "next" pointer
4. Set next pointer of left node to new object to be inserted. 
5. Objects are now linked 

---
#### Data structures for algorithms

Book mentions an algorithm that determines top employees, might use an array to store employee data.

---
### Abstract Data Types (ADT)

Abstraction is a really common theme that you'll see throughout your courses. It's one of the main ways that we grapple with difficult concepts and engage with "reality" as humans. In the context of ADTs, I like to think of abstraction as the scope or resolution that we view a certain problem with.

---

ADTs focus more on the what rather than the how.

---

Stacks, Heaps, Lists etc are examples of ADTs. When we talk about using a stack, an idea comes to mind of how data will be stored and handled without worrying about the concrete implementation. Stacks are FILO and so we understand that data coming in will be pushed to the bottom of a stack, and new data will pile on top of it. In order to reach information at the bottom, we have to remove stuff on top to get there.

---

What we're not thinking about is the actual programmatic implementation of how a particular stack might work. A stack can be implemented with lots of different data types. Chapter 1.7 says a specific data structure may be used to implement an ADT. See the following link as an example:

[C++ Stack Specification](https://cplusplus.com/reference/stack/stack/)

---
### Complexity

Computational Complexity can consist of time T(N) and space S(N) complexity (how fast it goes, and how much space it takes up) where N is the input. 

Algorithms are typically measured by their best, average, and worst case scenarios. Best is minimum operations, worst is max.

---

Space complexity include input data and additional memory allocation. Auxillary space complexity is just the additional memory allocation.

N represents input
k represents some constant number

---

Big O (and other notations) are not the same as time or space complexity. Time and Space complexity is a more raw calculation of a function of N. Notations are a description of the generalized behavior of Complexity given certain conditions.

---

We tend to think about problems in terms of time, like how long it takes to solve something, which is tied to how many operations you can perform. A machine typically executes one instruction at a time. So we're just trying to figure out how many instructions need to be completed, and seeing if the number of instructions scales with input.

---

Notation

|        | O                                                          | Θ                          | Ω                         |
| ------ | ---------------------------------------------------------- | -------------------------- | ------------------------- |
| Big    | Upper Bound. Worst Case. Calculations <=                   | Lower Bound. Best Case. >= | Tight Bound. Average Case |
| Little | Same as above, but without tight bounds. Don't ask me more |                            |                           |

---
### Recursion

Recursion has 3 laws:
1) A recursive function must CALL ITSELF
2) A recursive function must HAVE A WAY TO ADVANCE
3) A recursive function must HAVE A BASECASE

---

When I think about recursion, and general problems in programming, I tend to think "what gets the job done?" or "what does the real work?"

Whether you're working in some super abstract library or framework, or in the cloud, or in a recursive function, at the end of the day, some type of operation has to occur. Some work needs to get done. This is how I like to think about a base case in recursion. 

---

In terms of people, you can think about leadership. You have someone in charge (generally) and then people that do the real work. The real work is small, and usually doesn't amount to much on its own. The control of work is an abstraction that doesn't mean anything on its own. The sum of all the work of individuals yields the fruit of the combination of abstraction and real work. Advance case and base case. Without either, it doesn't work.

---


