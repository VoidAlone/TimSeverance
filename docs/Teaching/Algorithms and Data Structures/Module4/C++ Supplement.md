# C++ Supplement

## Rule of 3

[Rule of 3/5/0](https://en.cppreference.com/cpp/language/rule_of_three) states that if a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three.

Things like pointers are resources whose lifespan is given to the user to manually manage. Imagine the address of that resource being like a venue that you rent out, and the runtime gives you the keys. Once you're done, you clean up and lock up after yourself, and then return the keys back to the owner.

So, if you define an object that makes use of a manually managed resource, like a pointer, you're expected to clean up after yourself. This means, that typically, you need a destructor. The rule of 3 says that if you need any 1 of a destructor, copy constructor, or copy assignment, you need the rest.

Suppose a class exists:

```cpp
class MyClass{
    int* myarray;
    int capacity;
    int size;
    ...
};
```

### Destructor

```cpp
~MyClass(){
    delete[] myarray;
}
```

### Copy Constructor

```cpp
MyClass(const MyClass other) : size(other.size), capacity(other.capacity), myarray(new int[capacity]){
    for(auto i = 0; i < size; i++){
        myarray[i] = other.myarray[i];
    }
}
```

### Copy Assignment

```cpp
MyClass& operator=(const MyClass& other){
    delete[] myarray;
    capacity = other.capacity;
    size = other.size;
    myarray = new int[capacity]
    for(auto i = 0; i < size; i++){
        myarray[i] = other.myarray[i];
    }
    return *this;
}
```

## Header vs Source

Headers allow you to declare a high level blueprint of your class among other things. Headers can include definitions, but also allow you to keep your implementation separate from its declaration. 

```cpp example.h
class MyClass{
    void f();
}
```

```cpp example.cpp
void MyClass::f(){
    //do something
}
```

## Templates

Templates are similar to what some of you may know as "generics" in java or c#. Templates allow you to define classes and methods in a way that lets them accept generic arguments. They can get complex but the following is a simple form that will be common for you all.

```cpp
template typename<T>
class MyClass{
    T value;
    T 
}
```

## Pass-by

## Pointers vs References

### Pointer 

### Reference

### Get Address

### Dereference

## Friend

