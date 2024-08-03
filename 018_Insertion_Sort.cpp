#include<iostream>
using namespace std;

int printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

}

int insertionSort(int arr[], int n){
	for(int i=1; i<n; i++){

		int temp = arr[i];
		int j=i-1;

		for(; j>=0; j--){

			if(arr[j] > temp){
				arr[j+1] = arr[j];
			}
			else{
				break;
			}
		}
		arr[j+1] = temp;
	}
	return printArray(arr, n);
}

int main(){
	int arr[7] = {10,1,7,4,8,2,11};

	cout << "Insertion Sort result : " ;
	insertionSort(arr, 7);
}