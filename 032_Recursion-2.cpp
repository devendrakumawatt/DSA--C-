#include<iostream>
using namespace std;


//    ** REACH HOME **

void reachHome(int src, int dest){

	cout << "source : " << src <<", Destination" << dest << endl;
	// base case
	if(src == dest){
		cout << "Pahuch gya "<<endl;
		return ;
	}

	// processing - ek step aage
	src++;

	// recursive call
	reachHome(src, dest);
}

int main(){
	int dest = 10;
	int src = 1;

	cout << endl;
	reachHome(src, dest);
}




/*    **** FIBONNACI SERIES ****

int fibbonnaci(int n){
	// base case
	if(n==1)
		return 0;

	if(n==2)
		return 1;

	// recursive function
	return fibbonnaci(n-1) + fibbonnaci(n-2);
}

int main(){
	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int ans = fibbonnaci(n);
	cout << "Answer : " << ans <<endl; 
}
*/


/*    *** nth Stairs ***


 int countStairs(int n){
 	// base case
 	if(n < 0)
 		return 0;

 	if(n == 0)
 		return 1;


 	// recursive function
 	return countStairs(n-1) + countStairs(n-2);

 }

int main(){
	int n;
	cout << "enter the nth stairs : ";
	cin >> n;

	int res = countStairs(n);
	cout << "Result : " << res << endl;
}
*/


/* *** say digit ****

void sayDigit(int n, string arr[]){
	// base case
	if(n == 0)
		return ;

	// processing
	int digit = n % 10;
	n = n / 10;
	

	// recursive function
	sayDigit(n, arr);

	cout << arr[digit] << " ";
}

int  main(){
	string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	int n;
	cout << "Enter a number : ";
	cin >> n;

	cout << endl;
	sayDigit(n, arr);
}
*/