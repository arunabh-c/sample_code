#include <stdio.h>


class MyClass
{
public:
	int* data;
	int size;

	MyClass(int sz) {
		size = sz;
		data = new int[size];
		for (int i =0 ; i < size; ++i)
		{
			data[i] = i;
		}
	}
	
	//<====add operaloaded assignment operator here

	~MyClass()
	{
		delete data;
		data =nullptr;
	}
};

int main()
{
	MyClass obj1(5);
	MyClass obj2 = obj1;//this will give a double free error which can be fixed by an overloaded assignment operator where 
	//obj2.data is created as a malloc entity on the heap to prevent double free

	return 0;
}
