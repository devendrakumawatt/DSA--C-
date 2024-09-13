#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long miniCost(long long arr[], long long n){
	priority_queue<long long, vector<long long>, greater<long long> > pq;

	for(int i=0; i<n; i++){
		pq.push(arr[i]);
	}

	int cost = 0;

	while(pq.size() > 1){
		long long a = pq.top();
		pq.pop();

		long long b = pq.top();
		pq.pop();

		long long sum = a + b;
		cost = cost + sum;

		pq.push(sum);
	}
	return cost;
}

int main(){

	int n = 4;
	long long arr[n] = {4,3,2,6};

	int ans = miniCost(arr, n);

	cout << "Minimum cost : " << ans << endl;

}








/* 						// *** Merge 2 Binary Max Heap ***

void heapify(vector<int> &arr, int n, int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;

	if(left < n && arr[largest] < arr[left]){
		largest = left;
	}
	if(right < n && arr[largest] < arr[right]){
		largest = right;
	}

	if(largest != i){
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

vector<int> mergeHeap(vector<int> &a, vector<int> &b, int n, int m){
	// merge both array
	vector<int> ans;
	for(auto i:a){
		ans.push_back(i);
	}
	for(auto i:b){
		ans.push_back(i);
	}


	// build heap using merged array
	int size = ans.size();
	for(int i=size/2 - 1; i>=0; i--){
		heapify(ans, n, i);
	}
	return ans;

}


int main(){
	vector<int> a = {10,5,6,2};
	int n = 4;

	cout << "Heap Array a : ";
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}cout << endl;

	vector<int> b = {12,7,9};
	int m = 3;

	cout << "Heap Array b : ";
	for(int i=0; i<m; i++){
		cout << b[i] << " ";
	}cout << endl;

	vector<int> ans = mergeHeap(a, b, n, m);

	cout << "Merged Heap Array : ";
	for(int i=0; i<n+m; i++){
		cout << ans[i] << " ";
	}cout << endl;
}
*/










/* 					// *** Is Binary Tree Heap ? ***
class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

int countNode(Node* root){
	// base case
	if(root == NULL){
		return 0;
	}

	int ans = 1 + countNode(root->left) + countNode(root->right);
	return ans;
}

bool isCBT(Node* root, int index, int cnt){
	if(root == NULL){
		return true;
	}
	if(index >= cnt){
		return false;
	}
	else{
		bool left = isCBT(root->left, 2*index+1, cnt);
		bool right = isCBT(root->right, 2*index+2, cnt);
		return (left && right);
	}
}

bool isMaxOrder(Node* root){
	// base case
	if(root->left == NULL && root->right == NULL){
		return true;
	}
	if(root->right == NULL){
		return(root->data > root->right->data);
	}
	else{
		bool left = isMaxOrder(root->left);
		bool right = isMaxOrder(root->right);

		return (left && right && (root->data > root->left->data && root->right->data));
	}
}

bool isHeap(Node* root){
	int index = 0;
	int totalCount = countNode(root);

	if(isCBT(root, index, totalCount) && isMaxOrder(root)){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	Node* root = new Node(60);
	root->left = new Node(30);
	root->left->left = new Node(10);
	root->left->right = new Node(20);

	root->right = new Node(40);

	bool ans = isHeap(root);

	if(ans){
		cout << "The Binary Tree is Heap" << endl;
	}
	else{
		cout << "The Binary Tree is not Heap" << endl;
	}
}
*/









/*					// *** Kth Smallest Element ***

int KthSmallest (int arr[], int l, int r, int k){
	priority_queue<int> pq;
	for(int i=0; i<k; i++){
		pq.push(arr[i]);
	}

	for(int i=k; i<=r; i++){
		if(arr[i] < pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	int ans = pq.top();
	return ans;
}

int main(){
	int size = 5;
	int arr[size] = {7,10,4,20,15};
	int k = 3;
	int l = 0;
	int r = size-1;

	cout << "Printing the array : " ; 
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}cout << endl;

	cout << "The " <<k<< "rd smallest element is : " << KthSmallest(arr, l, r, k) << endl;
}
*/