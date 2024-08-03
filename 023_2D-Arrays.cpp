// Linear search in 2D array
// Row-wise sum
// Largest row sum
// wave order print
// spiral order print
// Binary search in 2D array
// Binary search in 2D array L2

#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

bool isPresent(int arr[][3], int target, int i, int j){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(arr[i][j] == target){
				return 1;
			}
		}
	}
	return 0;
}

void printSum(int arr[][3], int i, int j){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum = sum + arr[i][j];
		}
		cout<<"Sum of "<<i<<"th row : "<<sum<<endl;
	}
}

int largestRowSum(int arr[][3],int i, int j){
	int maxi = INT_MIN;
	int rowIdx = -1;
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum = sum + arr[i][j];
		}
		cout<<"Sum of "<<i<<"th row : "<<sum<<endl;
		if(sum>maxi){
			maxi = sum;
			rowIdx = i;
		}
	}
	cout << "The maximum row sum is : "<<maxi<<endl;
	return rowIdx;
}



void wavePrint(int arr[][3], int row, int col){
	for(int j=0; j<col; j++){
		if(j&1){
			for(int i=row-1; i>=0; i--){
				cout<<arr[i][j] << " ";
			}
		}
		else{
			for(int i=0; i<row; i++){
				cout<<arr[i][j] << " ";
			}
		}
	}
}

vector<int> spiralOrder(vector<vector<int>> &matrix){

	vector<int> ans;
	int row = matrix.size();
	int col = matrix[0].size();

	int count = 0;
	int total = row*col;

	int stratingRow = 0;
	int stratingCol = 0;
	int endingRow = row-1;
	int endingCol = col-1;

	while(count < total){
		for(int idx=stratingCol; count < total && idx<=endingCol; idx++){
			ans.push_back(matrix[stratingRow][idx]);
			count++;
		}
		stratingRow++;

		for(int idx=stratingRow; count < total && idx<=endingRow; idx++){
			ans.push_back(matrix[idx][endingCol]);
			count++;
		}
		endingCol--;

		for(int idx=endingCol; count < total && idx>=stratingCol; idx--){
			ans.push_back(matrix[endingRow][idx]);
			count++;
		}
		endingRow--;

		for(int idx=endingRow; count < total && idx>=stratingRow; idx--){
			ans.push_back(matrix[idx][stratingCol]);
			count++;
		}
		stratingCol++;
	}
	return ans;
}

bool searchMatrix(vector<vector<int>> &matrix, int target){
	int row = matrix.size();
	int col = matrix[0].size();

	int s = 0;
	int e = row*col-1;

	int mid = s + (e - s)/2;
	while(s <= e){

		int element = matrix[mid/col][mid%col];

		if(element == target){
			return 1;
		}
		if(element < target){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
		mid = s + (e - s)/2;
	}
	return 0;
}


bool searchMatrix2(vector<vector<int>> &matrix2, int target){
	int row = matrix2.size();
	int col = matrix2[0].size();

	int rowIdx = 0;
	int colIdx = col - 1;

	while(rowIdx < row && colIdx >= 0){
		int element = matrix2[rowIdx][colIdx];

		if(element == target){
			return 1;
		}
		if(element < target){
			rowIdx++;
		}
		else{
			colIdx--;
		}
	}
	return 0;
}




int main(){

	// int arr[3][3];
	// cout<<"Enter the elements of array : "<<endl;

	// for(int i=0; i<3; i++){
	// 	for(int j=0; j<3; j++){
	// 		cin >> arr[i][j];
	// 	}
	// }

	// cout<<"Values of array are : "<<endl;
	// for(int i=0; i<3; i++){
	// 	for(int j=0; j<3; j++){
	// 		cout << arr[i][j] <<" ";
	// 	}
	// 	cout<<endl;
	// }


	// cout<<"Enter the element to search : "<<endl;
	// int target;
	// cin >> target;

	// if(isPresent){
	// 	cout<<"Element "<<target<<" found"<<endl;
	// }
	// else{
	// 	cout<<"Element "<<target<<" not found"<<endl;
	// }

	// printSum(arr,3,3);


	// int ansIdx = largestRowSum(arr, 3, 3);
	// cout<<"Maximum row sum is at Index : "<<ansIdx<<endl;


	// cout<<"Wave order printing array : ";
	// wavePrint(arr,3,3);



	// vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

	// vector<int> result = spiralOrder(matrix);

	// cout << "Spiral print : "<<endl;

	// for(int num : result){
	// 	cout << num << " ";
	// }



	// vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	// bool result = searchMatrix(matrix,16);
	// cout << "Binary Search in 2D"<<endl;
	// cout << "Is Target element present : "<<result<<endl;



	vector<vector<int>> matrix2 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};
	bool res = searchMatrix2(matrix2,22);
	cout << "Binary Search in 2D L2"<<endl;
	cout << "Is Target element present matrix2 : "<<res<<endl;


}