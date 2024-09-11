#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

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

Node* insertIntoBST(Node* &root, int d){
	// base case
	if(root == NULL){
		root = new Node(d);
		return root;
	}

	if(d > root->data){
		// insert into right part
		root->right = insertIntoBST(root->right, d);
	}
	else{
		// insert into left part
		root->left = insertIntoBST(root->left, d);
	}
	return root;
}

void takeInput(Node* &root){
	int data;
	cin >> data;

	while(data != -1){
		insertIntoBST(root, data);
		cin >> data;
	}
}


							// *** Preorder to BST ***

Node* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if (i >= preorder.size()) {
        return NULL;
    }
    if (preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    Node* root = new Node(preorder[i]);
    i++;  // Move to the next index
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    cout << "Enter preorder traversal to convert to BST (end with -1):" << endl;
    vector<int> preorder;
    int data;
    cin >> data;
    while (data != -1) {
        preorder.push_back(data);
        cin >> data;
    }

    Node* bstFromPreorder = preorderToBST(preorder);

    cout << "Inorder traversal of the BST from preorder traversal:" << endl;
    inorderTraversal(bstFromPreorder);
    cout << endl;
}












/*								// *** Normal BST to Balanced BST ***

void inorder(Node* root, vector<int> &in){
	if(root == NULL){
		return ;
	}

	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}

Node* inorderToBST(int s, int e, vector<int> &in){
	// base case
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	Node* temp = new Node(in[mid]);
	temp->left = inorderToBST(s, mid-1, in);
	temp->right = inorderToBST(mid+1, e, in);
	return temp;
}

Node* balancedBST(Node* root){
	vector<int> inorderVal;
	// store inorder -> sorted values
	inorder(root, inorderVal);

	return inorderToBST(0, inorderVal.size()-1, inorderVal);
}

void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
    cout << endl;
}


int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

   	Node* res = balancedBST(root);

   	cout << "Inorder traversal of balanced BST: " << endl;
    printInorder(res);

}
*/










/*								// *** Flatten BST to Sorted Linked List ***

void inorder(Node* root, vector<int> &in){
	if(root == NULL){
		return ;
	}

	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}

Node* flatten(Node* root){
	vector<int> inorderVal;
	// store inorder -> sorted values
	inorder(root, inorderVal);

	int n = inorderVal.size();

	Node* newNode = new Node(inorderVal[0]);
	Node* curr = newNode;

	for(int i=1; i<n; i++){
		Node* temp = new Node(inorderVal[i]);

		curr->left = NULL;
		curr->right = temp;
		curr = temp;
	}

	curr->left = NULL;
	curr->right = NULL;

	return newNode;
}

void printFlattened(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

   	Node* res = flatten(root);

   	cout << "Flattened tree (as a sorted list): " << endl;
    printFlattened(res);
}
*/












/*								// *** Two Sum in BST ***

void inorder(Node* root, vector<int> &in){
	if(root == NULL){
		return ;
	}

	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}

bool twoSumInBST(Node* root, int target){
	vector<int> inorderVal;
	// store inorder -> sorted values
	inorder(root, inorderVal);

	// use two pointer approach
	int i = 0;
	int j = inorderVal.size()-1;

	while(i<j){
		int sum = inorderVal[i] + inorderVal[j];
		if(sum == target){
			return true;
		}
		else if(sum > target){
			j--;
		}
		else{
			i++;
		}
	}
	return false;
}

int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

    int target = 20;
    bool res = twoSumInBST(root, target);

    if(res){
    	cout << "Two Sum node = " <<target<< " ,Present." << endl;
    }
    else{
    	cout << "Two Sum node = " <<target<< " ,Absent." << endl;
    }
}
*/