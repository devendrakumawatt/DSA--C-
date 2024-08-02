#include <iostream>
#include<math.h>
using namespace std;

int main(){


	// Decimal to Binary

	// int n;
	// cout << "Enter the value of n" <<endl;
	// cin >> n;
	// int i=0;
	// float ans=0;

	// while(n!=0){
	// 	int bit = n & 1;
	// 	ans = (bit * pow(10 , i)) + ans;
	// 	n = n >> 1;
	// 	i++;
	// }
	// cout << "Answer = " << ans <<endl;




		// Binary to decimal

	int n;
	cout << "Enter the binary no. of n" << endl;
	cin >> n;
	int i=0;
	int ans=0;
	while(n!=0){
		int digit = n%10;
		if(digit == 1){
			ans = ans + pow(2,i);
		}
		n = n/10;
		i++;
	}
	cout << "Answer = " <<ans<<endl;
}