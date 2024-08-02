// Swap Alternate ------

// #include<iostream>
// using namespace std;

// void printArray(int arr[], int n){
// 	for(int i=0; i<n; i++){
// 		cout << arr[i] <<" ";
// 	}
// 	cout << endl;
// }

// void swapAlternate(int arr[], int size){
// 	for(int i=0; i<size; i=i+2){
// 		if(i+1 < size){
// 			swap(arr[i], arr[i+1]);
// 		}
// 	}
// }

// int main(){

// 	int even[8] = {5,7,2,9,1,4,8,3};
// 	int odd[7] = {2,6,7,8,1,4};

// 	cout << "Before Swapp --- "<<endl;

// 	cout << "Even Array - ";
// 	printArray(even, 8) ;

// 	cout << "Odd Array - " ;
// 	printArray(odd, 5) ;

// 	cout << " -------- " << endl;


// 	swapAlternate(even, 8);
// 	swapAlternate(odd, 5);

// 	cout << "After Swapp --- "<<endl;
// 	cout << "Even Array - "; 
// 	printArray(even, 8) ;
// 	cout << "Odd Array - " ;
// 	printArray(odd, 5) ;
// }


// -------------------------------------------


// Find Unique Element 
// #include<iostream>
// using namespace std;

// int main(){

// 	int ans = 0;
// 	int arr[7] = {1,3,5,6,1,3,5};

// 	for(int i=0; i<7; i++){
// 		ans = ans ^ arr[i];
// 	}
// 	cout << " Unique Element is = " << ans << endl;
// }



// -----------------------------------------------

// Find duplicate Element 
// #include<iostream>
// using namespace std;

// int main(){

// 	int ans = 0;
// 	int arr[9] = {1,2,3,4,5,6,7,8,2};

// 	for(int i=0; i<9; i++){
// 		ans = ans ^ arr[i];
// 	}
// 	cout << ans <<endl;
// 	for(int i=1; i<9; i++){

// 		ans = ans ^ i;
// 	}

// 	cout << "Duplicate element = "<<ans<<endl;
// }




// --------------------------------------------

// Sort 0/1

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


void sortOne(int arr[], int n){
	int i = 0, j = n-1;

	while(i < j){
		while(arr[i] == 0){
			i++;
		}
		while(arr[j] == 1){
			j--;
		}

		swap(arr[i],arr[j]);
		i++;
		j--;
	}
}


int main(){

	int arr[8] = {1,0,1,1,0,0,1,0};

	cout << "Before sorting ---" <<endl;
	cout << "Arr - " ;
	printArray(arr,8);

	cout<<endl;
	sortOne(arr, 8);

	cout << "After sorting ---" <<endl;
	cout << "Arr - ";
	printArray(arr, 8);
}