### To-do

This week we have the Iterator pattern for the upcoming project, and we have a project about the Composite pattern coming up soon as well.

We'll talk about these but we'll end up looping back and hitting the template method pattern in more detail because it's a really useful pattern.

### Iterator Pattern

At this point, whether you've known it or not, you've been interacting with iterators in just about every language you've used in your major so far. 

2420 is the first real brush with iterators that you've had though. You may not remember, but when implementing your linked list, you created an iterator. Check out this spec from python. 

https://wiki.python.org/moin/Iterator

Most languages have details on implementing iterators. It's a pretty important feature when it comes to creating data structures / containers. 

https://learn.microsoft.com/en-us/dotnet/csharp/iterators

https://cplusplus.com/reference/iterator/

#### Implementation

Looking at the python wiki about iterator, we see in their example iterator how the iter method returns self, while the iterator returns whatever value needs to be returned. Their random iterator is sort of silly, but we can see the structure. 

The idea is that in order for something to be iterable, it must return an iterator. 

To be an iterator, a class must implement the next method which returns some value, ideally from a collection.

In the simplest case, the class itself is also an iterator. But why would this be a bad idea? What kinds of things can go wrong here?

Why is it better to encapsulate the iterator?

What about iter? Is there a way we can make our classes a bit more robust when it comes to iteration?

#### Generators

Some languages support generators. All generators are an iterator. They make use of the yield keyword, and through language implementation, the state of the function is held in memory. Generators are wildly useful, but are a bit less of a pattern, and more of an idiom of a language that implements it. Still good to know them.

#### Single Responsibility Principle

A class should have only one reason to change. 

Remember one of our previous principles, open to extension, closed to modification. Remember that our principles are strong foundational guidelines, but they aren't laws. And scenarios like this are where we can bend the open/close principle. 

Why do we allow the pattern to change in this context though? What are some ways we can handle an iterator better? 

### Composite Pattern