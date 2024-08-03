#include<iostream>
using namespace std;


void update(int **p2){
	// p2 = p2 + 1;
	// Change? => NO 

	// *p2 = *p2 + 1;
	// Change? => YES

	**p2 = **p2 + 1; 
	// Change? => YES
}


int main(){

	int i = 5;
	int *p = &i;
	int **p2 = &p;

	cout <<"Sab shi chal rha hai"<<endl;
	cout << "---------------------------"<<endl;


/*
	cout << "Printing p "<< p << endl;
	cout << "---------------------------"<<endl;

	cout << "Address of p "<< &p << endl;
	cout << "*p2  -- "<< p2 << endl;
	cout << "---------------------------"<<endl;

	cout << "i = "<< i <<endl;
	cout << "*p = "<< *p <<endl;
	cout << "**p2 = "<< **p2 <<endl;
	cout << "---------------------------"<<endl;

	cout << "&i = "<< &i <<endl;
	cout << "p = "<< p <<endl;
	cout << "*p2 = "<< *p2 <<endl;
	cout << "---------------------------"<<endl;

	cout << "&p = "<< &p <<endl;
	cout << "p2 = "<< p2 <<endl;
	cout << "---------------------------"<<endl;
*/

/*
	cout << endl << endl;
	cout << "Before - " << i << endl;
	cout << "Before - " << p << endl;
	cout << "Before - " << p2 << endl;

	cout << "---------------------------"<<endl;

	update(p2);
	cout << "After - " << i << endl;
	cout << "After - " << p << endl;
	cout << "After - " << p2 << endl;

	cout << "---------------------------"<<endl;

*/

/*
	int first = 8;
	int second = 18;
	int *ptr = &second;
	*ptr = 9;
	cout << first << " " << second << endl;
*/

/*
	int first = 6;
	int *p = &first;
	int *q = p;
	(*q)++;
	cout << first << endl;
*/

/*
	int first = 8;
	int *p = &first;
	cout << (*p)++ <<" ";
	cout << first << endl;
*/

/*
	int arr[6] = {11,21,31};
	int *p = arr;
	cout << p[2] << endl;

*/

	 
}