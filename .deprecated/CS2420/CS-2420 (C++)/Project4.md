# Project 4 - Linked Lists

## How Linked Lists Work

## SList

SList is mostly entirely set up for you. All you have to do is implement insert, remove, remove_all, at, operator[], size(), and find.

### Insert

Pretty easy. Just iteratively walk through the list, check if the current value is less than or equal to the insert value, and the next value is greater than insert value, and then relink

```cpp
node_to_insert->next = cursor->next;
cursor->next = node_to_insert;
```

### Remove
Find first occurance of node_to_remove, then relink and delete

```cpp
temp = current
prev->next = current->next;
delete temp;
```
### RemoveAll
Same as remove, but delete while instances still exist

### Find
Iterate through and return first instance index. Ie keep a counter to tell where it lives

### At
Iterate n times and return value at index

### Operator[]
Same as at basically

### Size
Keep a counter that's modified on removes and inserts, return this value

## C++ Tech

There are a few things to be aware of when you implement this project. Most of the project is handled for you, but there are some things that may confuse you if you're not aware

### **Templates**

Templates give us generic behavior for our programs. The syntax for templates is similar to that of Generics in other languages like C#. 

```cpp
template <typename SomeType>
class SomeClass{
    T data;
    SomeClass();
};
... Somewhere in main

SomeClass<int> class_instance;

```

Like vectors, ```Vector<int> TeamRoster```, that allow you to create a container that accomadates any data type.

### **Rule of 3 and Constructors**

Rule of 3 states: if you need one of Destructor, Copy Constructor, or Copy Assignment, you probably need all 3.

How do you know if you need one of these? If you're using a managed resource like a pointer in your class.

Destructors handle delete, copy construct handles copying of pointers, and copy assignment does the same.

Constructor: 
```cpp
...
SomeClass() { ... };    //constructor with body for initialization
SomeClass() = default; //instantiate a class
SomeClass() = delete; //Not allowed to instantiate the class with a basic constructor
SomeClass(int param) : data(param) {}   //Does one init step using list initialization syntax... Default constructor required  now
SomeClass(int param) { data = param; } //Does two init steps, one at resource acquisition, and one in the body of constructor
```

Copy Constructor:
```cpp
SomeClass(const SomeClass& other) { this->data = other.data };
SomeClass(const SomeClass& other) : data(other.data) {}
SomeClass(const SomeClass& other) = default;    //Default generation of constructor. If no pointers, use this
SomeClass(const SomeClass& other) = delete;     //Disallow copy constructor
```

Copy Assignment:
```cpp
SomeClass& operator=(const SomeClass& other) { this->data = other.data} // not a constructor
SomeClass& operator=(const SomeClass& other) = default; //Automatically generated. If no pointers, use this
SomeClass& operator=(const SomeClass& other) = delete;  //Disallow copy assignment
```

Destructor:
```cpp
~SomeClass() = default; //automatically generated Destructor
~SomeClass() = delete;  //Disallow destruction (can't use delete class_instance)
~SomeClass() { delete ptr; }    //Required if using pointers or other managed resources under the hood
```

### **Ownership**

In our project, SList owns the Node class, so it handles the cleanup of nodes. This is why the Node class doesn't actually adhere to Rule of 3. SList will instead clean up the node resources in the remove methods and Destructor.
