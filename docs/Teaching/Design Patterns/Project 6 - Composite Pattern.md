
### Project 6

The project is a fairly easy project if you are comfortable with the following topics: polymorphism, dispatching, recursion, parsing.

The section can be broken down into three major parts: The Composites, the Parser, and the Explorer.

#### Composites

Your project will consist of an interface, let's say, Node.

In this case, File is a leaf type, and Directory is a composite type, ie, it's made up of many other objects. 

They will roughly mirror the command structure provided in the spec, that is, the Node interface will have the methods list, listall, chdir, up, etc.

The big key is that since we're explicitly building a tree structure with our composites, the idea is that we will be traversing it recursively. In this light, the main benefit of this pattern is that we can treat each node as the same type (since they implement the same interface) and then we can treat everything polymorphically. This means that leaves are responsible for leaf behavior, and composites are responsible for composite behavior. We don't need to make distinctions or do type checks while interacting with the tree.

#### Parser

The potentially toughest aspect of this project is building the tree from the file.

I find it is MUCH easier to build the tree recursively than it is to build it iteratively. Iteration requires that you keep track of depth and a whole lot of details, while recursion makes use of the implicitly recursive structure that's already encoded in the directory file you're given.

I recommend having a Parser class with a parser, and parse helper function. Parse() will mostly be responsible for opening the file, reading the lines into a list/array, and then invoking parse_helper() 

ParseHelper() is really straight forward.

Step 1: Pop the first item off the list to get the "item to add"

Step 2: Base Case: If it's a leaf (or it doesn't contain a ":") then we simply return a File object.

Step 3: Advance Case: If it's not a leaf, we create a Directory object, and then iteratively scan through the next lines. Each line, we check to see if they're indented more than our "item to add". If yes, we add them to the list of children for the composite by calling the parse_helper and adding the return of that as the child. Finally, we break, and return the current Directory object.

#### Explorer

Just do a while loop with a "current" pointer to whatever we're looking at in the tree, and a nested if statement or switch/match statement with the commands. On each command, print out the return value of calling the appropriate function on the "current" objec.