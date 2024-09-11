#include<iostream>
#include<vector>
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


void convertIntoSortedDLL(Node* root, Node* &head){
	// base case
	if(root == NULL){
		return ;
	}

	convertIntoSortedDLL(root->right, head);

	root->right = head;

	if(head != NULL){
		head->left = root;
	}
	head = root;

	convertIntoSortedDLL(root->left, head);
}

Node* mergeLinkedList(Node* head1, Node* head2){
	Node* head = NULL;
	Node* tail = NULL;

	while(head1 != NULL && head2 != NULL){
		if(head1->data < head2->data){
			if(head == NULL){
				head = head1;
				tail = head1;
				head1 = head1->right;
			}
			else{
				tail->right = head1;
				head1->left = tail;
				tail = head1;
				head1 = head1->right;
			}
		}
		else{
			if(head == NULL){
				head = head2;
				tail = head2;
				head2 = head2->right;
			}
			else{
				tail->right = head2;
				head2->left = tail;
				tail = head2;
				head2 = head2->right;
			}
		}
	}
	while(head1 != NULL){
		tail->right = head1;
		head1->left = tail;
		tail = head1;
		head1 = head1->right;
	}

	while(head2 != NULL){
		tail->right = head2;
		head2->left = tail;
		tail = head2;
		head2 = head2->right;
	}
	return head;
}

int countNodes(Node* head){
	int cnt = 0;
	Node* temp = head;
	while(temp != NULL){
		cnt++;
		temp = temp->right;
	}
	return cnt;
}

Node* sortedLLToBST(Node* &head, int n){
	// Base case
	if(n <= 0 || head == NULL){
		return NULL;
	}

	Node* left = sortedLLToBST(head, n/2);

	Node* root = head;
	root->left = left;
	head = head->right;

	root->right = sortedLLToBST(head, n-n/2-1);
	return root;
}

Node* mergeBST(Node* root1, Node* root2){
	// convert BST into Sorted DLL inspace
	Node* head1 = NULL;
	convertIntoSortedDLL(root1, head1);
	head1->left = NULL;

	Node* head2 = NULL;
	convertIntoSortedDLL(root2, head2);
	head1->left = NULL;


	// merge sorted Linked list
	Node* head = mergeLinkedList(head1, head2);

	// Convert SLL into BST
	return sortedLLToBST(head, countNodes(head));
}

void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


int main(){
	Node* root1 = NULL;
    Node* root2 = NULL;

    cout << "Enter elements for the first BST (end with -1): ";
    takeInput(root1);

    cout << "Enter elements for the second BST (end with -1): ";
    takeInput(root2);

    Node* mergedBST = mergeBST(root1, root2);

    cout << "Printing Merged BST (inorder): ";
    printInOrder(mergedBST);
    cout << endl;
}








/*		// Approach - 1

void inorder(Node* root, vector<int> &in){
	if(root == NULL){
		return ;
	}

	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
	vector<int> ans(a.size() + b.size());

	int i = 0, j = 0;
	int k = 0;

	while(i < a.size() && b.size()){
		if(a[i] < b[j]){
			ans[k++] = a[i];
			i++;
		}
		else{
			ans[k++] = b[j];
			j++;
		}
	}

	while(i < a.size()){
		ans[k++] = a[i];
		i++;
	}

	while(j < b.size()){
		ans[k++] = b[j];
		j++;
	}
	return ans;
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

Node* mergeBST(Node* root1, Node* root2){

	// Store inorder
	vector<int> bst1, bst2;
	inorder(root1, bst1);
	inorder(root2, bst2);

	// merge both sorted arrays
	vector<int> mergeArray = mergeArrays(bst1, bst2);

	// use merged inorder array to build BST
	int s = 0, e = mergeArray.size()-1;
	return inorderToBST(s, e, mergeArray);
}
*/