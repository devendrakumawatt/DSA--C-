#include <iostream>
using namespace std;


int main()
{
    // int n;
    // cout << "Enter the value of n";
    // cin >> n;

    // cout << "value of n is : "<< n << endl;

    // if n positive
   //  if(n>0){
   //      cout<<"N is positive" << endl;
   // }
   // // if n is negative
   // else{
   //  cout<<"N is negative" <<endl;
   // }

//-----------------------------------------------------

   // int a,b;
   // cout << "Enter the value of a" <<endl;
   // cin >> a;
   // cout << "Enter the value of b" <<endl;
   // cin >> b;
   // cout << "Value of a and b is " << a << b <<endl;

   // // if A>B
   // if(a>b){
   //  cout << "A is greater" <<endl;
   // }
   // // if B>A
   // if(b>a){
   //  cout << "B is greater" <<endl;
   // }

//-------------------------------------------------------

    int a;
    cout << "Enter the value of a" <<endl;
    cin >> a;
    if(a>0){
        cout << "A is positive" <<endl;
    }
    else if(a<0){
        cout << "A is negative" <<endl;
    }
    else{
        cout << "A is Zero" <<endl;
    }


    return 0;
}