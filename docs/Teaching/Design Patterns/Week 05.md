### Decorators

#### Definition
Attach additional behavior to an object dynamically.

#### Things we're avoiding

Monolithic structures.

This includes monolithic inheritance structures, and monolithic super classes.

#### Design Principles

Open for extension, closed for modification. 

#### Main Features

Structurally similar to strategy pattern. Composition based.

Context and Decorators both implement the same interface. 

While structurally similar, the intent is different (that's the main difference between most patterns). The idea is to not just delegate actions to components, but to also add additional behavior.

But it's not just a matter of adding additional behavior, it's a matter of separating and encapsulating what varies from what stays the same.