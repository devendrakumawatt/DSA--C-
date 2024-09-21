#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){

	visited[node] = true;
	for(auto nbr: adj[node]){
		if(!visited[nbr]){
			dfs(nbr, visited, s, adj);
		}
	}
	// topo logic
	s.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
	visited[node] = true;

	for(auto nbr : adj[node]){
		if(!visited[nbr]){
			revDFS(nbr, visited, adj);
		}
	}
}

int stronglyConnectedComponent(int v, vector<vector<int>> &edges){
	// create adj list
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// topo sort
	stack<int> s;
	unordered_map<int, bool> visited;
	for(int i=0; i<v; i++){
		if(!visited[i]){
			dfs(i, visited, s, adj);
		}
	}

	// create a transpose graph
	unordered_map<int, list<int>> transpose;
	for(int i=0; i<v; i++){
		visited[i] = 0;
		for(auto nbr: adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	// dfs call using above ordering
	int count = 0;
	while(!s.empty()){
		int top = s.top();
		s.pop();
		if(!visited[top]){
			count++;
			revDFS(top, visited, transpose);
		}
	}
	return count;
}

int main(){
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int v = 4; // Number of vertices
    cout << "Number of strongly connected components: " << stronglyConnectedComponent(v, edges) << endl;
}