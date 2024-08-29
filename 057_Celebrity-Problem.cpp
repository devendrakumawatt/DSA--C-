#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

					// ** The Celebrity Problem **
bool knows(vector<vector<int>> &M, int a, int b, int n){
	if(M[a][b] == 1){
		return true;
	}
	else{
		return false;
	}
}

int celebrity(vector<vector<int>> &M, int n){
	stack<int> s;
	// push all element
	for(int i=0; i<n; i++){
		s.push(i);
	}

	// get two element and compare them
	while(s.size() > 1){
		int a = s.top();
		s.pop();

		int b = s.top();
		s.pop();

		if(knows(M, a, b, n)){
			s.push(b);
		}
		else{
			s.push(a);
		}
	}
	int ans = s.top();

	// single element in stack is potential celeb ,so verify it

	int zeroCount = 0;
	for(int i=0; i<n; i++){
		if(M[ans][i] == 0){
			zeroCount++;
		}
	}
	// all zeroes
	if(zeroCount != n){
		return -1;
	}

	// column rowCheck
	int oneCount = 0;
	for(int i=0; i<n; i++){
		if(M[i][ans] == 1){
			oneCount++;
		}
	}
	if(oneCount != n-1){
		return -1;
	}
	return ans;
}

int main(){
	vector<vector<int>> M = {{0,1,0}, {0,0,0}, {0,1,0}};
	int size = M.size();

	cout << "Given Input Matrix : " << endl;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout << "  " << M[i][j] <<" ";
		}cout<<endl;
	}

	int ans = celebrity(M, size);

	if(ans == -1){
		cout << "There is no celebrity" << endl;
	}
	else{
		cout << "The celebrity is : " << ans << endl;
	}
}





/*						// ** Maximum rectangle area in binary matrix **
vector<int> nextSmallestElement(int *arr, int n){
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


vector<int> prevSmallestElement(int *arr, int n){
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

int largestRectangleArea(int *height, int n){
	// int n = height.size();

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

int maxArea(int M[4][4], int n, int m){
	int area = largestRectangleArea(M[0], m);

	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			// row update-by adding previous row's value
			if(M[i][j] != 0){
				M[i][j] = M[i][j] + M[i-1][j];
			}
			else{
				M[i][j] = 0;
			}
			// entire row updated
			int newArea = largestRectangleArea(M[i], m);
			area = max(area, newArea);
		}
	}
	return area;
}


int main(){
	int arr[4][4] = {{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
	int n = 4;
	int m = 4;

	cout << "Given Matrix : " << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << "   " << arr[i][j] << " ";
		}cout<<endl;
	}

	int ans = maxArea(arr, n, m);

	cout << "Maximum Area rectangle is : " << ans << endl;

}
*/