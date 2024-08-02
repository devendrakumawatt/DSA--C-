#include<iostream>
using namespace std;

// int main(){

// 	char ch;
// 	cout << "Enter the value of ch" <<endl;
// 	cin >> ch;

// 	if(ch >= 'A' && ch <= 'Z') {
// 		cout << "This is uppercase" <<endl;
// 	}
// 	else if(ch >= 'a' && ch <= 'z') {
// 		cout << "This is lowercase" <<endl;
// 	}
// 	else if(ch >= '0' && ch<= '9') {
// 		cout << "This is numerical" <<endl;
// 	}
// 	else{
// 		cout << "Special character" <<endl;
// 	}
// }



// ------------------------------------------

int main(){

	// int n,i = 1;
	// cout << "Enter the value of n" <<endl;
	// cin >> n;
	// while(i <= n){
	// 	cout << i <<endl;
	// 	i = i+1;
	// }


	// int a, s=0, i=1;
	// cout << "Enter the value of a" <<endl;
	// cin >> a;
	// while(i <= a){
	// 	cout << "i = " << i <<endl;
	// 	i = i+1;
	// 	s = s+i;
	// }
	// cout << "Sum = " << s <<endl;




	// int num, i=0;
	// cout <<"Enter the value of num"<<endl;
	// cin >> num;
	// while(i <= num){
	// 	cout << i <<endl;
	// 	i = i+2;
	// }



	int p, i=2;
	cout <<"enter the value of p"<<endl;
	cin >> p;
	while(i < p){
		if(p%i == 0){
			cout << "not prime for" <<i<<endl;
		}
		else{
			cout << "prime for" <<i<<endl;
		}
		i = i+1;
	}

}