#include<iostream>
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

							// *** LCA in BST ***

int LCAinBST(Node* root, int a, int b){
	// base case
	if(root == NULL){
		return -1;
	}

	while(root != NULL){
		if(root->data < a && root->data < b){
			root = root->right;
		}

		else if(root->data > a && root->data > b){
			root = root->left;
		}

		else{
			return root->data;
		}
	}
}


int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

    int a = 2;
    int b = 5;

    int res = LCAinBST(root, a, b);

    cout << "LCA in BST of "<< a << " & " << b << " is : " << res << endl;

}











/*									// ** Predecessor & Successor **

pair<int,int> predecessorSuccessor(Node* root, int key){
	// find key
	Node* temp = root;
	int pred = -1;
	int succ = -1;

	while(temp->data != key){
		if(temp->data > key){
			succ = temp->data;
			temp = temp->left;
		}
		else{
			pred = temp->data;
			temp = temp->right;
		}
	}
	// pred 
	Node* leftTree = temp->left;
	while(leftTree != NULL){
		pred = leftTree->data;
		leftTree = leftTree->right;
	}

	// succ
	Node* rightTree = temp->right;
	while(rightTree != NULL){
		succ = rightTree->data;
		rightTree = rightTree->left;
	}

	pair<int,int> ans = make_pair(pred, succ);
	return ans;
}


int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

    int key = 2;
    pair<int,int> res = predecessorSuccessor(root, key);

    cout << "Predecessor of " << key << " is : " << res.first << endl;
    cout << "Successor of " << key << " is : " << res.second << endl;
}
*/











/*								// *** Kth Smallest Element ***

int solve(Node* root, int &i, int k){
	// base case
	if(root == NULL){
		return -1;
	}

	int left = solve(root->left, i, k);
	if(left != -1){
		return left;
	}

	i++;
	if(i == k){
		return root->data;
	}
	return solve(root->right, i, k);
}

int KthSmallest(Node* root, int k){
	int i = 0;
	int ans = solve(root, i, k);
	return ans;
}


int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

    int k = 3;
    int res = KthSmallest(root, k);

    cout << k <<"rd Smallest element is : " << res << endl;
}
*/









/*							// *** Validate BST ***

bool isBST(Node* root, int min, int max){
	// base case
	if(root == NULL){
		return true;
	}

	if(root->data >= min && root->data <= max){
		bool left = isBST(root->left, min, root->data);
		bool right = isBST(root->right, root->data, max);
		return left && right;
	}

	else{
		return false;
	}
}

bool validateBST(Node* root){
	return isBST(root, INT_MIN, INT_MAX);
}

int main(){
	Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

    bool res = validateBST(root);

    if(res){
    	cout << "Valid BST" << endl;
    }
    else{
    	cout << "Not Valid BST" << endl; 
    }

}
*/