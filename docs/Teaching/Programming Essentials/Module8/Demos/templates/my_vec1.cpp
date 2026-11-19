
#include "my_vec1.hpp"

template<typename T>
void MyVec<T>::add_data(T x, int index);
	this->data[index] = x;
}

template class MyVec<int>;
template class MyVec<char>;
