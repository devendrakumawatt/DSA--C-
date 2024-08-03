// Rotate an Array ---------------------
// #include<iostream>
// #include<vector>
// using namespace std;


// void rotateArray(vector<int>& num, int k){
// 	vector<int> temp(num.size());

// 	for(int i=0; i<num.size(); i++){
// 		temp[(i+k)%num.size()] = num[i];
// 	}
// 	num = temp;
// }

// void printArray(vector<int> v){
// 	for(int i=0; i<v.size(); i++){
// 		cout<<v[i]<<" ";
// 	}
// }

// int main(){

// 	vector<int> v;

// 	v.push_back(1);
// 	v.push_back(7);
// 	v.push_back(9);
// 	v.push_back(11);
// 	v.push_back(15);


// 	cout<<"Before Rotating array : -> ";
// 	printArray(v);

// 	rotateArray(v,2);

// 	cout<<endl;
// 	cout<<"After Rotating array : -> ";
// 	printArray(v);

// }




// Check an array is Sorted and Rotated----------------------
// #include<iostream>
// #include<vector>
// using namespace std;


// bool checkArray(vector<int>& num){
// 	int count = 0;
// 	int n = num.size();

// 	for(int i=1; i<n; i++){
// 		if(num[i+1] > num[i]){
// 			count++;
// 		}
// 	}
// 	if(num[n-1] > num[0]){
// 		count++;
// 	}
// 	return count <= 1;
// }

// void printArray(vector<int> v){
// 	for(int i=0; i<v.size(); i++){
// 		cout<<v[i]<<" ";
// 	}
// }

// int main(){

// 	vector<int> v;

// 	v.push_back(3);
// 	v.push_back(4);
// 	v.push_back(5);
// 	v.push_back(1);
// 	v.push_back(2);

	
// 	cout<<"Is Array sorted & rotated : -> ";
// 	cout<<checkArray(v);

// }





// Sum of arrays ----------------------
#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v) {
	int s=0;
	int e = v.size()-1;

	while(s<e){
		swap(v[s++], v[e--]);
	}

	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	return v;
}

vector<int> sumArray(vector<int> &arr1, int n, vector<int> &arr2, int m){
	int i = n-1;
	int j = m-1;

	vector<int> ans;
	int carry = 0;

	while(i>=0 && j>=0){
		int val1 = arr1[i];
		int val2 = arr2[j];

		int sum = val1 + val2 + carry;

		carry = sum / 10;
		int value = sum % 10;
		ans.push_back(value);
		i--;
		j--;
	}

	while(i>=0){
		int sum = arr1[i] + carry;
		carry = sum / 10;
		int value = sum % 10;
		ans.push_back(value);
		i--;
	}

	while(j>=0){
		int sum = arr2[j] + carry;
		carry = sum / 10;
		int value = sum % 10;
		ans.push_back(value);
		j--;
	}

	while(carry != 0){
		int sum = carry;
		carry = sum / 10;
		int value = sum % 10;
		ans.push_back(value);
	}

	return reverse(ans);
}


int main(){
	vector<int> arr1;
	arr1.push_back(3);
	arr1.push_back(4);
	arr1.push_back(5);

	vector<int> arr2;
	arr2.push_back(9);
	arr2.push_back(6);

	// vector<int> ans;

	cout<< "Sum of arr1 and arr2 is :-> ";
	sumArray(arr1, 3, arr2, 2);
}