```py
'''
Note that dunder methods in python and operator overloads in C++ more or less do the same thing

In this case, we're implementing __eq__ so that two objects can be compared. 

bool operator==(const _& other) does the exact same thing.

both take a parameter other, and then we do some sort of comparison and return a bool so we can do equality checks
'''

class Ex:
    def __eq__(self, other: Ex):
        return self.x = other.x

    def __iadd__(self, other):
        self.x = self.x + other.x

def main():
    ex1 = Ex()
    ex2 = Ex()

    print(ex1 == ex2)
```
