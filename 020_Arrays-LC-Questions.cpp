// Reverse an array --------------------------- 
// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> reverse(vector<int> v){
// 	int s = 0, e = v.size()-1;

// 	while(s<=e){
// 		swap(v[s],v[e]);
// 		s++;
// 		e--;
// 	}
// 	return v;
// }

// void printArray(vector<int> v){
// 	for(int i=0; i<v.size(); i++){
// 		cout<<v[i]<<" ";
// 	}
// }

// int main(){
// 	vector<int> v;
// 	v.push_back(11);
// 	v.push_back(7);
// 	v.push_back(3);
// 	v.push_back(12);
// 	v.push_back(4);

// 	vector<int> ans = reverse(v);

// 	cout<<"Printing reverse of an array after reverse"<<endl;
// 	printArray(ans);
// }





// Merge 2 sorted array ----------------------------

// #include<iostream>
// #include<vector>
// using namespace std;

// void printArray(int ans[], int n){
// 	for(int i=0; i<n; i++){
// 		cout<<ans[i]<<" ";
// 	}
// }

// void merge(int arr1[],int n, int arr2[], int m, int arr3[]){
// 	int i=0, j=0, k=0;

// 	while(i<n && i<m){
// 		if(arr1[i] < arr2[j]){
// 			arr3[k++] = arr1[i++];
// 		}
// 		else{
// 			arr3[k++] = arr2[j++];
// 		}
// 	}

// 	while(j<m){
// 		arr3[k++] = arr2[j++];
// 	}

// 	while(i<n){
// 		arr3[k++] = arr1[i++];
// 	}
	
// }


// int main(){
// 	int arr1[5]={1,3,5,7,9};
// 	int arr2[4]={2,4,6,8};

// 	int arr3[9] = {0};


// 	merge(arr1,5,arr2,4, arr3);

// 	cout<<"Merge 2 sorted array result :-> ";
// 	printArray(arr3,9);
// }




// Move zeroes ---------------
#include<iostream>
#include<vector>
using namespace std;


void moveZero(int arr[], int n){
	int nonZero = 0;
	for(int j=0; j<n; j++){

		if(arr[j] != 0){
			swap(arr[j], arr[nonZero]);
			nonZero++;
		}
	}
}


void printArray(int ans[], int n){
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
}

int main(){

	int arr[6] = {0,1,0,3,12,0};

	cout << "Before shifting zeroes -> ";
	printArray(arr, 6);

	cout<<endl;
	cout<<"After Shifting zeroes to right -> ";
	moveZero(arr, 6);
	printArray(arr, 6);
}