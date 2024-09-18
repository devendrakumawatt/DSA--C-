#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, unordered_map<int, list<int>> &adj){

	visited[node] = true;
	dfsVisited[node] = true;

	for(auto bajuVala: adj[node]){
		if(!visited[bajuVala]){
			bool cycleDetect = checkCycleDFS(bajuVala, visited, dfsVisited, adj);
			if(cycleDetect){
				return true;
			}
		}
		else if(dfsVisited[bajuVala]){
			return true;
		}
	}
	dfsVisited[node] = false;
	return false;
}


int detectCycleInDirectedGraph(int n, vector<pair <int,int>> &edges){

	// create adjacency list
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
	}

	// calll dfs all components
	unordered_map<int,bool> visited;
	unordered_map<int,bool> dfsVisited;

	for(int i=1; i<=n; i++){
		if(!visited[i]){
			bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
			if(cycleFound){
				return true;
			}
		}
	}
	return false;
}

int main(){
	vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3;

    if (detectCycleInDirectedGraph(n, edges)) {
        cout << "Yes! Cycle detected in graph" << endl;
    } else {
        cout << "No! cycle not detected in graph" << endl;
    }
}