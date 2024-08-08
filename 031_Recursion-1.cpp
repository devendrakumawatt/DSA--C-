#include<iostream>
using namespace std;

int factorial(int n){
	// Base case
	if(n == 0){
		return 1;
	}

	// Recursive relation
	return n * factorial(n-1);
}


int power(int p){
	// Base case
	if(p == 0)
		return 1;

	// Recursive relation
	return 2 * power(p-1);
}


int countPrint(int c){
	// Base case
	if(c == 0)
		return 1;


	// Recursive relation
	countPrint(c-1);
	cout << c << endl;	

}

int main(){

/* // ** Factorial **
	int n;
	cout << "Enter the value of n";
	cin >> n;
	int ans = factorial(n);
	cout << "Answer  :  " << ans << endl;

*/


/*	// ** Power **
	int p;
	cout << "Enter the value of p ";
	cin >> p;
	int res = power(p);
	cout << "Result  :  " << res <<endl;

*/


	// ** Counting **
	int c;
	cout << "Enter the value of c ";
	cin >> c;
	countPrint(c);

	
}