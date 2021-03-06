#include <iostream>
int * ptrReturn(int& a)
{
	return &a;
}
int main()
{
	int a = 5;
	int b = 4;
	int * pb = &b;

	//ptrReturn(a) = pb; //error "Expression must be a modifiable lvalue"

	//pointer is an object, and the result of a function call is always an rvalue if the return type is an object type.


	//Dereferencing the pointer will give an lvalue denoting the object it points to.
	*ptrReturn(a) = b;//correct
	

	//Using a tmp object to contain the rvalue will allow us to use it as lvalue
	int * tmp = ptrReturn(a);
	*tmp = *pb;//also correct

	//or simply

	*tmp = b;

	//check it for yourself
	std::cout << a;
    return 0;
}

