#include<iostream>
using namespace std;

/*			// Reaverse a string

void reverseString(string &str, int i, int j){

	// cout << "Recursive string step : " << str << endl;
	// base case
	if(i>j)
		return ;

	swap(str[i], str[j]);
	i++;
	j--;

	//recursive call
	reverseString(str, i, j);
}

int main(){

	string name = "deva";
	cout << "Input : "<< name << endl;
	reverseString(name, 0, name.length()-1);

	cout << "Output : " << name << endl;

}
*/




/*			// Check Palindrome


bool checkPalindrome(string &str, int i, int j){
	// base case
	if(i > j)
		return true;

	if(str[i] != str[j])
		return false;
	else
		// recursive call
		return checkPalindrome(str, i+1, j-1);

}

int main(){
	string name = "abbccbba";
	bool isPalindrome = checkPalindrome(name, 0, name.length()-1);

	if(isPalindrome)
		cout << name << " is a palindrome string" << endl;
	else
		cout << name << " is not a palindrome string" << endl;

}

*/



/*				// Power of b to a

int power(int a, int b){
	// base case
	if(b == 0)
		return 1;

	if(b == 1)
		return a;

	// recursive call
	int ans = power(a, b/2);

	//if b is even
	if(b%2 == 0)
		return ans * ans;
	else
		return a * ans * ans;
}

 
int main(){

	int a, b;
	cout << "Enter the value of a and b : " << endl;
	cin >> a >> b;

	int ans = power(a,b);
	cout << "answer is : " << ans << endl;

}
*/


			// Bubble sort

void bubbleSort(int arr[], int n){
	// base case
	if(n == 0 || n == 1)
		return ;

	for(int i=0; i<n-1; i++){
		if(arr[i] > arr[i+1])
			swap(arr[i], arr[i+1]);
	}

	bubbleSort(arr, n-1);
}


int main(){

	int arr[5] = {2,5,1,9,6};
	cout << "Unsorted array : ";
	for(int i=0; i<5; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	bubbleSort(arr, 5);

	cout << "Sorted array : " ;
	for(int i=0; i<5; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}