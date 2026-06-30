# Module 1

In this module, our goals are to gain high level notions of algorithms, data structures, abstraction, and complexity. 

## 1 What is an algorithm?

Algorithm: A set of steps used to solve a problem.

The word algorithm is often misappropriated as a term that exclusively belongs to math or computational fields. In reality, you use algorithms on a daily basis. We can use natural algorithms to describe them too. 

If you've ever followed a recipe for baking a cake or cooking dinner, you used an algorithm. 

If you ever relied on something like Maps to get directions somewhere, you used an algorithm.

The problems that we face on a daily basis are high level abstract problems. While the results are relatively deterministic, baking a cake requires the correct combination of ingredients and steps to produce something that a person could consider tasty.

In short, you have a set of inputs like ingredients and timers, you then process those inputs in some process like baking in an oven, and you get some expected output, which is a baked cake.

We can do the same thing with machines. The question is, in relation to an algorithm, what are the ingredients? What are the functions? How do we bake a virtual cake?

## 2 Algorithms and Data Structures

Instructions, algorithms, are useful to humans because we live in a physical world with space and time. We perceive our world as a stateful, with objects and processes. While algorithms and data structures aren't unique to object oriented programming, we're going to think about the world and programming in terms of objects and how those objects communicate with eachother.

So, what are algorithms useful for? Operating on data. In computer science we can represent data in a lot of ways. There's nothing particularly sacred about any individual representation of data, but different representations offer different contraints, and as a result, lend themselves to different modes of computation.

Consider how we might organize a grocery list. Just saying the term, your mind probably goes immediately to a mental image of a notepad with some bullet points. Maybe a title "grocery list" and the obvious abilities to write more items as you think of them, and the ability to cross out items as you grab them. You also have the ability to do a quick visual scan of the list to see if you've missed anything, or see if an item is present in the list.

You know where this is going. We can map the same kinds of notions and operations that we perform as humans onto data with a computer. We can digitize that list and let a computer perform those tasks for us. We can create more complex data too. Rather than a simple word to represent a bundle of bananas, we can make a whole object that encapsulates number of bananas, cost of bananas, weight, etc. Whatever data we want. Now that we have a computer to handle everything for us, we can use this data structure, the list, to organize complex data, and then use algorithms to work on that data.

Some common data structures we'll cover in this class are:

- Arrays
- Linked Lists
- Vectors and Dynamic Arrays
- Stacks
- Heaps
- Hash Tables
- Trees
- Graphs

So why use different algorithms and data structures? Different data structures lend themselves to different algorithms, and sometimes vice versa.

## 3 Abstractions and ADTs

We already thought about a list... We thought about operations we can perform on it. We can search, we can add, we can remove. 

But, that's something that we consider to be an abstraction. We don't really know the actual implementation details. Take a second to think about those processes. If you had to write down the steps, the algorithm required to remove an item from your grocery list, what are the physical steps that you take? Consider things like, read the list, grab a pen, check the cart, go back to the part of the list that has the item, cross out the item. 

What seems so simple actually has a ton of small individual steps. Take a minute to jot down the individual physical and cognitive steps that take place, you'd be surprised how many steps you might find as you get more granular.

Back to our list. We've only considered the high level operations. Search, add, remove.

There are two main kinds of lists, and we'll cover them in the coming weeks, but there are array based lists as well as linked lists. You might think "a list is a list," but depending on how we implement the data structure, or in other words, how we organize the data, it drastically changes how we're even able to operate on that data.

This is the distinction between an Abstract Data Type, and an actual Data Structure, and its implementation.

## Take Aways

- Algorithms describe how to accomplish something  
- Abstract Data Types describe what operations are available and what behavior those operations should have  
- Data Structures implement those operations with a concrete representation  

