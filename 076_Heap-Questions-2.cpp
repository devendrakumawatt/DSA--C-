#include<iostream>
#include<vector>
#include<queue>
using namespace std;

	
								// *** Merge K-sorted Linked List ***

class Node {
public:
	int data;
	Node* next;

	Node(int d){
		this->data = d;
		this->next = NULL;
	}

	~Node() {
		if(next != NULL){
			delete next;
		}
	}
};

class compare {
public:
	bool operator()(Node* a, Node* b){
		return a->data > b->data;
	}
};

Node* mergeKLists(vector<Node*> &listArray){
	priority_queue<Node*, vector<Node*>, compare > minheap;

	int k = listArray.size();

	if(k == 0){
		return NULL;
	}

	for(int i=0; i<k; i++){
		if(listArray[i] != NULL){
			minheap.push(listArray[i]);
		}
	}

	Node* head = NULL;
	Node* tail = NULL;

	while(minheap.size() > 0){
		Node* top = minheap.top();
		minheap.pop();

		if(top->next != NULL){
			minheap.push(top->next);
		}

		if(head == NULL){
			// Answer LL is empty
			head = top;
			tail = top;
			
		}
		else{
			// insert at linked list
			tail->next = top;
			tail = top;
		}
	}
	return head;
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    vector<Node*> listArray = { list1, list2, list3 };

    Node* mergedList = mergeKLists(listArray);

    cout << "Merged k sorted Linked List : ";
    printList(mergedList);
}











/*							// *** Merge k-sorted Arrays ***

class node {
public:
	int data;
	int i;
	int j;

	node(int data, int row, int col){
		this->data = data;
		i = row;
		j = col;
	}
};

class compare {
public:
	bool operator()(node* a, node* b){
		return a->data > b->data;
	}
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k){
	priority_queue<node*, vector<node*>, compare> minHeap;

	// saare arrays k first element insert krna h
	for(int i=0; i<k; i++){
		node* tmp = new node(kArrays[i][0], i, 0);
		minHeap.push(tmp);
	}

	vector<int> ans;

	while(minHeap.size() > 0){
		node* tmp = minHeap.top();
		ans.push_back(tmp->data);
		minHeap.pop();

		int i = tmp->i;
		int j = tmp->j;

		if(j+1 < kArrays[i].size()){
			node* next = new node(kArrays[i][j+1], i, j+1);
			minHeap.push(next);
		}
	}
	return ans;
}


int main(){
	vector<vector<int>> kArrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<int> mergedArray = mergeKSortedArrays(kArrays, 3);

    cout << "Merged k sorted Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;
}
*/









/*						// *** Kth largest sum of sub-array ***

int getKthLargest(vector<int> &arr, int k){

	priority_queue<int, vector<int>, greater<int> > mini;

	int n = arr.size();
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum = sum + arr[j];
			if(mini.size() < k){
				mini.push(sum);
			}
			else{
				if(sum > mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}


int main(){

	vector<int> arr = {1,2,6,4,3};

	int k = 2;
	int res = getKthLargest(arr, k);

	cout << k <<"nd largest sub-array sum is : " << res << endl;
}
*/