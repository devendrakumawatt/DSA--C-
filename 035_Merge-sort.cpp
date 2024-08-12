#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
	int mid = s + (e-s)/2;

	int len1 = mid - s + 1;
	int len2 = e - mid;

	int *first = new int[len1];
	int *second = new int[len2];


	// copying value
	int k = s;
	for(int i=0; i<len1; i++){
		first[i] = arr[k++];
	}

	k = mid+1;
	for(int i=0; i<len2; i++){
		second[i] = arr[k++];
	}

	// merge 2 sorted array
	int index1 = 0;
	int index2 = 0;
	k = s;

	while(index1 < len1 && index2 < len2){
		if(first[index1] < second[index2]){
			arr[k++] = first[index1++];
		}
		else{
			arr[k++] = second[index2++];
		}
	}

	while(index1 < len1){
		arr[k++] = first[index1++];
	}

	while(index2 < len2){
		arr[k++] = second[index2++];
	}

	delete []first;
	delete []second;
}


void mergeSort(int arr[], int s, int e){
	// base case
	if(s >= e)
		return ;

	int mid = s + (e-s)/2;

	// left part sort krna h
	mergeSort(arr, s, mid);

	// right part sort krna h
	mergeSort(arr, mid+1, e);

	// merge
	merge(arr, s, e);
}

int main(){
	int arr[14] = {2, 5, 8, 9, 1, 4, 7, 3, 11, 99, 32, 12, 86, 13};
	int n = 14;

	cout << "Unsorted array : ";

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}cout << endl;

	mergeSort(arr, 0, n-1);

	cout << "Sorted array : ";

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}cout << endl;
}