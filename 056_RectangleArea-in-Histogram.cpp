#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

					// ** Largest rectange area in Histogram **
vector<int> nextSmallestElement(vector<int> arr, int n){
	stack<int> s;
	s.push(-1);
	vector<int> ans(n);

	for(int i=n-1; i>=0; i--){
		int curr = arr[i];
		while(s.top() != -1 && arr[s.top()] >= curr){
			s.pop();
		}
		// ans se stack ka top
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}


vector<int> prevSmallestElement(vector<int> arr, int n){
	stack<int> s;
	s.push(-1);
	vector<int> ans(n);

	for(int i=0; i<n; i++){
		int curr = arr[i];
		while(s.top() != -1 && arr[s.top()] >= curr){
			s.pop();
		}
		// ans se stack ka top
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}


int largestRectangleArea(vector<int> &height){
	int n = height.size();

	vector<int> next(n);
	next = nextSmallestElement(height, n);

	vector<int> prev(n);
	prev = prevSmallestElement(height, n);

	int area = INT_MIN;
	for(int i=0; i<n; i++){
		int l = height[i];
		if(next[i] == -1){
			next[i] = n;
		}
		int b = next[i] - prev[i] - 1;

		int newArea = l*b;
		area = max(area, newArea);
	}
	return area;
}



int main(){
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int area = largestRectangleArea(height);
    cout << "The largest rectangle area is: " << area << endl;
}









/*						// ** Next Smaller Element **
vector<int> nextSmallElement(vector<int> &arr, int n){

	stack<int> s;
	s.push(-1);
	vector<int> ans(n);

	for(int i=n-1; i>=0; i--){
		int curr = arr[i];
		while(s.top() >= curr){
			s.pop();
		}
		// ans se stack ka top
		ans[i] = s.top();
		s.push(curr);
	}
	return ans;
}

int main(){
	vector<int> arr = {2, 1, 4, 3};
	int size = arr.size();
	cout << "Given Array : ";

	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}cout << endl;

	cout << "Output Array : ";
	vector<int> ans = nextSmallElement(arr, size);

	for(int i=0; i<size; i++){
		cout << ans[i] << " ";
	}cout << endl;
}
*/