#include<iostream>
#include<map>
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

								// *** InOrder / PostOrder to Binary Tree ***

void createMapping(int in[], map<int,int>&nodeToIndex, int n){
	for(int i=0; i<n; i++){
		nodeToIndex[in[i]] = i;
	}
}

Node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){
	// base case
	if(index < 0 || inOrderStart > inOrderEnd){
		return NULL;
	}

	// create a root node for element
	int element = post[index--];
	Node* root = new Node(element);

	// find element and index in inorder
	int position = nodeToIndex[element];


	// Recursive call
	root->right = solve(in, post, index, position+1, inOrderEnd, n, nodeToIndex);
	root->left = solve(in, post, index, inOrderStart, position-1, n, nodeToIndex);

	return root;
}

Node* buildTree(int in[], int post[], int n){
	int postOrderIndex = n-1;
	map<int,int> nodeToIndex;

	// create nodes to index mapping
	createMapping(in, nodeToIndex, n);
	Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
	return ans;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


int main(){
	int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* root = buildTree(inorder, postorder, n);

    cout << "Inorder traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;
}









/*						// *** InOrder / PreOrder to Binary Tree ***

void createMapping(int in[], map<int,int>&nodeToIndex, int n){
	for(int i=0; i<n; i++){
		nodeToIndex[in[i]] = i;
	}
}

Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){
	// base case
	if(index >= n || inOrderStart > inOrderEnd){
		return NULL;
	}

	// create a root node for element
	int element = pre[index++];
	Node* root = new Node(element);

	// find element and index in inorder
	int position = nodeToIndex[element];


	// Recursive call
	root->left = solve(in, pre, index, inOrderStart, position-1, n, nodeToIndex);
	root->right = solve(in, pre, index, position+1, inOrderEnd, n, nodeToIndex);

	return root;
}

Node* buildTree(int in[], int pre[], int n){
	int preOrderIndex = 0;
	map<int,int> nodeToIndex;

	// create nodes to index mapping
	createMapping(in, nodeToIndex, n);
	Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
	return ans;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


int main(){
	int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* root = buildTree(inorder, preorder, n);

    cout << "Inorder traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;
}
*/