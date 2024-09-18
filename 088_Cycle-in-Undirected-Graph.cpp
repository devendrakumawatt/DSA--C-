#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
	unordered_map<int, int> parent;

	parent[src] = -1;
	visited[src] = 1;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neighbour: adj[front]){
			if(visited[neighbour] == true && neighbour != parent[front]){
				return true;
			}
			else if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour] = 1;
				parent[neighbour] = front;
			}
		}
	}
	return false;
}


bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){

	visited[node] = true;

	for(auto sathi: adj[node]){
		if(!visited[sathi]){
			bool cycleDetect = isCyclicDFS(sathi, node, visited, adj);
			if(cycleDetect){
				return true;
			}
		}
		else if(sathi != parent){
			// cycle present
			return true;
		}
	}
	return false;
}


string cycleDetection(vector<vector<int>> &edges, int n, int m){

	// create adjacency list
	unordered_map<int, list<int>> adj;
	for(int i=0; i<m; i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// to handle disconnected component
	unordered_map<int, bool> visited;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			//bool ans = isCyclicBFS(i, visited, adj);  // by BFS
			bool ans = isCyclicDFS(i, -1, visited, adj);  // by DFS
			if(ans == 1){
				return "yes";
			}
		}
	}
	return "No";

}

int main(){
	 vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3;
    int m = edges.size();

    cout << "Is cycle present in graph : " ;
    cout << cycleDetection(edges, n, m) << endl; 

}