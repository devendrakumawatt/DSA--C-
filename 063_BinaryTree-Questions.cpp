#include<iostream>
using namespace std;


						// ** Height of Tree **
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

int height(Node* ans){
	//base case
	if(ans == NULL){
		return 0;
	}

	int left = height(ans->left);
	int right = height(ans->right);

	int result = max(left, right) + 1;
	return result;
}

int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of the tree: " << height(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

}




/*							// ** Diameter of Tree **

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


pair<int,int> diameterfast(Node* root){
	// base case
	if(root == NULL){
		pair<int,int> p = make_pair(0,0);
		return p;
	}

	pair<int,int> left = diameterfast(root->left);
	pair<int,int> right = diameterfast(root->right);

	int op1 = left.first;
	int op2 = right.first;
	int op3 = left.second + right.second + 1;

	pair<int,int> ans;
	ans.first = max(op1 , max(op2, op3));
	ans.second = max(left.second , right.second) + 1;

	return ans; 

}

int diameter(Node* root){
	return diameterfast(root).first;
}

int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->left->right = new Node(8);
    root->left->right->left->right->left = new Node(9);

    cout << "Diameter of the tree: " << diameter(root) << endl;

}
*/



/*							// ** Check for Balanced Tree **

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

pair<bool,int> isbalancedFast(Node* root){
	// base case
	if(root == NULL){
		pair<bool,int> p = make_pair(true,0);
		return p;
	}

	pair<int,int>left = isbalancedFast(root->left);
	pair<int,int>right = isbalancedFast(root->right);

	bool leftAns = left.first;
	bool rightAns = right.first;
	bool diff = abs(left.second - right.second) <=1;

	pair<bool,int> ans;
	ans.second = max(left.second, right.second) + 1;

	if(leftAns && rightAns && diff){
		ans.first = true;
	}
	else{
		ans.first = false;
	}
	return ans;

}
bool isbalanced(Node* root){
	return isbalancedFast(root).first;
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(10);
    root->right = new Node(39);
    root->left->left = new Node(5);

    if(isbalanced(root)){
    	cout << "Tree is Balanced " << endl;
    }
    else{
    	cout << "Tree is not Balanced " << endl;
    }
}
*/



/*							// ** Check Identical Tree **

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

bool isIdentical(Node* r1, Node* r2){
	// base case
	if(r1 == NULL && r2 == NULL){
		return true;
	}

	if(r1 == NULL && r2 != NULL){
		return false;
	}

	if(r1 != NULL && r2 == NULL){
		return false;
	}

	bool left = isIdentical(r1->left, r2->left); 
	bool right = isIdentical(r1->right, r2->right); 

	bool value = r1->data == r2->data;


	if(left && right && value){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	Node* r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);

    Node* r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);

    if(isIdentical(r1, r2)){
    	cout << "Trees are Identical " << endl;
    }
    else{
    	cout << "Trees are not Identical " << endl;
    }
}
*/



/*					// ** Sum Tree **

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

pair<bool,int> isSumTreeFast(Node* root){
	// base case
	if(root == NULL){
		pair<bool,int> p = make_pair(true, 0);
		return p;
	}

	// Leaf Node
	if(root->left == NULL && root->right == NULL){
		pair<bool,int> p = make_pair(true, root->data);
		return p;
	}

	pair<bool,int> leftAns = isSumTreeFast(root->left);
	pair<bool,int> rightAns = isSumTreeFast(root->right);

	bool isLeftSumTree = leftAns.first;
	bool isRightSumTree = rightAns.first;

	int leftSum = leftAns.second;
	int rightSum = rightAns.second;

	bool condn = root->data = leftSum + rightSum;

	pair<bool,int> ans;
	if(isLeftSumTree && isRightSumTree && condn){
		ans.first = true;
		ans.second = root->data + leftSum + rightSum;
	}
	else{
		ans.first = false;
	}
	return ans;
}

bool isSumTree(Node* root){
	return isSumTreeFast(root).first;
}

int main(){
	Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    if(isSumTree(root)){
    	cout << "It is Sum Tree" << endl;
    }
    else{
    	cout << "It is not Sum Tree" << endl;
    }

}
*/