#include<iostream>
#include<stack>
using namespace std;

class TwoStack {
public:

	int *arr;
	int top1;
	int top2;
	int size;

	TwoStack(int s){
		this->size = s;
		top1 = -1;
		top2 = s;
		arr = new int[s];
	}

	// push in stack1
	void push1(int num){
		if(top2 - top1 > 1){
			top1++;
			arr[top1] = num;
		}
		else{
			cout << "Stack Overflow" << endl;
		}
	}

	// push in stack2
	void push2(int num){
		if(top2 - top1 > 1){
			top2++;
			arr[top2] = num;
		}
		else{
			cout << "Stack Overflow" << endl;
		}
	}

	// pop from stack1 and return popped elemnet
	int pop1(){
		if(top1 >= 0){
			int ans = arr[top1];
			top1--;
			return ans;
		}
		else{
			return -1;
		}
	}

	// pop from stack2 and return popped elemnet
	int pop2(){
		if(top2 >= 0){
			int ans = arr[top2];
			top2--;
			return ans;
		}
		else{
			return -1;
		}
	}

};






/* 				// ** Stack Impletation using class **
class Stack {
public:
	int *arr;
	int top;
	int size;

	Stack (int size){
		this->size = size;
		arr = new int[size];
		top = -1;
	}

	void push(int element){
		if(size-top > 1){
			top++;
			arr[top] = element;
		}
		else{
			cout << "Stack Overflow" << endl;
		}
	}

	void pop(){
		if(top >= 0){
			top--;
		}
		else{
			cout << "Stack Underflow" << endl;
		}
	}

	int peek(){
		if(top >=0){
			return arr[top];
		}
		else{
			cout << "Stack is Empty" << endl;
			return -1;
		}
	}

	bool isEmpty(){
		if(top == -1){
			return true;
		}
		else{
			return false;
		}
	}

};
*/


int main(){

	TwoStack st(6);
	st.push1(22);
	st.push1(43);
	st.push1(41);

	st.push2(44);
	st.push2(21);
	st.push2(66);

	cout << "Popped element from satck1 : " << st.pop1() << endl;
	cout << "Popped element from satck1 : " << st.pop1() << endl << endl;
	cout << "Popped element from satck2 : " << st.pop2() << endl;
	cout << "Popped element from satck2 : " << st.pop2() << endl;

	
	






/*
	Stack st(5);

	st.push(22);
	st.push(43);
	st.push(44);
	st.push(55); 

	cout << "Top element is : " << st.peek() << endl;
	st.pop();
	cout << "Top element is : " << st.peek() << endl;
	st.pop();
	cout << "Top element is : " << st.peek() << endl;
	st.pop();
	cout << "Top element is : " << st.peek() << endl;
	st.pop();
	cout << "Top element is : " << st.peek() << endl;

	if(st.isEmpty()){
		cout << "Stack is empty !!" << endl;
	}
	else{
		cout << "Stack is not empty !!" << endl;
	}

*/


/*
	// Creation of stack
	stack<int> s;

	// push
	s.push(2);
	s.push(3);
	s.push(4);

	// pop
	s.pop();

	cout << "printing top element : " << s.top() << endl;

	if(s.empty()){
		cout << "stack is empty" << endl; 
	}
	else{
		cout << "stack is not empty" << endl;
	}

	cout << "Size of stack is : " << s.size() <<endl;

*/
}