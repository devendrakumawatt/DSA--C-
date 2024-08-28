#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &rev, int x){
	// base case
	if(rev.empty()){
		rev.push(x);
		return;
	}

	int num = rev.top();
	rev.pop();

	// recursive call
	insertAtBottom(rev, x);
	rev.push(num);
}

void reverseStack(stack<int> &stc){
	// base case
	if(stc.empty()){
		return;
	}

	int num = stc.top();
	stc.pop();

	// recursion call
	reverseStack(stc);

	insertAtBottom(stc, num);
}

int main(){
	stack<int> s;
	s.push(3);
	s.push(4);
	s.push(7);
	s.push(9);

	stack<int> temp = s;
	cout << "Given stack : ";
	while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "Reversed Stack using recursion : ";
	while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;	

}






/* 				// ** Insert an element at bottom of stack **
void solve(stack<int> &s ,int x){
	// base case
	if(s.empty()){
		s.push(x);
		return;
	}

	int num = s.top();
	s.pop();

	// recursive call
	solve(s, x);
	s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack , int x){
	solve(myStack, x);
	return myStack;
}


int main(){
	stack<int> s;
	s.push(7);
	s.push(1);
	s.push(4);
	s.push(5);

	stack<int> temp = s;
	cout << "Given stack : ";
	while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int X = 9;
    pushAtBottom(s, X);

    cout << "Stack after adding element : ";
	while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
*/





/* 				// ** Check valid expression ** 
bool isValidParenthesis(string exp){
	stack<char> s;
	for(int i=0; i<exp.length(); i++){
		char ch = exp[i];

		// if opening bracket, stack push
		// if closing bracket, stacktop check and pop

		if(ch == '[' || ch == '{' || ch == '('){
			s.push(ch);
		}
		else{
			// for close bracket
			if(!s.empty()){
				char top = s.top();
				if((ch == ']' && top == '[') || 
					(ch == '}' && top == '{') || 
					(ch == ')' && top == '(')){
					s.pop();
				}
				else
					return false;
			}
			else
				return false;
		}
	}
	if(s.empty())
		return true;
	else
		return false;
}


int main(){
	string str = "[{}]";
	cout << "Given Experession : " << str << endl;
	cout << "Is it valid Experession : ";

	if(isValidParenthesis(str)){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
}
*/





/* 				// ** Delete Middle Element in stack **

void solve(stack<int> &inputStack, int count, int n){
	// base case
	if(count == n/2){
		inputStack.pop();
		return;
	}

	int num = inputStack.top();
	inputStack.pop();

	// recursive call
	solve(inputStack, count+1, n);
	inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int n){
	int count = 0;
	solve(inputStack, count, n);
}

int main(){
	stack<int> st;
	st.push(5);
	st.push(9);
	st.push(12);
	st.push(8);
	st.push(4);

	int size = 5;
	stack<int> temp = st;
	cout << "Given stack : " ;
	while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

	deleteMiddle(st, 5);

	cout << "Updated stack : ";
	while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
*/







/*				// ** Reverse a String using Stack **

int main(){
	string str = "DEVENDRA";
	cout << "Given string : " << str << endl;

	stack<char> s;

	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		s.push(ch);
	}

	string ans = "";
	while(!s.empty()){
		char ch = s.top();
		ans.push_back(ch);
		s.pop();
	}
	cout << "Reversed string : " << ans << endl;
}
*/