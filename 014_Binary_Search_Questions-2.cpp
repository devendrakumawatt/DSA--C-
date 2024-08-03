// First and Last occurance ------

// #include<iostream>
// using namespace std;

// int firstOcc(int arr[], int size, int key){
// 	int s = 0,e = size-1;
// 	int mid = s + (e - s)/2;

// 	int ans = -1;
// 	while(s<=e){
// 		if(arr[mid] > key){
// 			e = mid-1;
// 		}
// 		else if(arr[mid] < key){
// 			s = mid+1;
// 		}
// 		else if(arr[mid] == key){
// 			ans = mid;
// 			e = mid-1;
// 		}
// 		mid = s + (e - s)/2;
// 	}
// 	return ans;
// }

// int lastOcc(int arr[], int size, int key){
// 	int s = 0,e = size-1;
// 	int mid = s + (e - s)/2;

// 	int ans = -1;
// 	while(s<=e){
// 		if(arr[mid] > key){
// 			e = mid-1;
// 		}
// 		else if(arr[mid] < key){
// 			s = mid+1;
// 		}
// 		else if(arr[mid] == key){
// 			ans = mid;
// 			s = mid+1;
// 		}
// 		mid = s + (e - s)/2;
// 	}
// 	return ans;
// }

// int main(){

// 	int even[9] = {1,2,3,3,3,3,3,4,5};

// 	cout << "First Occurance of 3 is at index : " << firstOcc(even, 9, 3);
// 	cout << endl;
// 	cout << "Last Occurance of 3 is at index : " << lastOcc(even, 9, 3);
// }




// Peak element of mountain array ----------------

#include<iostream>
using namespace std;

int peakElement(int arr[], int n){
	int s = 0, e = n-1;
	int mid = s + (e-s)/2; 
	while(s < e){
		if(arr[mid] < arr[mid+1]){
			s = mid+1;
		}
		else{
			e = mid;
		}
		mid = s + (e-s)/2;
	}
	return arr[s];
}

int main(){

	int peak[9] = {1,2,3,4,6,7,5,3,1};

	cout << "Peak Element of array is : " << peakElement(peak,9) ;
}