#### Class Diagrams

[Class Lucid Chart](https://www.lucidchart.com/pages/uml-class-diagram)

A class diagram consists of 3-4 parts

For members, we can use + for public, - for private, and # for protected members. Static members can be underlined

Relationships
https://en.wikipedia.org/wiki/Class_diagram
#### Use Case Diagrams

[Use Case Lucid Chart](https://www.lucidchart.com/pages/uml-use-case-diagram)

#### Sequence Diagram

[Sequence Diagram Youtube](https://www.youtube.com/watch?v=pCK6prSq8aw)
[Sequence Lucid Chart](https://www.lucidchart.com/pages/uml-sequence-diagram)

Sequence diagrams have a timeline that moves from top to bottom.

Actors include anything from users to external systems that might interact with a system.

A lifeline is an element of the system that will be interacted with during the lifespan of a sequence.

Messages show how the different lifelines and actors interact. They usually have a block that follows a lifeline that indicates a certain amount of time passed for a given message or event

- Synchronous messages: Solid Arrow... waits for a reply. Responses to a synchronous message are usually dotted lines.

- Asynchronous message: Solid arrow... Doesn't need a reply

- Create Message: Shows the spawning of a new element. Usually labeled with \<\<create\>\> and a dotted arrow to the element being created

- Delete message shows when to destroy an element. Solid arrow to an X on the lifeline.

- Self message is just a loop arrow on the same lifeline

- Reply messages are usually dotted arrows

- Found message: from unknown source. Dot indicating unlisted element with an arrow to a lifeline.

- Lost message: to unknown source. Arrow from lifeline to a dot.

- Guards: Circle or square indicating some kind of conditional or situation that determines whether or not a sequence will execute.


#### Activity Diagram

[Activity Lucid Chart](https://www.lucidchart.com/pages/uml-activity-diagram)

