#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){
	// create adj List

	unordered_map<int,list<pair<int,int>>> adj;
	for(int i=0; i<edges; i++){
		int u = vec[i][0];
		int v = vec[i][1];

		int w = vec[i][2];

		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}

	// create distance array with infinite values
	vector<int> dist(vertices);
	for(int i=0; i<vertices; i++){
		dist[i] = INT_MAX;
	}

	// creation of set -> (distance, node)
	set<pair<int,int>> st;

	// initialise distance and set with source node
	dist[source] = 0;
	st.insert(make_pair(0, source));

	while(!st.empty()){
		// fetch top record
		auto top = *(st.begin());

		int nodeDistance = top.first;
		int topNode = top.second;

		// remove top record now
		st.erase(st.begin());


		// traverse on neighbours
		for(auto neighbour: adj[topNode]){
			if(nodeDistance + neighbour.second < dist[neighbour.first]){

				auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

				// if record found, then erase it
				if(record != st.end()){
					st.erase(record);
				}

				// distance update
				dist[neighbour.first] = nodeDistance + neighbour.second;

				// record push in set
				st.insert(make_pair(dist[neighbour.first], neighbour.first));
			}
		}
	}
	return dist;
}


int main(){
	int vertices = 4;
    int edges = 5;

    vector<vector<int>> vec = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 0, 5},
        {1, 2, 9},
        {1, 3, 2},
        {2, 0, 8},
        {2, 1, 9},
        {2, 3, 6},
        {3, 1, 2},
        {3, 2, 6}
    };

    int source = 0;
    vector<int> distances = dijkstra(vec, vertices, edges, source);

    cout << "Shortest Distance from node (" << source << "):" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "node " << i << ": " << (distances[i] == INT_MAX ? "INF" : to_string(distances[i])) << endl;
    }
}