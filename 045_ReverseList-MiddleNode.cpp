#include<iostream>
using namespace std;



/*				// *** Q - REVERSE THE LINKED LIST ***

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

void inserAtHead(Node * &head, int d){
	// new node create
	Node *temp = new Node(d);
	temp -> next = head;
	head = temp;
}


			// *** Recursive Solution ***

void reverse(Node* &head, Node* curr, Node* prev){
	//base case
	if(curr == NULL){
		head = prev;
		return;
	}

	Node *forward = curr->next;
	reverse(head, forward, curr);
	curr->next = prev;
}

Node* reverseLinkedList(Node* head){
	Node *curr = head;
	Node *prev = NULL;
	reverse(head, curr, prev);
	return head;
}




  //** Iterative solution **

// Node* reverseLinkedList(Node* head){

// 	if(head == NULL || head->next == NULL){
// 		return head;
// 	}

// 	Node *prev = NULL;
// 	Node *curr = head;
// 	Node *forward = NULL;

// 	while(curr != NULL){
// 		forward = curr->next;
// 		curr->next = prev;
// 		prev = curr;
// 		curr = forward;
// 	}
// 	return prev;
	
// }



int main(){
	Node *node1 = new Node(22);

	Node *head = node1;
	Node *tail = node1;

	inserAtHead(head, 20);
	print(head);
	inserAtHead(head, 17);
	print(head);
	inserAtHead(head, 15);
	print(head);
	inserAtHead(head, 11);

	cout << "Given Linked list : " ;
	print(head);

	head = reverseLinkedList(head);
	cout << "Reversed Linked List : ";
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



			// *** Q - MIDDLE OF LINKED LIST

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


int middleValue(Node* head){
    if (head == NULL) {
        // Handle empty list case
        return -1; // Assuming -1 is not a valid data value in your list
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data; // Return the data of the middle node
}


int main(){
    Node *head = new Node(22);

    head->next = new Node(20);
    head->next->next = new Node(17);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(11);

    cout << "Given Linked list : ";
    print(head);

    cout << "Middle Value is : " << middleValue(head) << endl;

    // Free allocated memory (cleanup)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

