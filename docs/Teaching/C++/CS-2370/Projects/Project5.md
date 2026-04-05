# Project 5 Notes

## Intro

Dr Harrison initially wrote the requirements for this project. There are a few inconsistencies and confusing parts, but once we break it all down, it's a very easy project.

The main parts we need to go over are:
- Single cpp vs many headers
- Structs vs Classes
- Polymorphism, dispatching, and object orientation
- Reading orders.txt

## Single cpp vs many headers

His instructions say to put everything in a single file. Do it or don't. I prefer to split everything up into sensible header files to keep things nicely organized. Keeping everything in a single source file leads to a monolithic file that can be hard to navigate and confusing to manage.

I break my project down into a main.cpp (groceries.cpp), customer.h, item.h, order.h, payment.h. I define all of my payments in the payment header file, and then define everything inline in all of the source files. This keeps it nice and modular. Then you just have to include your headers into your main.cpp.

Don't forget to add include guards e.g. #ifndef ITEM_H... 

## Structs vs Classes

In part 1 he says to make everything a struct and to keep the data members public in items and customers. In part 2, he provides a UML class diagram that shows all of the data members being private. For the sake of the project, keep everything as structs if you want. It's technically better if everything is private, but he already said to make it public, so you can do whatever's easiest.

We talked about this earlier but for reference: https://youtu.be/lmAarC0Zhq4?si=xuYvEzMPMkXBRgQ6

Object Orientation is about encapsulation i.e., information hiding. Internal data should be private, and should be accessible only through methods. Object orientation has less to do with "objects" and more to do with "message passing." In short, the proper OO way is to make your data private. A good reason for this can be seen if we think about the design of our Order class. It has a pointer to a payment.

```cpp
struct Order{
    Payment* payment;
};
```

In the above example, what would happen if we wanted to change our payment objects out? For instance, if we wanted to change our order's payment method to PayPal instead of credit? Imagine we wanted to do that at runtime. Well, as it stands, we'd have to remember to call delete on our payment since it's a dynamic heap allocated object, that way the memory would be free again. We'd then have to do our assignment. This is one area where it really pays to have a setter. Setters are often seen as annoying, especially when they're just boilerplate, but consider the DRY principle. If we have a setter, we can control that deletion in one spot, and we don't have to worry about cleaning up our pointers every time:

```cpp
class Order{
    private:
        Payment* payment;
    public:
        void SetPayment(Payment* p){
            delete payment;
            this->payment = p;
        }
};
```

*This isn't necessary for our project*, but it's something to consider in the overall design of object-oriented programs.

## Composition and confusing uml

In the uml diagram he gave, he has lineitem objects that we store in a vector. We also have a customer id but no reference or pointer to a customer object.

You sort of have creative liberty here, and you can do things as you see fit. If you follow his reference, you would maybe do a lookup in the customers vector and then call print_details on the right customer. However, if you find it easier, it might make more sense to compose your customer with an actual object. In such a case, it would be a good idea to have a pointer to the customer, and then invoke its print_detail method in your print_order method. The next section I'll talk about polymorphism.

## Polymorphism and runtime dispatch.

The uml defines a Payment base class that's supposed to be abstract. We make it pure abstract, or pure virtual in c++ terms, by setting any method = 0. Like so:

```cpp
class Payment{
    //data and constructors etc
    virtual string print_detail() = 0;

};
```

Payment is now pure virtual, or pure abstract, and cannot be instantiated by itself. This is vital for us so that we can get generic, polymorphic behavior. In other words, by doing this, we make it so that the dispatcher can determine the correct method to call during runtime.

```cpp
class PayPal{
    string print_detail() override {
        string output = "";
        //structure your output etc.
        //you can also use a stringstream here and use the stream operators to easily write into the stream, and then return a string once you're done building
        //might be useful to use a stringstream for formatting purposes (decimal points and so on)
        return "stuff...";
    }
};
```
Because payment has a pure virtual method, the message dispatcher never has an ambiguous situation when deciding whether to call the base Payment version of print_detail vs the PayPal version of print_detail. There is only one correct version. So why then do we use a Payment pointer in our Order class?

Because, the pointer is just a pointer. It points to an implementation. A pointer is not the object itself. Every subclass of Payment is a Payment at the root, but then additionally it's a Paypal or Credit or whatever.

0x3000 Payment: Payment
0x3001 ammount: double
0x3002 this   : Credit
0x3003 number : double
0x3004 etc...

In memory, all of the objects have a slice that is the base class, and then a slice that is the subclass. So, by doing a pointer to a Payment (pointer to implementation aka PIMPL), we can let the runtime point to any object that shares a Payment implementation, but then the runtime can determine the correct method to use on the subclass. This is really how polymorphism works.

This allows us to do things like 

payment->print_detail();

And then it calls the correct implementation on the credit instance's print_detail method.

Similarly, you could have a Customer* customer pointer, and then do something like 

```cpp
string print_order(){
    payment->print_detail();
    customer->print_detail();
}
```

## Reading Orders

To do this, you just need to do a while loop like you did before, but now you'll do two getlines. 

First getline for the order. On the order, once you've read the line, you can split on commas to get the individual entries. After you've done that, you can do a loop and iterate over the vector returned by split, and then call split again this time using '-' to get the item_id and its quantity. Using these values you can look up the items in the vector<item> and then create a lineitem object using the count number and information from the item object.

On the second getline, you can create a payment object and then set your order's payment pointer to that object. 
