### Observer

The general problem solved by the observer is a matter of interrupting/polling

**Principles**

We still want to generally adhere to the principles we covered in chapter 1: Encapsulate what varies, composition over inheritance, program to an interface, DRY. 

Our new principle is to strive for loose coupling in our designs. We want our classes and methods to rely on each other and external data as little as possible.

**Definition** 

A one-to-many dependency between objects so that when state for one changes, the rest are updated accordingly

### Pub/Sub

Very similar to the observer, but adds an additional layer between the subjects/observers