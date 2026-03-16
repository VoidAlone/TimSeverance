```cpp
#include "dynarray.h"
#include <iostream>

using namespace std;

// class MyClass{
//     public:
//         int get_size(){
//             return 0;
//         }
// };

int main(){
    // MyClass m1;
    // int x = m1.get_size();
    //
    // MyClass* m_pointer = new MyClass();
    // x = m_pointer->get_size();
    // x = (*m_pointer).get_size();
    //

    dynarray d;
    d.grow();
    cout << d.data[0] << endl;
    d.grow();
	dynarray d1 = dynarray();
	dynarray d2 = d1;
}
```
