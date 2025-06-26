1) carefully. It's asking about operator functions. Think back to our BitArray project, and how we specifically handled overloading conversion and access operators. We defined a nested private class, BitProxy, to handle such overloads for us. While BitProxy is defined in BitArray, the functions are BitProxy's, not BitArray.

2) will be about check for 1 or 0 value in a given character. Review the lab/slides for info on that. Multiple answer with 2 correct choices

3) will ask for a single line of code. Be familiar with how to write a lambda function:
```
[](){'expression'};
```

4) Be familiar with lock_guard and how it differs from unique_guard
5) Be familiar with bit masks as were covered in the lab for P6
6) Same as above. You'll be asked to write a code snippet that does some bit operations
7) Be familiar with template parameters (there are some resources on that in the Discord)
8) Be aware of the rule of 5. You'll be asked to evaluate what a certain code snippet outputs with a variety of potential options from different constructors and assignments.
9) You'll need to write a move constructor and move assignment
10) Write a copy assignment snippet
11) Light multithreading example where you add locks to a region, similar to P7
12) Be familiar with maps, you'll have to implement a class that stores records in a map.
13) You can use references from CPlusPlus.com or cppreference.com to figure out what you need to do to implement std::transform. You'll need to be familiar with iterators. I don't care so much about perfection for this one, mostly that you have the general idea.
14) Why did we use BitProxy in P6?
15) Evaluate a problem with a given line of code from P6 related to setting a bit. 
16) Implement some functions without using explicit loops.