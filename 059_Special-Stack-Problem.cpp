#include<iostream>
#include<stack>
using namespace std;

class SpecialStack {
public:
	stack<int> s;
	int mini;

	void push(int data){
		// for first element
		if(s.empty()){
			s.push(data);
			mini = data;
		}
		else{
			if(data < mini){
				s.push(2*data - mini);
				mini = data;
			}
			else{
				s.push(data);
			}
		}
	}

	int pop(){
		if(s.empty()){
			return -1;
		}

		int curr = s.top();
		s.pop();
		if(curr > mini){
			return curr;
		}
		else{
			int prevMin = mini;
			int val = 2*mini - curr;
			mini = val;
			return prevMin;
		}
	}

	int top(){
		if(s.empty()){
			return -1;
		}

		int curr = s.top();
		if(curr < mini){
			return mini;
		}
		else{
			return curr;
		}
	}

	bool isEmpty(){
		return s.empty();
	}

	int getMin(){
		if(s.empty()){
			return -1;
		}
		return mini;
	}
};



int main(){
	SpecialStack st;
    st.push(3);
    cout << "Min: " << st.getMin() << endl;
    st.push(5);
    cout << "Min: " << st.getMin() << endl;
    st.push(2);
    cout << "Min: " << st.getMin() << endl;
    st.push(1);
    cout << "Min: " << st.getMin() << endl << endl;

    cout << "Top: " << st.top() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Min: " << st.getMin() << endl;

}