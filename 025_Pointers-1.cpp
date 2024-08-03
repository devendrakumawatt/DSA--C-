#include<iostream>
using namespace std;



int main(){

	int num = 5;
	cout << num << endl;

	//address of operator - &

	cout << "Address of num is "<< &num << endl;

	int *ptr = &num;
	cout << "value is : "<<*ptr<<endl;
	cout << "Address is : "<<ptr<<endl;

	cout << "size of integer num is : "<<sizeof(num)<<endl;
	cout << "size of integer pointer is : "<<sizeof(ptr)<<endl;


	int a = *ptr;
	cout << "Before a++ num is : "<< num <<endl;
	a++;
	cout << "after a++ num is : "<< num <<endl;

	int n = 3;
	int *p = &n;
	cout << "Before (*p)++ num is : "<< *p <<endl;
	(*p)++;
	cout << "after (*p)++ num is : "<< *p <<endl;



	// copying a pointer
	int *q = p;
	cout << p << " - " << q << endl;
	cout << *p << " - " << *q << endl;

	

}