### Decorator Pattern

We have a family of classes that we want to be able to decorate, this would be some kind of abstract base class, and then concrete subclasses.

We then create a separate family of decorators, that have their own hierarchy as decorators. They have some abstract base class, and then concrete subclasses. The key is that the abstract base class, is also a subclass of the decorate-ables. In other words, our decorator abstract base class / interface, inherits from the decorate-able base class.

The decorators have some member that will be used to store a reference to the thing it wants to decorate or wrap. If you're using interfaces, then every subclass will likely need to define a reference

The decorator's purpose is to augment the behavior of the decorate-able. This means that it will have at least one of the same methods of the decorate-ables (this is overriding). We then write whatever logic we want inside of this method, and at some point we invoke the wrapped or decorated object's same method.


