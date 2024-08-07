#include<iostream>
using namespace std;

/*  // **** MACROS ****

#define PI 3.14

int main(){
	int r = 5;
	// double pi = 3.14;
	double area = PI * r * r;
	cout << "Area is : "<< area << endl;

}
*/

/*       // **** GLOBAL VARIABLE ****

int score = 54;

void a(int &i){
	cout << i << endl;
	cout << "score in a : " << score << endl;
	// b(i);
}

void b(int &i){
	cout << i << endl;
	cout << "score in b : " << score << endl;
}

int main(){
	int i = 5;
	a(i);
	cout << "score in main : " << score << endl;
}

*/


/*           // **** INLINE FUNCTIONS ****

inline void func(int a, int b){
	a++;
	b++;
	cout << a << endl;
	cout << b << endl;
}

int main(){
	int a = 1, b = 2;
	func(a,b);
}

*/


// *** DEFAULT ARGUMENT ***

void print(int arr[], int n, int start = 0){
	for(int i=start; i<n; i++){
		cout << arr[i] << endl;
	}
}

int main(){
	int arr[5] = {9,2,8,4,7};
	print(arr, 5);
}