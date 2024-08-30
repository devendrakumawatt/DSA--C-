#include<iostream>
using namespace std;

class NStack {
public:
	int *arr;
	int *top;
	int *next;

	int n, s;

	int freespot;

	NStack(int N, int S){
		n = N;
		s = S;
		arr = new int[s];
		top = new int[n];
		next = new int[s];

		// top initialisation
		for(int i=0; i<n; i++){
			top[i] = -1;
		}

		// next initialisation
		for(int i=0; i<s; i++){
			next[i] = i+1;
		}

		// update last index value to -1
		next[s-1] = -1;

		// initialise freespot
		freespot = 0;
	}

	// Destructor
    ~NStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }


	// Push 'x' into the mth stack, returns true if it gets pushed into the stack and false otherwise
	bool push (int x, int m){
		// check for overflow
		if(freespot == -1){
			return false;
		}

		// find index
		int index = freespot;

		// update freespot
		freespot = next[index];

		// insert element into array
		arr[index] = x;

		// update next
		next[index] = top[m-1];

		// update top
		top[m-1] = index;

		return false;
	}

	// /Pop top element from mth stack , return -1 if the stack is empty
	int pop(int m){

		// check underflow condition
		if(top[m-1] == -1){
			return -1;
		}

		int index = top[m-1];

		top[m-1] = next[index];

		next[index] = freespot;

		freespot = index;

		return arr[index];
	}
};

int main(){
	NStack stacks(3, 10); // 3 stacks and 10 elements

    cout << stacks.push(5, 1) << endl;
    cout << stacks.push(10, 2) << endl;
    cout << stacks.push(15, 1) << endl;

    cout << stacks.pop(1) << endl;
    cout << stacks.pop(2) << endl;
    cout << stacks.pop(1) << endl;
    cout << stacks.pop(1) << endl;
}