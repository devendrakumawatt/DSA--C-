#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

								// ** Maximum Sum of Adjacent Node **

pair<int,int> solve(Node* root){
	// base case
	if(root == NULL){
		pair<int,int> p = make_pair(0,0);
		return p;
	}

	pair<int,int> left = solve(root->left);
	pair<int,int> right = solve(root->right);

	pair<int,int> res;
	res.first = root->data + left.second + right.second;
	res.second = max(left.first, left.second) + max(right.first, right.second);

	return res;
}

int getMaxSum(Node* root){
	pair<int,int> ans = solve(root);
	return max(ans.first, ans.second);
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int result = getMaxSum(root);

    cout << "Maximum sum of Non-Adjacent Nodes : " << result << endl;
}









/*								// ** Kth Ancestor **

Node* solve(Node* root, int &k, int node){
	// base case
	if(root == NULL){
		return NULL;
	}
	if(root->data == node){
		return root;
	}

	Node* leftAns = solve(root->left, k , node);
	Node* rightAns = solve(root->right, k , node);

	if(leftAns != NULL && rightAns == NULL){
		k--;
		if(k<=0){
			k = INT_MAX; // to lock answer
			return root;
		}
		return leftAns;
	}

	if(leftAns == NULL && rightAns != NULL){
		k--;
		if(k<=0){
			k = INT_MAX; // to lock answer
			return root;
		}
		return rightAns;
	}
	return NULL;
}

int KthAncestor(Node* root, int k, int node){
	Node* ans = solve(root, k , node);
	if(ans == NULL || ans->data == node){
		return -1;
	}
	else{
		return ans->data;
	}
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);

    int k = 2;
    int result = KthAncestor(root, k, 4);

    cout << k << "th Ancestor of node-4 is : " << result << endl;
}
*/












/*									// *** K - Sum Paths ***

void solve(Node* root, int k, int &count, vector<int> &path){
	// base case
	if(root == NULL){
		return ;
	}

	path.push_back(root->data);

	// left call
	solve(root->left, k, count, path);

	// right call
	solve(root->right, k, count, path);

	// check for K sum
	int size = path.size();
	int sum = 0;
	for(int i=size-1; i>=0; i--){
		sum = sum + path[i];
		if(sum == k){
			count++;
		}
	}
	path.pop_back();
}

int sumK(Node* root, int k){
	vector<int> path;
	int count = 0;
	solve(root, k, count, path);
	return count;
}


int main(){
	Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);

    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right->right = new Node(6);

    int k = 5;
    int result = sumK(root, k);

    cout << "Number of paths with a Sum of " << k << " is : " << result << endl;
}
*/










/*								// *** Lowest Common Ancestor ***

Node* lca(Node* root, int n1, int n2){
	// base case
	if(root == NULL){
		return NULL;
	}
	if(root->data == n1 || root->data == n2){
		return root;
	}

	Node* leftAns = lca(root->left, n1, n2);
	Node* rightAns = lca(root->right, n1, n2);

	if(leftAns != NULL && rightAns != NULL){
		return root;
	}
	else if(leftAns != NULL && rightAns == NULL){
		return leftAns;
	}
	else if(leftAns == NULL && rightAns != NULL){
		return rightAns;
	}
	else{
		return NULL;
	}
}

int main(){
	Node* root = new Node(5);
    root->left = new Node(4);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->left->right->left = new Node(12);
    root->left->right->right = new Node(9);

    root->right = new Node(3);
    root->right->left = new Node(22);
    root->right->right = new Node(27);
    root->right->right->left = new Node(29);

    Node* ans = lca(root, 9, 29);

    if(ans){
        cout << "The LCA [Lowest Common Ancestor] is : " << ans->data << endl;
    } 
    else{
        cout << "LCA not found" << endl;
    }
}
*/








/* 							// *** Sum of Longest Bloodline **

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
	// base case
	if(root == NULL){
		if(len > maxLen){
			maxLen = len;
			maxSum = sum;
		}
		else if(len == maxLen){
			maxSum = max(sum, maxSum);
		}
		return ;
	}

	sum = sum + root->data;

	solve(root->left, sum, maxSum, len+1, maxLen);
	solve(root->right, sum, maxSum, len+1, maxLen);
}


int sumOfLongestBloodline(Node* root){
	int len = 0;
	int maxLen = 0;
	int sum = 0;
	int maxSum = INT_MIN;

	solve(root, sum, maxSum, len, maxLen);

	return maxSum;
}

int main(){
	Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);

    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    int result = sumOfLongestBloodline(root);

    cout << "The Sum of Longest Bloodline is : " << result << endl;
}
*/