#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t){

	// create adj list
	unordered_map<int,list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// do bfs
	unordered_map<int, bool>visited;
	unordered_map<int, int>parent;
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i: adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	// parepare shortest path
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);

	while(currNode != s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


int main(){
	vector<pair<int,int>> edges = { 
		{1, 2},
		{1, 3},
		{1, 4},
		{2, 5},
		{3, 8},
		{4, 6},
		{5, 8},
		{6, 7},
		{7, 8}
	};

    int n = 9;
    int m = edges.size();
    int s = 1;
    int t = 8;

    vector<int> path = shortestPath(edges, n, m, s, t);

    if (path.empty() || path[0] != s) {
        cout << "No path found." << endl;
    } else {
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
}