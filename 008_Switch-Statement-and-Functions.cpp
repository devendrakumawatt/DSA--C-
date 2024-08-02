// #include<iostream>
// using namespace std;

// int main(){
	// int num;
	// cout << "Enter a case" <<endl;
	// cin >> num;

	// switch(num){
	// case 1:
	// 	cout <<"First"<<endl;
	// 	break;
	
	// case 2:
	// 	cout <<"Second"<<endl;
	// 	break;
	
	// case 3:
	// 	cout <<"Third"<<endl;
	// 	break;

	// default: 
	// 	cout <<"Default"<<endl;
	// }



// Calculator
	// char op;
	// int a,b,ans;
	// cout << "Enter value of a" <<endl;
	// cin >> a;
	// cout << "Enter value of b" <<endl;
	// cin >> b;
	// cout << "Enter a operation" <<endl;
	// cin >> op;

	// switch(op){
	// case '+':
	// 	ans = a+b;
	// 	cout <<ans<<endl;
	// 	break;
	
	// case '-':
	// 	ans = a-b;
	// 	cout <<ans<<endl;
	// 	break;
	
	// case '*':
	// 	ans = a*b;
	// 	cout <<ans<<endl;
	// 	break;

	// case '/':
	// 	ans = a/b;
	// 	cout <<ans<<endl;
	// 	break;

	// case '%':
	// 	ans = a%b;
	// 	cout <<ans<<endl;
	// 	break;

	// default: 
	// 	cout <<"Default"<<endl;
	// }




// -----------------------------------
	// int amount = 1330;
	// int note;
	// cout << "Enter which no. of notes you want to know " << endl;
	// cin >> note;

	// switch(note){
	// case 100:
	// 	cout <<"No. of 100's notes = 13"<<endl;
	// 	break;
	
	// case 50:
	// 	cout <<"No. of 50's notes = "<<endl;
	// 	break;
	
	// case 20:
	// 	cout <<"No. of 20's notes = 1"<<endl;
	// 	break;

	// case 10:
	// 	cout <<"No. of 10's notes = 1"<<endl;
	// 	break;

	// default: 
	// 	cout <<"Default"<<endl;
	// }
// }





// FUNCTIONS ---------

// #include<iostream>
// using namespace std;

// int power(){
// 	int a,b;
// 	cout << "Enter the value of a and b"<<endl;
// 	cin >> a >> b;
// 	int ans = 1;
// 	for(int i=1; i<=b; i++){
// 		ans = ans*a;
// 	}
// 	return ans;
// }

// int main(){
// 	// int a,b;
// 	// cout << "Enter the value of a and b"<<endl;
// 	// cin >> a >> b;

// 	int ans = power();
// 	cout << "Answer is = "<<ans<<endl;
// }





// #include<iostream>
// using namespace std;

// bool isEven(int a){
// 	if(a&1){
// 		return 0;
// 	}
// 	return 1;
// }

// int main(){
// 	int num;
// 	cout <<"Enter the num" <<endl;
// 	cin >> num;

// 	if(isEven(num)){
// 		cout << "Number is Even" <<endl;	
// 	}
// 	else{
// 		cout << "Number is Odd" <<endl;
// 	}
	
// }



// #include<iostream>
// using namespace std;


//  int factorial(int n){
//  	int fact = 1;
//  	for(int i=1; i<=n; i++){
//  		fact = fact*i;
//  	}
//  	return fact;
//  }

//  int nCr(int n, int r){
//  	int num = factorial(n);
//  	int deno = factorial(r) * factorial(n-r);
//  	int ans = num/deno;
//  	return ans;
//  }

//  int main(){

//  	int n, r;
//  	cout << "Enter the value of n,r"<<endl;
//  	cin >>n>>r;

//  	cout << "The nCr of "<<n<<" C "<<r<<" is = "<<nCr(n,r)<<endl;
//  }




// #include<iostream>
// using namespace std;

// void printCounting(int n){

// 	for(int i=1; i<=n; i++){
// 		cout << i << " " ;
// 	}
// 	cout<<endl;
// }

// int main(){
// 	int n;
// 	cout << "Enter the no. to count upto"<<endl;
// 	cin >>n;

// 	printCounting(n);
// }




// PRIME NUMBER -----------

#include<iostream>
using namespace std;

bool isPrime(int n){
	for(int i=2; i<n; i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;

}

int main(){

	int num;
	cout << "Enter a no. to check prime or not"<<endl;
	cin >> num;
	if(isPrime(num)){
		cout << num << " is a Prime No." <<endl;
	}
}