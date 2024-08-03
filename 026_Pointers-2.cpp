#include<iostream>
using namespace std;


void print(int *p){
	cout << *p <<endl;
}

void update(int *p){
	// p = p + 1;
	// cout << "Inside ==== "<< p <<endl;
	*p = *p + 1;
}

int getSum(int *arr, int n){
	cout << endl <<"Size --- "<< sizeof(arr) << endl;
	int sum  = 0;
	for(int i=0; i<n; i++){
		sum = sum + arr[i];
	}
	return sum;
}


int main(){
	// Integer Array
/*
	int arr[10] = {23, 122, 41, 67};

	cout << "Address of first memory block is "<< arr << endl;
	cout << arr[0] << endl;
	cout << "Address of first memory block is "<< &arr[0] << endl;

	cout << "4th "<< *arr << endl;
	cout << "5th "<< *arr + 1 << endl;
	cout << "6th "<< *(arr + 1) << endl;
	cout << "7th "<< arr[2] << endl;
	cout << "8th "<< *(arr + 2) << endl;

	int i = 3;
	cout << "formula value w1 - "<< i[arr] << endl;
	cout << "formula value w2 - "<< *(i + arr) << endl;




	int temp[10];
	cout << sizeof(temp) << endl;

	int *ptr = &temp[0];
	cout << sizeof(ptr) << endl;


	cout <<"-----------"<<endl;
	cout << "&temp => " << &temp << endl;
	cout << "&ptr => " << &ptr << endl;
	cout <<"-----------"<<endl;


	int drr[10];
// ERROR
	// drr = drr + 1


	int *drt = &drr[0];
	cout << drt << endl;
	drt = drt + 1;
	cout << drt << endl;

*/



	// Character Array
/*
	char ch[6] = "abcde";
	cout << ch <<endl;

	char *c = &ch[0];
	// print 0th index of string
	cout << *c <<endl;
	// print entire string
	cout << c <<endl;


	char temp = 'z';
	char *tp = &temp;
	cout << tp <<endl;
*/



	// Pointer & functions

/*
	int value = 5;
	int *p = &value;
	// print(p);	

	cout<<"before ==== "<< *p <<endl;
	update(p);
	cout<<"after ==== "<< *p <<endl;
*/


	int arr[5] = {1,2,3,4,5};

	cout << "Sum is "<< getSum(arr,5) << endl;
}