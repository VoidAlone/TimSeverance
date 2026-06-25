# Module 1

In this module, our goals are to gain high level notions of algorithms, data structures, abstraction, and complexity. 

## 1 What is an algorithm?

Algorithm: A set of steps used to solve a problem.

The world algorithm is often misappropriated as a term that exclusively belongs to math or computational fields. In reality, you use algorithms on a daily basis. We can use natural algorithms to describe them too. 

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

## 4 Measuring efficiency

Now we know that there are different algorithms to be used depending on how our data is organized. As a result, we may find that depending on our implementation, some algorithms are really fast or efficient, while others are less so. 

Let's consider adding an element to an array-based list vs a linked list.

What factors were important in relation to adding an item to the different types of lists? We had the space occupied by the existing data structure in memory, we had the amount of items in the list, we had auxillary space for copy operations, etc. In short, there were many inputs in our function.

We can see that there are pros and cons to different implementations. Since we're using machines to automate work for us, we need to decide which algorithms, and which data structures are right for the job. How do we do this? What metrics are useful to us as people?

Well, since we're 3D beings, the most important things to us are time and space. There's another element that's significant in the world and that's work, but we'll talk about that later. 

We have a notation to describe these important artifacts.

## 5 Complexity Functions

You may have heard of Big O notation. If you haven't, don't worry. Big O notation is what we use to describe the complexity of a function, or in other words, how it performs. Specifically, we use Big O notation to describe how it performs in relation to Time, ie T(N), and Space, ie S(N). These functions describe the general behavior of how long a function takes to finish in relation to its input, and how much space a function uses in relation to its input.

If we want to insert an item into a list, and our list is 10 units long, how long does it take to find the right spot to put it? If our list is 1'000'000 items long, how long does it take for us to find the right spot to put it?

In the easiest scenario, maybe we're sorting alphebetically, and our word starts with A. So, we'll likely put it towards the start of the list. In the best case scenario, it's the very first word to add. We don't have to look very long. Now imagine we want to put it somewhere in the middle, it'll probably take a lot longer to find it if the list is 1'000'000 words long, as opposed to 10 words long. In the worst case scenario, we have to scan the entire list all the way to the very last word.[^1]

So, how do we describe this behavior? How do we say "well, the more input you have, the longer it can take in different scenarios." We use Complexity Functions, like Big O notation.

Big O refers to the worst case scenario for something. In our grocery list example, there's a 1:1 correspondence in the number of checks we have to do in relation to the number of items present in the list. Big O notation says that "In the worst case scenario, if you have N items, you have to go all the way to the end of the list to do your insertion." So, we can denote this as O(N). Let's think of another example. In other words, the amount of time it takes in the worst case, is directly proportional to the amount of elements in your list (N).

Let's think of another example. Imagine if rather than introducing yourself to the entire class at once, let's say instead I had you all introduce yourselves one on one. So now, every single one of you is introducing yourselves to every single one of you. In other words, For each student in class, for every other student in class, introduce yourself. We now have N^2 introductions happening in our class. This is horribly inefficient. 

Now here's the important part. In our case, this knowledge that we'd have N students squared introducing themselves... if I actually wanted you all to get to know each other one on one, I can use this information to determine how long each introduction should be in accordance with how much time we have, and how much I want to socially exhaust you all.

In this O(N^2) scenario, 30 second introductions amounts to 2.1 hours roughly. If I had you all make 5 minute presentations, we're now talking about an assignment that will be more appropriate on the scale of a week. Instead, it's better to just have you all introduce yourself to the class. In other words, for each student in class, introduce yourself. This is now an O(N) operation.


## 6 Asymptotic Notation

The key thing here is that growth is the imporant part. As our operations scale in complexity, it affects how long it'll take to get something done. In introducing yourselves, it doesn't really matter exactly how long I make your introductions. What does matter is that it's a massive pain to introduce yourself to each individual person in the class, and it's an even bigger pain as I wait for you all to finish. What's less painful, is for you to sit in your chair, and say your intro once.

So, we don't care a ton about measuring raw speed. Raw speed is important, but, the way we optimize is by determining where certain bottlenecks are, or in otherwords, finding inefficient algorithms, and making them as efficient as possible.

The key here is that Big O notation is a subset of asymptotic notation. In short, we use a graph, and then we have a line that describes some boundary, or asymptote, and say given an input, as we approach the limit where the input is infinite, we get close to that boundary or asymptote. So, if our input is Linear like the grocery list, then the behavior of the graph in the worst case has an asymptote that is linear. If we have all of you introduce yourselves individually, the behavior of the graph is quadratic. 

There are many types of notations we can use, big o, small o, big theta, etc, but the ones we're most often concerned with are the worst case. See: murphy's law, scout motto, etc.

## 7 Recursion

Recursion is a concept that we'll spend more time with as our algorithms and data structures call for it. Recursion is generally a concept that invokes fear, dread, and worry in computer science students. We'll keep it simple for now, remembering the three rules of recursion that will make it easy grapple with going forward. 

A recursive function must:
1) call itself (recurse)
2) have a stopping point (base case)
3) advance to a stopping point (advance case)

Recursion requires practice and a degree of intution. As we deal more with algorithms and data structures that call for recursion, we'll expand that intuition.

## Take Aways

Algorithms describe how to accomplish something
Abstract Data Types describe how to represent data 
Data Structures implement that behavior
Functions can be described in terms of time and space relative to their inputs.
Big O notation describes the worst case growth rate for a function
Recursion has 3 rules that you must memorize.

## Footnotes

[^1]: A distinction here, is that humans have some added cognitive tricks to make this work easier, but it can still be exhausting. A trade-off with traditional computers, is they're dumb. They can only follow instructions exactly. The trade-off is that they don't get mentally fatigued. So, the balancing act is offloading the higher level cognition to humans, and then offloading the actual work to machines. We can embed our cognition in the form of highly complex conditions in an algorithm, but the computer just follows what we told it to do, exactly.
