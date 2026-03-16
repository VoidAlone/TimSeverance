/*
 *	this file is intentionally incomplete, and is just an artifact from class
 *	when we were talking about a bunch of concepts. For more complete explanations
 *	refer to the md docs 
 */
#include <cstddef>

class dynarray
{
public:
    int* data; //this is nullptr unless otherwise initialized
    const int CHUNK = 10;
    int size = 0;       //how many values we're storing
    int cap = CHUNK; //overall capacity

   public:
    dynarray(){
		//don't do this, this was a teaching moment in class
		//since we don't have accessors or mutators implemented yet
        data = new int[cap];
        data[0] = 1;
        data[1] = 2;
        size = 2;
    }


	dynarray(const dynarray& o) : cap(o.cap), size(o.size), data(new int[o.cap]){
		for(size_t i = 0; i < size; i++){
			data[i] = o.data[i];
		}
	}

	dynarray& operator=(const dynarray& o){
		delete[] data;
		size = o.size;
		cap = o.cap;
		data = new int[cap];
		for(size_t i = 0; i < size; i++){
			data[i] = o.data[i];
		}
		return *this;
	}
    void grow()
    {
		//addresses refer to grow.md
		//data:0x50F1
        cap *= 1.6;
        int* temp = new int[cap];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp; //data:0x5CF1 temp:0x5CF1
        temp = nullptr;
    }

	bool operator==(const dynarray& other){
		if(this->size == other.size)
			return true;
		else
			return false;

		//check each element is equal
		//etc...
	}

};
