#include<iostream>
#include<math.h>
using namespace std;

int main(){

// Leetcode problem -1 

	// int num ,digit, ans=0;
	// // int INT_MAX = pow(2,30);
	// // int INT_MIN = (pow(2,30) - 1);
	// cout << "Enter a number" << endl;
	// cin >> num;
	// while(num != 0){
	// 	digit = num%10;
	// 	if((ans > (INT_MAX/10)) || (ans < (INT_MIN/10))){
	// 		cout << "Answer = " << 0 <<endl ;
	// 	}
	// 	ans = (ans * 10) + digit;
	// 	num = num / 10;
	// }
	// cout << "Answer = " << ans << endl;




// Leetcode problem -2


	// int num, ans, mask=0;
	// cout << "Enter a number" <<endl;
	// cin >> num;

	// if(num == 0){
	// 	cout << "Answer = " << 1 <<endl;
	// }
	// while(num != 0){
	// 	mask = (mask << 1) | 1;
	// 	num = num >> 1;
	// }
	// ans = ((~num) & (mask));
	// cout << "Answer = " << ans <<endl;





	int n,i,ans;
	cout << "Enter a number" <<endl;
	cin >> n;

	for(i=0; i<=30; i++){
		ans = pow(2,i);

		if(ans == n){
		cout << "True" <<endl;
		}
	}
	return false;	
	
}