#include<iostream>
#include<queue>
using namespace std;


class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
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

void inorder(node* root){
	// base case
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root){
	// base case
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root){
	// base case
	if(root == NULL){
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void buildFromLevelOrder(node* &root){
	queue<node*> q;
	cout << "Enter data for root" << endl;
	int data;
	cin >> data;
	root = new node(data);
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		cout << "Enter left node for : " << temp->data << endl;
		int leftData;
		cin >> leftData;

		if(leftData != -1){
			temp->left = new node(leftData);
			q.push(temp->left);
		}

		cout << "Enter right node for : " << temp->data << endl;
		int rightData;
		cin >> rightData;

		if(rightData != -1){
			temp->right = new node(rightData);
			q.push(temp->right);
		}
	}
}



int main(){
	node* root = NULL;

	buildFromLevelOrder(root);
	levelOrderTraversal(root);


/*
	//creating a Tree
    root = buildTree(root);

    //Level-order Traversal
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    // In-order Traversal
    cout << "Inorder Traversal is : ";
    inorder(root);
    cout << endl;

    // Pre-order Traversal
    cout << "preorder Traversal is : ";
    preorder(root);
    cout << endl;

    // Post-order Traversal
    cout << "postorder Traversal is : ";
    postorder(root);
    cout << endl;

*/
}





/*						// ** Count Leaf Nodes **

class leafNode {
public:
	int data;
	leafNode *left;
	leafNode *right;

	leafNode(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	~leafNode() {
        delete left;
        delete right;
    }
};

void inorder(leafNode *root, int &count){
	// base case
	if(root == NULL){
		return;
	}
	
	inorder(root->left, count);

	// leaf node
	if(root->left == NULL && root->right == NULL){
		count++;
	}

	inorder(root->right, count);
}


int leafNodeCount(leafNode *root){
	int cnt = 0;
	inorder(root, cnt);
	return cnt;
}

int main(){

	leafNode *root = new leafNode(1);
    root->left = new leafNode(2);
    root->right = new leafNode(3);
    root->left->left = new leafNode(4);
    root->left->right = new leafNode(5);
    root->right->right = new leafNode(6);

    // Output the number of leaf nodes
    cout << "Number of leaf nodes: " << leafNodeCount(root) << endl;

    // Cleanup memory
    delete root;

}
*/
