### Patterns

Command

Template Method

Facade

Adapter

Iterator

Composite

Visitor

Null Object

MVC

#### What to know about them

For these patterns be familiar with the following:

What is the primary purpose of this pattern? 

What are secondary benefits, if any?

What kind of pattern is it? Creational, structural, behavioral?

What are key words associated with this pattern? For example, observer pattern uses keywords like Observer and Observable, notify and update, subscribe and unsubscribe. Command has key words like sender/invoker, receiver, command. 

What is the general structure of their UML diagram like when describing the general flow of the pattern?

### Principles

#### The Principle of Least Knowledge / Law of Demeter: Talk only to your friends

1. Each unit should have only limited knowledge about other units: only units "closely" related to the current unit.
2. Each unit should only talk to its friends; don't talk to strangers.
3. Only talk to your immediate friends.

#### Hollywood Principle: Don't call us, we'll call you

With the Hollywood Principle, we allow low-level components to hook themselves into a system, but the high-level components determine when they are needed, and how. In other words, the high-level components give the low-level components the “don’t call us, we’ll call you” treatment.

In other words, the template method pattern allowed us to write in "hooks" or spots where methods from a lower level class could be called. That lower level class is responsible for getting the job done, but it doesn't make all of the calls. The higher level template class does, and appropriately calls the lower level class when its specific methods are needed. 

#### Single Responsibility Principle: A class should have only one reason to change 

This principle is concerned with the same problems that we encountered in chapter 1 with the principle "encapsulate what varies." But, It's more related to determining how we perform that encapsulation. 

"Another wording for the Single Responsibility Principle is: Gather together the things that change for the same reasons. Separate those things that change for different reasons."