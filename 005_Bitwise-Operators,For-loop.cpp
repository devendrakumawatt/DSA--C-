#include<iostream>
using namespace std;

int main(){

	// int a = 4;
	// int b = 6;

	// cout << "a & B = " << (a&b) <<endl;
	// cout << "a | B = " << (a|b) <<endl;
	// cout << "~a = " << (~a) <<endl;
	// cout << "a ^ B = " << (a^b) <<endl;
	// cout << "5<<2 = " << (5<<2) <<endl;
	// cout << "5>>2 = " << (5>>2) <<endl;



	// For loop

	// int n;
	// cout << "Enter the value of n" << endl;
	// cin >> n;

	// cout << "Printing count from 1 to "<< n <<endl;

	// for(int i=1; i<=n; i++){
	// 	cout << i <<endl;
	// }



	// int n;
	// cout <<"enter the value of n" <<endl;
	// cin >> n;
	// int i=1;
	// for( ; ; ){
	// 	if(i <= n){
	// 		cout<< i << endl;
	// 	}
	// 	else{
	// 		break;
	// 	}
	// 	i++;
	// }


	// for(int a=0, b=1; a>=0 && b>=1; a--,b--){
	// 	cout << a << " " << b <<endl;
	// }


	// int n,s=0;
	// cout << "enter the value of n " << endl;
	// cin >> n;
	// for(int i=1; i<=n; i++){
	// 	s=s+i;
	// }
	// cout << "sum is " << s << endl;



	// fibonacci series 

	// int n, a=0, b=1;
	// cout << "enter the value of n"<<endl;
	// cin >> n;
	// cout << a <<" "<< b <<" ";
	// for(int i=1; i<=n; i++){
	// 	int nn = a+b;
	// 	cout << nn <<" " ;
	// 	a=b;
	// 	b=nn;
	// }



	// Prime or Not

	// int n ;
	// cout <<"Enter the value of n"<<endl;
	// cin >> n;
	// bool isPrime = 1;
	// for(int i=2; i<n; i++){
	// 	if(n%i==0){
	// 		cout << "Not a Prime for " <<i<<endl;
	// 		isPrime = 0;
	// 		break;
	// 	}
	// }
	// if(isPrime ==  0){
	// 	cout << n <<" is Not a Prime No." <<endl;
	// }
	// else{
	// 	cout << n <<" is a Prime No." <<endl;
	// }



	// Continue statement

	// for(int i=1; i<=5; i++){
	// 	cout << "Hii" <<endl;
	// 	cout << "Hey" <<endl;
	// 	continue;
	// 	cout << "reply??" <<endl;
	// }



	// Questions

	int n,pro=1,num,sum=0;
	cout << "Enter the value of n" <<endl;
	cin >> n;
	while(n!=0){
		num = n%10;
		pro = pro * num;
		sum = sum + num;
		n = n/10;
	}
	cout << "Product = " <<pro<<endl;
	cout << "Sum = " <<sum<<endl;
	cout << "Product - Sum = " <<pro - sum<<endl;


}