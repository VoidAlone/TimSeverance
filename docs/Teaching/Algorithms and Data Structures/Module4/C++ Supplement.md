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
MyClass(const MyClass& other) : size(other.size), capacity(other.capacity), myarray(new int[capacity]){
    for(auto i = 0; i < size; i++){
        myarray[i] = other.myarray[i];
    }
}
```

### Copy Assignment

```cpp
MyClass& operator=(const MyClass& other){
    if(this == &other){
        return *this;
    }

    delete[] myarray;
    capacity = other.capacity;
    size = other.size;
    myarray = new int[capacity];
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
};
```

```cpp example.cpp
void MyClass::f(){
    //do something
}
```

## Templates

Templates are similar to what some of you may know as "generics" in Java or C#. Templates allow you to define classes and methods in a way that lets them accept generic arguments. They can get complex, but the following is a simple form that will be common for you all.

```cpp
template <typename T>
class MyClass{
    T value;

public:
    void setValue(const T& newValue){
        value = newValue;
    }

    T getValue() const{
        return value;
    }
};
```

[Header vs Source implementation for Templates](https://learn.microsoft.com/en-us/cpp/cpp/source-code-organization-cpp-templates?view=msvc-170)

## Pass-by

There are four ways you will pass values to functions in C++.

- Pass-by-value creates a copy. Changes made inside the function do not affect the original.
- Pass-by-reference lets the function work with the original object without dealing with pointers.
- Pass-by-const-reference avoids a copy while protecting the original from modification.
- Pass-by-pointer creates a local pointer variable containing whatever address you passed in. Arrays are passed by pointer for instance.

```cpp
void byValue(int x){}
void byReference(int& x){}
void byConstReference(const int& x){}
```

## Pointers vs References

Pointers and references both let you indirectly work with other values, but they are not the same thing.

### Pointer 

A pointer stores an address. It can be reassigned, and it can also be `nullptr`.

```cpp
int value = 10;
int* ptr = &value;
```

### Reference

A reference is another name for an existing object. It must be initialized when declared and cannot later refer to a different object.

```cpp
int value = 10;
int& ref = value;
```

### Get Address

Use `&` to get the address of a variable.

```cpp
int value = 10;
int* ptr = &value;
```

### Dereference

Use `*` to follow a pointer to the value stored at that address.

```cpp
int value = 10;
int* ptr = &value;
*ptr = 20;
```

## Friend

The `friend` keyword allows a non-member function or another class to access private members.

```cpp
class MyClass{
    friend void printValue(const MyClass& obj);

private:
    int value = 42;
};
```
