#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

class Node {
public:
	int data;
	int row;
	int col;

	Node (int d, int r, int c){
		data = d;
		row = r;
		col = c;
	}
};

class compare {
public:
	bool operator()(Node* a, Node* b){
		return a->data > b->data;
	}
};


int kSorted(vector<vector<int>> &a, int k, int n){
	int mini = INT_MAX;
	int maxi = INT_MIN;

	priority_queue<Node*, vector<Node*>, compare> minHeap;

	// create min heap for starting element of each list and tracking min/max
	for(int i=0; i<k; i++){
		int element = a[i][0];
		mini = min(mini, element);
		maxi = max(maxi, element);
		minHeap.push(new Node(element, i, 0));
	}

	int start = mini;
	int end = maxi;

	// process ranges
	while(!minHeap.empty()){

		// mini fetch
		Node* temp = minHeap.top();
		minHeap.pop();

		mini = temp->data;

		// range or answer updation
		if(maxi - mini < end - start){
			start = mini;
			end = maxi;
		}

		// next element exists
		if(temp->col+1 < n){
			maxi = max(maxi, a[temp->row][temp->col + 1]);
			minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col+1));
		}
		else{
			// next element does not exists
			break;
		}
	}
	// returning the difference value of range
	return {end-start + 1};
}

int main(){
	vector<vector<int>> a = {
        {1, 7, 10},
        {4, 8, 12},
        {6, 9, 14}
    };

    int k = a.size();
    int n = a[0].size();

    cout << "Smallest range is of size: " << kSorted(a, k, n) << endl;
}