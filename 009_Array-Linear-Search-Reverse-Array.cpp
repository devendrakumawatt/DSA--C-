// #include<iostream>
// using namespace std;


// void printArray(int arr[], int size){
// 	for(int i=0; i<size; i++){
// 		cout << arr[i] << " ";
// 	}
// 	cout << "Printing done" <<endl;
// }



// int main(){
	// declare
	// int num[15];

	// cout << "Value at 0th index is "<< num[0] << endl;

	// cout << endl << "Evertything is Fine" << endl;

	// int num[15] = {1,2,3,5,12,4} ;
	// int n = 15;

	// printArray(num , 15);
// }


// ------------------------------------------------

// #include<iostream>
// using namespace std;


// int getMax(int numb[], int n){
// 	int max = 0;
// 	for(int i=0; i<n; i++){
// 		if(numb[i] > max){
// 			max = numb[i];
// 		}
// 	}
// 	return max;
// }

// int getMin(int numb[], int n){
// 	int min = 100;
// 	for(int i=0; i<n; i++){
// 		if(numb[i] < min){
// 			min = numb[i];
// 		}
// 	}
// 	return min;
// }


// int main(){

// 	int numb[100];
// 	int size;
// 	cout << "Enter the Size of array" <<endl;
// 	cin >> size;

// 	cout << "Enter the values in array" << endl;
// 	for(int i=0; i<size; i++){
// 		cin >> numb[i];
// 	}

// 	cout << "Maximum value " << getMax(numb, size) <<endl;
// 	cout << "Minimum value " << getMin(numb, size) <<endl;
// }






// Linear Search --------------------------

// #include<iostream>
// using namespace std;

// bool search(int arr[], int size, int key){
// 	for(int i=0; i<size; i++){
// 		if(key == arr[i]){
// 			return 1;
// 		}
// 	}
// 	return 0;
// }

// int main(){
// 	int arr[10] = {5,7,8,3,4,1,5,6,33,12};

// 	cout << "Enter the key to search for "<< endl;
// 	int key;
// 	cin >> key;

// 	bool found = search(arr, 10, key);

// 	if(found){
// 		cout << "Key is present" <<endl;
// 	}
// 	else{
// 		cout << "Key is not present" <<endl;
// 	}

// }



// Reverse Array -------------------------------

#include<iostream>
using namespace std;


void reverse(int arr[], int size){
	int start = 0;
	int end = size-1;

	while(start<=end){
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}


void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main(){

	int ev[6] = {1,3,4,5,6,7};
	int od[5] = {1,3,2,6,8};

	cout << "Before Reverse 1st = " ;
	for(int i=0; i<6; i++){
		cout << ev[i] << " ";
	}
	cout << endl;

	cout << "Before Reverse 2nd = " ;
	for(int i=0; i<5; i++){
		cout << od[i] << " ";
	}
	cout << endl;
	cout << endl;

	reverse(ev, 6);
	reverse(od, 5);

	cout << "After Reverse 1st = ";
	printArray(ev, 6);

	cout << "After Reverse 2nd = ";
	printArray(od, 5);
	cout << endl;
}