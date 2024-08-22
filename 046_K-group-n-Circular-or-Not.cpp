#include<iostream>
using namespace std;

/*					//** Reverse Linked list in k-groups **

class Node{
public:
	int data;
	Node *next;

	// constructor
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
};


void print(Node * &head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << "  ";
		temp = temp -> next;
	}
	cout << endl;
}

Node* kReverse(Node* head, int k){
	// base case
	if(head == NULL){
		return NULL;
	}

	// step1: reverse first k node
	Node* next = NULL;
	Node* curr = head;
	Node* prev = NULL;
	int cnt = 0;

	while(curr != NULL && cnt < k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}

	// step2: recursion dekh lega 
	if(next != NULL){
		head->next = kReverse(next,k);
	}


	// step3: return head of reversed linked list
	return prev;
}


int main(){

	Node *head = new Node(11);
    head->next = new Node(13);
    head->next->next = new Node(15);
    head->next->next->next = new Node(17);
    head->next->next->next->next = new Node(19);

    cout << "Given Linked list : ";
    print(head);

    int k = 2;
    head = kReverse(head,k);
    cout << "Reversed Linked List after reverse in k = "<< k << " Groups : ";
    print(head);

    // Free allocated memory (cleanup)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
*/


					// ** Circular linked list or Not **

class Node{
public:
    int data;
    Node *next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}


bool isCircular(Node* head){
	if(head == NULL){
		return true;
	}

	Node* temp = head->next;
	while(temp != NULL && temp != head){
		temp = temp->next;
	}

	if(temp == head){
		return true;
	}
	return false;
}



int main(){
	Node *head = new Node(22);

    head->next = new Node(20);
    head->next->next = new Node(17);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(11);

    // cout << "Given Linked list : ";
    // print(head);

   	if(isCircular(head)){
   		cout << "Linked list is circular" << endl;
   	}
   	else{
   		cout << "Linked list is not circular" << endl;
   	}

    // Free allocated memory (cleanup)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}