#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newX, int newY, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n){
	if((newX >=0 && newX < n) && (newY >= 0 && newY < n) && vis[newX][newY] != 1 && arr[newX][newY] == 1){
		return true;
	}
	else{
		return false;
	}
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path){
	// base case
	if(x == n-1 && y == n-1){
		ans.push_back(path);
		return;
	}

	// 4 Movements - D, L, R, U
	vis[x][y] = true;
	// down
	if(isSafe(x+1, y, vis, arr, n)){
		solve(x+1, y, arr, n, ans, vis, path+'D');

	}

	// left
	if(isSafe(x, y-1, vis, arr, n)){
		solve(x, y-1, arr, n, ans, vis, path+'L');

	}

	// right
	if(isSafe(x, y+1, vis, arr, n)){
		solve(x, y+1, arr, n, ans, vis, path+'R');

	}

	// up
	if(isSafe(x-1, y, vis, arr, n)){
		solve(x-1, y, arr, n, ans, vis, path+'U');	
	}
	vis[x][y] = false;
}


vector<string> searchMaze(vector<vector<int>> &arr, int n){
	vector<string> ans;
	vector<vector<bool>> visited(n, vector<bool> (n,false));
	string path = "";

	if(arr[0][0] == 0 || arr[n - 1][n - 1] == 0){
		return ans;
	}

	solve(0, 0, arr, n, ans, visited, path);
	return ans;
}

int main(){
	vector<vector<int>> arr = {
		{1,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,1,1,1}
	};

	int n = arr.size();

	vector<string> ans = searchMaze(arr, n);

	cout << "Possible path-way solutions : " << endl;
    for (string i : ans) {
        cout << i << endl;
    }
}