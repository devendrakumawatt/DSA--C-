#include<iostream>
using namespace std;

          // *** is Sorted or not using recursion ***

bool isSorted(int arr[], int size){
	// base case
	if(size == 0 || size == 1)
		return true;

	if(arr[0] > arr[1]){
		return false;
	}
	else{
		bool remainInput = isSorted(arr+1, size-1);
		return remainInput;
	}
}

int main(){

	int arr[5] = {2,4,6,8,9};
	int size = 5;

	bool ans = isSorted(arr, size);

	if(ans)
		cout << "Array is sorted" << endl;
	else
		cout << "Array is not sorted" << endl;
}





/*            // ** get sum of array using recursion **

int getSum(int arr[], int size){

	// base case
	if(size == 0)
		return 0;

	if(size == 1)
		return arr[0];


	int res = getSum(arr+1, size-1);
	int sum = arr[0] + res;
	return sum;
}


int main(){
	int arr[5] = {3, 2, 5, 1, 6};
	int size = 5;

	int ans = getSum(arr, size);
	cout << "Sum of Elements of array is : " << ans << endl;

} 
*/




/*			// *** Linear search using recursion ***

bool linearSearch(int arr[], int size, int key){

	// base case
	if(size == 0)
		return false;

	if(arr[0] == key){
		return true;
	}
	else{
		bool remainPart = linearSearch(arr+1, size-1, key);
		return remainPart;
	}

}

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	int size = 5;
	int key = 2;

	bool ans = linearSearch(arr, size, key);
	if(ans){
		cout << "Key present" << endl;
	}
	else{
		cout << "Key Absent" << endl;
	}
}
*/ 






/*			// *** Binary Search using Recursion ***

bool binarySearch(int arr[], int s, int e, int k){
	// base case

	if(s>e)
		return false;

	int mid = s + (e - s)/2;

	if(arr[mid] == k)
		return true;

	if(mid < k)
		return binarySearch(arr, mid+1, e, k);

	if(mid > k)
		return binarySearch(arr, s, mid-1, k);

}

int main(){
	int arr[6] = {2, 4, 6, 10, 14, 16};
	int s = 0;
	int e = 5;
	int k = 16;

	bool ans = binarySearch(arr, s, e, k);

	if(ans)
		cout << k << " is present in array" << endl;
	else
		cout << k << " is Absent in array" << endl;

} 
*/