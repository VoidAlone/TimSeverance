The Visitor Pattern is fraught with varying implementations and philosophies depending on your language. In some ways, the way people think about the pattern and implement it, can turn it into something of an anti-pattern.

Let's see what the core purpose of the Visitor Pattern is and then we can dive into issues, and implementations.

From Design Patterns: Elements of Reusable Object-Oriented Software by the GoF:

Visitor Pattern:
Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.

### Main Idea
The Visitor Pattern's core idea is to add behavior to elements of an object structure. This insinuates adding behavior onto a composite structure of some kind. We're adding behavior to objects without modifying their class definitions. This allows us to obey the open/close principle. Great stuff.

There are some core issues with the pattern however, and the common solutions to those issues end up often being mistaken as the solution that the pattern provides.

The visior pattern is usually implemented with an Accept method in the elements, which takes a visitor, and then inside invokes the visit method of the visitor, and passes self to the visit() method.

class SomeObject
	accept(visitor)
		visitor.visit(this)

class Visitor
	visit(object)
		//do something

There is a problem that arises with this approach however. In languages (especially earlier languages when the pattern was invented) that only support single dispatch, the above pseudocode doesn't work. The dispatcher won't be able to determine which method to call if there are several overloads, especially if there's an overload for a common base class between elements.

So the solution is to do something like this

class SomeObject
	accept(visitor)
		visitor.visitSomeObject(this)

class Visitor
	visitSomeObject(object)
		//do something
	visitAnotherObject(object)
		//do something else
		
This approach avoids function overloading, and instead defines a set of functions with different names, so that we don't have to worry about which method the dispatcher chooses. 

Then, all elements of the composite structure implement the accept interface, or what I would call being a "visitable" as an object might be an "iterable"

However, in this solution, we face an inherent issue. We're now disobeying the open/close principle, even if only slightly. 

If we decide to use visitor from the get-go it might not be a problem, but if we decide we want to add behavior to our objects later, we now have to go implement the accept method for every single class. This is time-consuming, and arduous, especially if you have a very large heterogeneous composite structure. So now we're modifying our original structure.

For single-dispatch classes, we more or less have to concede to slightly breaking open/close principle even though that's what we were initially striving to maintain from the beginning.

### Multiple Dispatch
Now, the Accept/Visit dichotomy is almost inherently tied to the concept of the visitor pattern, and in almost all scenarios, you'll find people who talk about the necessity of the accept method, and you'll see the accept method being used even in languages where the above issues don't apply. Let's take a look at an example of the visitor with Multiple Dispatch

class Object1:
	accept(Visitor)
		visitor.visit(this)
class Object2:
	accept(Visitor)
		visitor.visit(this)
class Visitor:
	visit(ObjectA)
		//do something
	visit(ObjectB)
		//do something else

In the above example, with multiple dispatch, we'll likely be dispatching the method call based on a number of factors.

We'll look at the order, arity, and types of parameters passed, we'll look at the type of object that the message is being sent to, and we'll look at the name of the function.

In a single dispatch situation, usually the method that gets dispatched is based on the type of the receiving object. So with visitor.visit(obj), the dispatcher will look at visitor to decide the function. In languages like python, function overloading just refers to the last defined function, in other languages, it may defer to the first, in any case, it doesn't matter what the arguments of the function are, because it won't look at them to resolve it.

However, in a multiple dispatch scenario, it will be able to determine the correct method to call based on many factors revolving around the message being sent.

So now we can do something like this

class Object1:
	accept(Visitor)
		Visitor.visit(this)
class Visitor:
	visit(Object1)
		//do something
	visit(Object2)
		//do something else

In this scenario, we can define a generic visit method, which makes defining our accept a little bit easier. We can just call the visit method of the visitor without having to specify a bunch of different unique names depending on the type of object we want to visit.

This is where the next issue with the visitor pattern comes in. If we're in a multiple dispatch scenario where we're able to determine the correct method to call based on the type of arguments being passed in, this renders the accept method completely useless. However, this isn't so much of an issue with the visitor pattern as it is with the dogma and interpretations of programmers who have implemented the visitor pattern in their varying languages.

So, if we have multiple dispatch, then we can do something like

class Object1:
	...

class Visitor:
	visit(Object1)
		//do something
	visit(Object2)
		//do something else

Now we can truly obey the open/close principle. We no longer need to modify our original classes, and we can just add behavior to the object in question.

However, in my experience, programmers will assert that this isn't a proper visitor pattern.

### Traversal

Now, revisiting the intent of the Visitor Pattern, the idea is that we should be adding behavior to elements of an object structure. This is the core idea. Especially in the context of ASTs and general graphs, the visitor pattern is very popular. In the GoF book, it even discusses ASTs as one of the main examples for usage. One of the main use cases of the Visitor Pattern is to not only add behavior to a set of elements, but also to manage traversal of a tree structure. While this two-for-one behavior can be useful, it does end up confusing the purpose of the pattern in my opinion, and violates the single responsibility principle.

There are two places we can define the traversal of the tree in the visitor pattern. One of the more common ways is to define it in the accept method. However, this violates single responsibility principle. 

The accept method in the case of an element is to make it visitable by emulating double dispatch. 

If we put the traversal logic inside of the visitor, we're still, once again, disobeying the single responsibility principle. 

The purpose of the visit method in the case of the visitor is to perform some operation on or with the element in question, thus extending the element's behavior.

In either scenario, we should be avoiding adding traversal behavior to either the visitable, or the visitor. 

Iterators are in charge of iteration, and then we can perform logic on that Iterable via other means.

### Circular Includes / Forward Declaration



### Solutions

For single dispatch scenarios, we have to concede to following the accept/visit paradigm. It isn't an ideal scenario, however, we end up getting better behavior out of our classes by following open/close as best we can. It's not perfect, but neither is single dispatch.

However, for multiple dispatch scenarios, there really is no reason why we should be using the accept/visit paradigm. The terms accept/visit don't even really lend themselves to what we're trying to do with the class in question. 

In both scenarios, we should also not be tying the traversal to the algorithm that we're adding to the classes. I suggest we instead define a Visitable interface which would define something similar to our accept method. 

On one hand, accept ends up adding weird behavior to our objects, but on the other hand, by putting traversal properties here, it means that the visitor doesn't have to be aware of the underlying family structure of the node it's operating on. On the other hand, the idea is to add behavior to elements, which means that we're extending the behavior of nodes whose behavior we should be aware of to begin with. 

I suggest we should abandon the pattern altogether in the case of multiple dispatch scenarios, and instead define a recursive iterator, which could follow any depth first or breadth first algorithm or whatever you want, and then while iterating through for each object, call the Extender's method on the currently iterable object. This could be implemented via strategy pattern, or a pure visitor scenario. This would also eliminate the need to define an accept method in every single class that makes up your tree. This would also clear up the terminology issues that arise with the visitor pattern.

The use of accept also violates DRY. The problems with the pattern are myriad, and there seems to be a plethora of misunderstanding regarding the topics of dispatching, and general confusion when confronted with the redunant feeling of having accept be called on an object so that visit can be called with the object as an argument, and then potentially calling accept within the visitor on the children of the object being visited. It's a mess overall, and while it's a nifty way to approach things, I think we can do better.