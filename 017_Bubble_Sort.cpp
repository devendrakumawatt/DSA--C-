#include<iostream>
using namespace std;

int printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

}

int bubbleSort(int arr[], int n){
	for(int i=0; i<n-1; i++){

		bool swapped = false;

		for(int j=0; j<n-1-i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false){
			break;
		}
	}
	return printArray(arr, n);
}


int main(){

	int arr[6] = {10, 1, 7, 6, 14, 9};
	cout << "Bubble Sort Result : ";
	bubbleSort(arr, 6);
}