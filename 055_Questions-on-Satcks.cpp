#include<iostream>
#include<stack>
using namespace std;

							// ** Find Minimum cost for valid expression **
int findMinimumCost(string str){
	// odd condition
	if(str.length()%2 == 1){
		return -1;
	}

	stack<char> s;
	for(int i=0; i<str.length(); i++){
		char ch = str[i];

		if(ch == '{'){
			s.push(ch);
		}
		else{
			// ch is closed brace
			if(!s.empty() && s.top() == '{'){
				s.pop();
			}
			else{
				s.push(ch);
			}
		}
	}
	// stack contains invalid expression
	int a = 0, b = 0;
	while(!s.empty()){
		if(s.top() == '{'){
			b++;
		}
		else{
			a++;
		}
		s.pop();
	}
	int ans = (a+1)/2 + (b+1)/2;
	return ans;
}


int main(){
	string str = "}}}}{{{{";

	cout << "Given expression : " << str << endl;

	int ans = findMinimumCost(str);
	cout << "Minimum Cost for valid expression is : " << ans << endl;
}










/*						// ** Find Redundant brackets **

bool findRedundantBrackets(string &str){
	stack<char> s;
	for(int i=0; i<str.length(); i++){
		char ch = str[i];

		if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			s.push(ch);
		}
		else{
			// ch yaa toh ')' hai yaa lowercase letter
			if(ch == ')'){
				bool isRedundant = true;
				while(s.top() != '('){
					char top = s.top();
					if(top == '+'|| top == '-' || top == '*' || top == '/'){
						isRedundant = false;
					}
					s.pop();
				}
				if(isRedundant == true){
					return true;
				}
				s.pop();
			}
		}
	}
	return false;
}


int main(){
	string str = "((a*(b+c)))";

	cout << "Given expression : " << str << endl;

	if(findRedundantBrackets(str)){
		cout << "Expression have redundant brackets" << endl;
	}
	else{
		cout << "Expression do not have redundant brackets" << endl;
	}

}
*/









/*					// ** Sort a stack **
void sortedInsert(stack<int> &st, int num){
	// base case
	if(st.empty() || (!st.empty() && st.top() < num)){
		st.push(num);
		return;
	}

	int n = st.top();
	st.pop();

	// recursive call
	sortedInsert(st, num);
	st.push(n);
}

void sortStack(stack<int> &s){
	// base case
	if(s.empty()){
		return;
	}

	int num = s.top();
	s.pop();

	// recursive call
	sortStack(s);

	sortedInsert(s, num);
}

int main(){
	stack<int> s;
	s.push(5);
	s.push(-2);
	s.push(9);
	s.push(-7);
	s.push(3);

	stack<int> temp = s;
	cout << "Given stack : ";
	while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(s);

    cout << "Sorted stack : ";
	while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}
*/






/* 				// ** Reversed the stack using recursion **

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
*/






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