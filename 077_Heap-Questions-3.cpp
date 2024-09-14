#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

 							// *** Smallest Range in k-list ***

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











/*							// *** Median in a Stream ***


int signum(int a, int b){
	if(a == b){
		return 0;
	}
	else if(a > b){
		return 1;
	}
	else{
		return -1;
	}
}

void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini , int &median){
	switch(signum(maxi.size(), mini.size())){

		case 0: if(element > median){
					mini.push(element);
					median = mini.top();
				}
				else{
					maxi.push(element);
					median = maxi.top();
				}
				break;

		case 1: if(element > median){
					mini.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				else{
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				break;

		case -1: if(element > median){
					maxi.push(mini.top());
					mini.pop();
					mini.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				else{
					maxi.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				break;
	}

}


vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int median = 0;

	for(int i=0; i<n; i++){
		callMedian(arr[i], maxheap, minHeap, median);
		ans.push_back(median);
	}
	return ans;
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    vector<int> medians = findMedian(arr, n);

    cout << "Running medians: ";
    for (int m : medians) {
        cout << m << " ";
    }
    cout << endl;
}
*/