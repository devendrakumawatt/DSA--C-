#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges){
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].insert(v);
		adjList[v].insert(u);
	}
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();

		//store frontNode into ans 
		ans.push_back(frontNode);


		// traverse all neighbours of frontNode
		for(auto i:adjList[frontNode]){
			if(!visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

vector<int> BFS(int vertex, vector<pair<int, int>> &edges){
	unordered_map<int, set<int>> adjList;
	vector<int> ans;
	unordered_map<int, bool> visited;

	prepareAdjList(adjList, edges);

	// traverse all componenet of a graph
	for(int i=0; i<vertex; i++){
		if(!visited[i]){
			bfs(adjList, visited, ans, i);
		}
	}
	return ans;
}

int main(){

	int vertex = 5;
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4}
    };

    vector<int> result = BFS(vertex, edges);

    // Print BFS result
    cout << "BFS Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;
}