#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

int detectCycleInDirectedGraph(int n, vector< pair<int,int> > &edges){
	// create adj list
	unordered_map<int, list<int>> adj;
	for(int i=1; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
	}

	// find all indegrees
	vector<int> indegree(n);
	for(auto i: adj){
		for(auto j: i.second){
			indegree[j]++;
		}
	}


	// 0 indegree walo ko queue mai push krdo
	queue<int> q;
	for(int i=1; i<n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	// do bfs
	int cnt = 0;
	vector<int> ans;
	while(!q.empty()){
		int front = q.front();
		q.pop();

		// increment cnt
		cnt++;

		// neighbour indegree update
		for(auto neighbour: adj[front]){
			indegree[neighbour]--;
			if(indegree[neighbour] == 0){
				q.push(neighbour);
			}
		}
	}
	if(cnt == n){
		return false;
	}
	else{
		return true;
	}
}

int main(){
	int n = 7;

    vector<pair<int,int>> edges = {
        {4, 2},
        {2, 5},
        {5, 3},
        {3, 1},
        {1, 6},
        {6, 4}
    };

    bool result = detectCycleInDirectedGraph(n, edges);

    cout << "Is cycle present : ";
    if(result){
    	cout << "Yes!" << endl;
    }
    else{
    	cout << "No!" << endl;
    }

}
