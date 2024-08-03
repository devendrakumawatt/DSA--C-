#include<iostream>
using namespace std;

int printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

}

int selectionSort(int arr[], int n){

	for(int i=0; i<n-1; i++){
		int minIndex = i;

		for(int j = i+1; j<n; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}

	return printArray(arr, n);

}

int main(){
	int arr[5] = {64,25,12,22,11};
	cout <<"Selection Sort Result : ";
	selectionSort(arr, 5);
}