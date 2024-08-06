#include<iostream>
using namespace std;



int main(){

/*
	int n;
	cout << "Enter the size of array";
	cin >> n;

	// Creating 2D array (for 3x3)
	int **arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int[n];
	}



	// Taking input 
	cout << "Enter the elements of an array";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}


	// Output
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

		// releasing memory
	for(int i=0; i<n; i++){
		delete[] arr[i];
	}

	delete[] arr;
*/


	int rows;
	cout << "Enter the no. of rows";
	cin >> rows;

	int cols;
	cout << "Enter the no. of cols";
	cin >> cols;

	// Creating 2D array (for row x cols)
	int **arr2 = new int*[rows];
	for(int i=0; i<rows; i++){
		arr2[i] = new int[cols];
	}



	// Taking input 
	cout << "Enter the elements of an array";
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cin >> arr2[i][j];
		}
	}


	// Output
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}

	// releasing memory
	for(int i=0; i<rows; i++){
		delete[] arr2[i];
	}

	delete[] arr2;

}