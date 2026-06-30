# Module 2

## 1 Measuring efficiency

Now we know that there are different algorithms to be used depending on how our data is organized. As a result, we may find that depending on our implementation, some algorithms are really fast or efficient, while others are less so. 

---

Activity: Let's consider adding an element to an array-based list vs a linked list.

--- 

What factors were important in relation to adding an item to the different types of lists? We had the space occupied by the existing data structure in memory, we had the amount of items in the list, we had auxillary space for copy operations, etc. In short, there were many inputs in our function.

We can see that there are pros and cons to different implementations. Since we're using machines to automate work for us, we need to decide which algorithms, and which data structures are right for the job. How do we do this? What metrics are useful to us as people?

Well, since we're 3D beings, the most important things to us are time and space. There's another element that's significant in the world and that's work, but we'll talk about that later. 

We have a notation to describe these important artifacts.

## 2 Complexity Functions

You may have heard of Big O notation. If you haven't, don't worry. Big O notation is what we use to describe the complexity of a function, or in other words, how it performs. Specifically, we use Big O notation to describe how it performs in relation to Time, ie T(N), and Space, ie S(N). These functions describe the general behavior of how long a function takes to finish in relation to its input, and how much space a function uses in relation to its input.

If we want to insert an item into a list, and our list is 10 units long, how long does it take to find the right spot to put it? If our list is 1'000'000 items long, how long does it take for us to find the right spot to put it?

In the easiest scenario, maybe we're sorting alphebetically, and our word starts with A. So, we'll likely put it towards the start of the list. In the best case scenario, it's the very first word to add. We don't have to look very long. Now imagine we want to put it somewhere in the middle, it'll probably take a lot longer to find it if the list is 1'000'000 words long, as opposed to 10 words long. In the worst case scenario, we have to scan the entire list all the way to the very last word.[^1]

So, how do we describe this behavior? How do we say "well, the more input you have, the longer it can take in different scenarios." We use Complexity Functions, like Big O notation.

Big O is commonly used to talk about worst case growth, but more generally it describes an asymptotic upper bound on growth. In our grocery list example, there's a 1:1 correspondence in the number of checks we may have to do in relation to the number of items present in the list. Big O notation says that "as the input grows, the work grows no faster than this rate." So, if in the worst case we may have to scan all N items, we can denote that as O(N). In other words, the amount of time it takes grows proportionally with the amount of elements in your list (N).

Let's think of another example. Imagine if rather than introducing yourself to the entire class at once, let's say instead I had you all introduce yourselves one on one. So now, every single one of you is introducing yourselves to every single one of you. In other words, For each student in class, for every other student in class, introduce yourself. We now have N^2 introductions happening in our class. This is horribly inefficient. 

Now here's the important part. In our case, this knowledge that we'd have N students squared introducing themselves... if I actually wanted you all to get to know each other one on one, I can use this information to determine how long each introduction should be in accordance with how much time we have, and how much I want to socially exhaust you all.

In this O(N^2) scenario, 30 second introductions amounts to 2.1 hours roughly. If I had you all make 5 minute presentations, we're now talking about an assignment that will be more appropriate on the scale of a week. Instead, it's better to just have you all introduce yourself to the class. In other words, for each student in class, introduce yourself. This is now an O(N) operation.


## 3 Asymptotic Notation

The key thing here is that growth is the important part. As our operations scale in complexity, it affects how long it'll take to get something done. In introducing yourselves, it doesn't really matter exactly how long I make your introductions. What does matter is that it's a massive pain to introduce yourself to each individual person in the class, and it's an even bigger pain as I wait for you all to finish. What's less painful, is for you to sit in your chair, and say your intro once.

So, we don't care a ton about measuring raw speed. Raw speed is important, but the way we optimize is by determining where certain bottlenecks are, or in other words, finding inefficient algorithms, and making them as efficient as possible.

The key here is that Big O notation is one kind of asymptotic notation. The main idea is that we care about how a function grows as the input becomes very large. Rather than focusing on exact runtimes, we describe the overall growth rate. So, if the work grows roughly in proportion to the input size, we call it linear. If the work grows roughly with the square of the input size, we call it quadratic.

There are many types of notations we can use, big O, small o, big Theta, etc, but the ones we're most often concerned with in an introductory setting are upper bounds and worst case reasoning.

## 4 Know thy Complexities!

[Big O Cheatsheet](https://www.bigocheatsheet.com/)

## 5 Recursion

Recursion is a concept that we'll spend more time with as our algorithms and data structures call for it. Recursion is generally a concept that invokes fear, dread, and worry in computer science students. We'll keep it simple for now, remembering the three rules of recursion that will make it easy grapple with going forward. 

A recursive function must:
1) call itself (recurse)
2) have a stopping point (base case)
3) advance to a stopping point (advance case)

Recursion requires practice and a degree of intuition. As we deal more with algorithms and data structures that call for recursion, we'll expand that intuition.

## 6 Searching

### Linear Search

Linear Search is a very straight forward algorithm

If we have a list of items, either in an array or linked list or whatever, the objective here is to simply iterate through the collection, until we find what we're looking for.

### Binary Search

Binary Search is much more efficient, but everything has a cost! Binary search requires your collection to already be sorted ahead of time. Nothing is free in computing, it's a matter of where you offload the cost, or complexity.

Binary search leverages an already sorted list. It works by constantly splitting the search space in half. So to start, you look at the middle most element. If it matches your target, you're done. Otherwise, check if the element in the middle is less than or greater than your target value. If it's less than your target value, you look at the middle most element in the left half of your array, if it's greater than, you search in the right half. 

The whole time, you keep track of the boundaries of your new partitions that you're searching in. 

--- 

Activity: Consider iterative approach vs. recursive approach

---

### Jump Search

Jump search is a more efficient version of the linear search. When I say it's more effecient, alarm bells should be ringing in your head and you should be asking "at what cost." 

It requires the list to already be sorted!

Jump search works by defining some *jump size*. Rather than walking forward one element at a time, instead, you jump by your jump size through the array. When you jump ahead, you check to see if the current element is the target, if it's less than, or greater than. If it's less than, you simply do a search through the previous jump space. If it's greater than, you keep leaping ahead by your jump size. You have to watch out for jumping beyond your array, so checking the bounds is required here.

--- 

Ponder: Efficieny, cost, and work

## Takeaways

- Functions can be described in terms of time and space relative to their inputs.  
- Big O notation describes an asymptotic upper bound, and is often used to discuss worst case growth rate for a function  
- Recursion has 3 rules that you must memorize.  

## Footnotes

[^1]: A distinction here, is that humans have some added cognitive tricks to make this work easier, but it can still be exhausting. A trade-off with traditional computers, is they're dumb. They can only follow instructions exactly. The trade-off is that they don't get mentally fatigued. So, the balancing act is offloading the higher level cognition to humans, and then offloading the actual work to machines. We can embed our cognition in the form of highly complex conditions in an algorithm, but the computer just follows what we told it to do, exactly.
