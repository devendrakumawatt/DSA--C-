#include<iostream>
#include<vector>
#include<queue>
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

void solve(Node* root, vector<int> &ans, int level){
	// base case
	if(root == NULL){
		return ;
	}

	// we entered into new level
	if(level == ans.size()){
		ans.push_back(root->data);
	}

	solve(root->right, ans, level+1);
	solve(root->left, ans, level+1);
}


vector<int> rightView(Node* root){
	vector<int> ans;
	solve(root, ans, 0);
	return ans;
}



int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(7);

    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    vector<int> result = rightView(root);

    cout << "Right View Tree Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl;

}









/*								// ** Left View of Tree **

void solve(Node* root, vector<int> &ans, int level){
	// base case
	if(root == NULL){
		return ;
	}

	// we entered into new level
	if(level == ans.size()){
		ans.push_back(root->data);
	}

	solve(root->left, ans, level+1);
	solve(root->right, ans, level+1);
}


vector<int> leftView(Node* root){
	vector<int> ans;
	solve(root, ans, 0);
	return ans;
}



int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(7);

    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    vector<int> result = leftView(root);

    cout << "Left View Tree Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl;

}
*/









/*									// ** Bottom View of Tree **

vector<int> bottomView(Node* root){
	vector<int> ans;
	if(root == NULL){
		return ans;
	}

	map <int,int> bottomNode;
	queue<pair<Node* ,int>> q;

	q.push(make_pair(root, 0));

	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		bottomNode[hd] = frontNode->data;

		if(frontNode->left){
			q.push(make_pair(frontNode->left, hd-1));
		}

		if(frontNode->right){
			q.push(make_pair(frontNode->right, hd+1));
		}
	}
	for(auto i: bottomNode){
		ans.push_back(i.second);
	}
	return ans;
}


int main(){
	Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right = new Node(30);

    vector<int> result = bottomView(root);

    cout << "Bottom View Tree Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl;
}
*/











/*						// ** Top View of Tree **

vector<int> topView(Node* root){
	vector<int> ans;
	if(root == NULL){
		return ans;
	}

	map <int,int> topNode;
	queue<pair<Node* ,int>> q;

	q.push(make_pair(root, 0));

	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		// if one value is present for a hs, then 
		if(topNode.find(hd) == topNode.end()){
			topNode[hd] = frontNode->data;
		}

		if(frontNode->left){
			q.push(make_pair(frontNode->left, hd-1));
		}

		if(frontNode->right){
			q.push(make_pair(frontNode->right, hd+1));
		}
	}
	for(auto i: topNode){
		ans.push_back(i.second);
	}
	return ans;
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topView(root);

    cout << "Top View Tree Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl;
}
*/







/*						// ** Vertical Order Traversal **

vector<int> verticalOrder(Node* root){

	map<int, map<int,vector<int>> > nodes;
	queue<pair<Node* ,pair<int,int>> > q;
	vector<int> ans;

	q.push(make_pair(root, make_pair(0,0)));

	while(!q.empty()){
		pair<Node* ,pair<int,int>> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second.first;
		int lvl = temp.second.second;

		nodes[hd][lvl].push_back(frontNode->data);

		if(frontNode->left){
			q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
		}
		if(frontNode->right){
			q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
		}
	}
	for(auto i : nodes){
		for(auto j : i.second){
			for(auto k : j.second){
				ans.push_back(k);
			}
		}
	}
	return ans;
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<int> result = verticalOrder(root);

    cout << "Vertical Order Traversal Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl;
}
*/







/*								// *** Boundary Traversal ***

void traverseLeft(Node* root, vector<int> &ans){
	// base case
	if((root == NULL) || (root->left == NULL && root->right == NULL)){
		return ;
	}

	ans.push_back(root->data);
	if(root->left){
		traverseLeft(root->left, ans);
	}
	else{
		traverseLeft(root->right, ans);
	}

}

void traverseLeaf(Node* root, vector<int> &ans){
	// base case
	if(root == NULL){
		return ;
	}
	if(root->left == NULL && root->right == NULL){
		ans.push_back(root->data);
		return ;
	}
	traverseLeaf(root->left, ans);
	traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans){
	// Base case
	if((root == NULL) || (root->left == NULL && root->right == NULL)){
		return ;
	}
	if(root->right){
		traverseRight(root->right, ans);
	}
	else{
		traverseRight(root->left, ans);
	}
	ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
	vector<int> ans;
	if(root == NULL){
		return ans;
	}
	ans.push_back(root->data);

	// left part print
	traverseLeft(root->left, ans);

	// traverse Leaf Node

	// Left Sub Tree
	traverseLeaf(root->left, ans);
	// Right Sub Tree
	traverseLeaf(root->right, ans);

	// print right part
	traverseRight(root->right, ans); 

	return ans;
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    root->right->right->right->left = new Node(10);
    root->right->right->right->right = new Node(11);

    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl; 

}
*/





/*							// *** ZIG ZAG TRAVERSAL ***

vector<int> zigZagTraversal(Node* root){
	vector<int> result;
	if(root == NULL){
		return result;
	}

	queue<Node*> q;
	q.push(root);

	bool leftToRight = true;

	while(!q.empty()){
		int size = q.size();
		vector<int> ans(size);

		// level Process
		for(int i=0; i<size; i++){
			Node* frontNode = q.front();
			q.pop();

			// normal insert or reverse insert
			int index = leftToRight ? i : size-i-1;
			ans[index] = frontNode->data;

			if(frontNode->left){
				q.push(frontNode->left);
			}
			if(frontNode->right){
				q.push(frontNode->right);
			}
		}
		// direction change
		leftToRight = !leftToRight;


		for(auto i : ans){
			result.push_back(i);
		}
	}
	return result;
}

int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = zigZagTraversal(root);

    cout << "Zig Zag Traversal Ans : ";
    for(int value : result){
        cout << value << " ";
    }
    cout << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;


}
*/