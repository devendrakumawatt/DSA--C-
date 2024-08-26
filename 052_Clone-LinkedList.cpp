#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *random;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
          if(head->random)
              cout << head->random->data << ")";
          else 
              cout << "null" << ")";
        
          if(head->next != NULL)
              cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


void insertAtTail(Node* &head, Node* &tail, int d){
	Node* newNode = new Node(d);
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
}
/* // Approach - 1

Node* copyList(Node* head){
	// create a clone list
	Node* cloneHead = NULL;
	Node* cloneTail = NULL;

	Node* temp = head;

	while(temp != NULL){
		insertAtTail(cloneHead, cloneTail, temp->data);
		temp = temp->next;
	}

	// create a map
	unordered_map<Node*, Node*> oldToNewNode;

	Node* originalNode = head;
	Node* cloneNode = cloneHead;
	while(originalNode != NULL){
		oldToNewNode[originalNode] = cloneNode;
		originalNode = originalNode->next;
		cloneNode = cloneNode->next;

	}
	originalNode = head;
	cloneNode = cloneHead;

	while(originalNode != NULL){
		cloneNode->random = oldToNewNode[originalNode->random];
		originalNode = originalNode->next;
		cloneNode = cloneNode->next;
	}
	return cloneHead;
}
*/



// Approach - 2
Node* copyList2(Node* head){

	// step-1: create clone list
	Node* cloneHead = NULL;
	Node* cloneTail = NULL;
	Node* temp = head;
	while(temp != NULL){
		insertAtTail(cloneHead, cloneTail, temp->data);
		temp = temp->next;
	}

	// step-2: cloneNode add in between original list
	Node* originalNode = head;
	Node* cloneNode = cloneHead;

	while(originalNode != NULL && cloneNode != NULL){
		Node* next = originalNode->next;
		originalNode->next = cloneNode;
		originalNode = next;

		next = cloneNode->next;
		cloneNode->next = originalNode;
		cloneNode = next;
	}

	// step-3: random pointer copy
	temp = head;
	while(temp != NULL){
		if(temp->next != NULL){
			temp->next->random = temp->random ? temp->random->next : temp->random;
		}
		temp = temp->next->next;
	}

	// step-4: revert changes done in step-2
	originalNode = head;
	cloneNode = cloneHead;

	while(originalNode != NULL && cloneNode != NULL){
		originalNode->next = cloneNode->next;
		originalNode = originalNode->next;

		if(originalNode != NULL){
			cloneNode->next = originalNode->next;
			cloneNode = cloneNode->next;
		}
	}


	// step-5: return ans
	return cloneHead;
}


int main(){
	Node *original = new Node(1);
    original->next = new Node(2);
    original->next->next = new Node(3);
    original->next->next->next = new Node(4);
    original->next->next->next->next = new Node(5);
    original->random = original->next->next;
    original->next->random = original;
    original->next->next->random = original->next->next->next->next;
    original->next->next->next->random = original->next->next;
    original->next->next->next->next->random = original->next;


    cout << "Original Linked List : ";
    printList(original);

    cout << "Clone Linked List : ";
    // Node* temp = copyList(original);
    Node* temp = copyList2(original);
    printList(temp);

}