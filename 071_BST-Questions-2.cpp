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
