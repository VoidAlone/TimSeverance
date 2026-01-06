Scientific Notation: be able to read it, how does it work?

Range of decimal numbers and modulo operation. How many results are possible
for a given mod operation?

---
Cin deliminates on what characters? How does cin work? 
https://www.geeksforgeeks.org/cpp/cin-in-c/
Take note of the first example under Examples of cin. 

Taking a Text from User Input
```cpp
#include <iostream>
using namespace std;

int main() {
  
  	// Variable to store data given by cin
    string s;

    // Take input using cin
    cin >> s;

    // Print output
    cout << s;
    return 0;
}
```

Input

```Welcome to GeeksforGeeks```

Output

```Welcome```

We can see that when evaluating such a string for cin, only 'Welcome' is consumed and assigned to s. 
The rest of the input is still in the buffer waiting to be assigned.

Run the following code and observer its behavior

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;

    // Keep reading until end of input (e.g. Ctrl+D or Ctrl+Z)
    while (cin >> word) {
        cout << "You entered: " << word << endl;
    }

    return 0;
}
```

---

A couple of questions about basic syntax like bools, conditionals, ints and overflow etc.

Overflow

Assume a while loop for a menu, implemented in standard/sane way, what kinds of
conditions will exist for continuing/exiting.

A TRICKY switch statement question if you're not paying attention. 
What does a switch statement need to function correctly?

Ternary operators

Short circuit evaluation

Rational approaches to writing software

A bunch of questions just evaluating what a loop will do, what cin will do, weird assignments for vectors and arrays.

Remember for arrays and any variable, a declaration means that even if you don't explicitly initialize anything yourself, by creating an array, you now have n number of elements. They maybe be garbage values because you didn't specify what they should be, but they are usable nonetheless. 

C strings. There's a question that's a trick question if you don't remember that strings technically end in a terminal character (doesn't show up on your screen, but it's there for the computer).

Arrays are passed by pointer, not by copy/value.

Recursive functions. Think about where they "pause" and come back. Think about rules for recursion: Base case, advance, calls itself.

Bit shifts and masks. Be familiar with bitwise and, or, xor. 

Keep an eye out for the static keyword on the last question, and remember the
difference between ++i and i++.
