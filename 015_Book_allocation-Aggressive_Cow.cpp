// Book Allocation ------------------

// #include<iostream>
// using namespace std;

// bool isPossible(int arr[], int n, int m, int mid){
// 	int studentCount = 1;
// 	int pageSum = 0;

// 	for(int i = 0; i< qn; i++){
// 		if(pageSum + arr[i] <= mid){
// 			pageSum = pageSum + arr[i];
// 		}
// 		else{
// 			studentCount++;
// 			if(studentCount > m || arr[i] > mid){
// 				return false;
// 			}
// 			pageSum = arr[i];
// 		}
// 	}
// 	return true;
// }


// int allocateBook(int arr[], int n, int m){
// 	int s = 0;
// 	int sum = 0;

// 	for(int i = 0; i<n ; i++){
// 		sum = sum + arr[i];
// 	}
// 	int e = sum;
// 	int ans = -1;

// 	int mid = s + (e - s)/2;

// 	while(s <= e){
// 		if(isPossible(arr, n, m, mid)){
// 			ans = mid;
// 			e = mid - 1;
// 		}
// 		else{
// 			s = mid + 1;
// 		}
// 		mid = s + (e - s)/2;
// 	}
// 	return ans;
// }


// int main(){


// 	int books[4] = {10, 20, 30, 40};

// 	cout << "Answer of book allocation is = " << allocateBook(books, 4, 2);
// }




// Agressive Cows ----------

#include<iostream>
#include <bits/stdc++.h>
using namespace std;


bool isPossible(int stalls[], int k , int mid, int n){
	int cowCount = 1;

	int lastPos = stalls[0];

	for(int i=0; i<n; i++){
		if(stalls[i]-lastPos >= mid){
			cowCount++;
			if(cowCount == k){
				return true;
			}
			lastPos = stalls[i];
		}
	}
	return false;
}


int aggressiveCows(int stalls[], int n , int k){
	sort(stalls,stalls + k);
	int s=0;
	int maxi = -1;
	for(int i=0; i<k; i++){
		maxi = max(maxi, stalls[i]);
	}
	int e = maxi;
	int ans = -1;
	int mid = s + (e - s)/2;

	while(s <= e){
		if(isPossible(stalls, k, mid, n)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid - 1;
		}
		mid = s + (e - s)/2;
	}
	return ans;
}


int main(){

	int stalls[5] = {4,2,1,3,6};
	cout << "Largest minimum distance between two cows : "<<aggressiveCows(stalls, 5, 2);

}