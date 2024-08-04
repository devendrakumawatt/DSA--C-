#include<iostream>
using namespace std;

int &func(int a){
	int num = a;
	int &ans = num;
	return ans;
}

void update1(int n){
	n++;
}

void update2(int &n){
	n++;
}


int getSum(int *arr, int n){
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	return sum;
}


int main(){

/*
	int i = 5;
	// Create a reference variable

	int &j = i;
	cout << i << endl;
	i++;
	cout << i << endl;
	j++;
	cout << i << endl;
	cout << j << endl;

*/

	// int n = 5;
	// cout << "Before -- " << n << endl;
	// // update(n);
	// update2(n);
	// cout << "After -- " << n << endl;

	// func(n);


	int n;
	cout << "Size of array = ";
	cin >> n;

	// variable size array
	int *arr = new int[n];

	// taking input in array
	cout << "Enter elements of an array : ";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int ans = getSum(arr, n);

	cout << "Answer is = "<< ans << endl;

}