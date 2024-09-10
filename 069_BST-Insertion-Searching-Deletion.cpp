#include<iostream>
#include<queue>
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

							// *** Creation & Inserton into BST ***

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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}


int main() {
    Node* root = NULL;

    cout << "Enter the data to create BST : " << endl;
    takeInput(root);

    cout << "Printing the BST : " << endl;
    levelOrderTraversal(root);
    cout << endl;
}










/*								// *** Search X in BST ***

Node* insertIntoBST(Node* &root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}


void takeInput(Node* &root) {
    int data;
    cout << "Enter data to create BST (enter -1 to stop): " << endl;
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

bool searchInBST(Node* root, int x){
	
	Node* temp = root;

	while(temp != NULL){
		if(temp->data == x){
			return true;
		}
		if(temp->data > x){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	return false;
}


int main(){
	Node* root = NULL;
	
    takeInput(root);

    int x;
    cout << "Enter value to search in BST: ";
    cin >> x;

    if (searchInBST(root, x)) {
        cout << "Value " << x << " found in the BST." << endl;
    } else {
        cout << "Value " << x << " not found in the BST." << endl;
    }
}
*/









/* 							// *** Min & Max value in BST ***

Node* insertIntoBST(Node* &root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node* minValue(Node* root){
	Node* temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

Node* maxValue(Node* root){
	Node* temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}


void takeInput(Node* &root) {
    int data;
    cout << "Enter data to create BST (enter -1 to stop): " << endl;
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}


int main(){
	Node* root = NULL;
	
    takeInput(root);

    cout << "Printing BST in (In-order) form: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Minimum Value of BST is : " << minValue(root)->data << endl;
    cout << "Maximum Value of BST is : " << maxValue(root)->data << endl;
}
*/









/* 							// *** Deletion in BST ***

Node* insertIntoBST(Node* &root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node* minValue(Node* root){
	Node* temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

Node* deleteFromBST(Node* &root, int val){
	// base case
	if(root == NULL){
		return root;
	}

	if(root->data == val){
		// 0 child
		if(root->left && root->right == NULL){
			delete root;
			return NULL;
		}

		// 1 child
			// Left child --  
		if(root->left != NULL && root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
			// Right child --
		if(root->left == NULL && root->right != NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// 2 child
		if(root->left != NULL && root->right != NULL){
			int mini = minValue(root->right)->data;
			root->data = mini;
			root->right = deleteFromBST(root->right, mini);
			return root;
		}


	}
	else if(root->data > val){
		// right part mai
		root->left = deleteFromBST(root->left, val);
		return root;
	}
	else{
		// left part mai
		root->right = deleteFromBST(root->right, val);
		return root;
	}

}

void takeInput(Node* &root) {
    int data;
    cout << "Enter data to create BST (enter -1 to stop): " << endl;
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

int main(){
	Node* root = NULL;
	
    takeInput(root);

    int val = 50;

    cout << "BST Before Node - " <<val<< " deletion : " << endl;
    levelOrderTraversal(root);
    cout << endl;

    deleteFromBST(root, val);

    cout << "BST After Node - " <<val<< " deletion : " << endl;
    levelOrderTraversal(root);
    cout << endl;
}
*/