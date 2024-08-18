#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	// constructor
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}

	// destructor
	~Node(){
		int value = this->data;
		// memory free
		if(this->next != NULL){
			delete next;
			this -> next = NULL;
		}
		cout << "Memory is free for node with data "<< value << endl;
	}
};

void inserAtHead(Node * &head, int d){
	// new node create
	Node *temp = new Node(d);
	temp -> next = head;
	head = temp;
}

void insertAtTail(Node * &tail, int d){
	// new node create
	Node *temp = new Node(d);
	tail -> next = temp;
	tail = tail -> next;
}

void print(Node * &head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << "  ";
		temp = temp -> next;
	}
	cout << endl;
}


// Insert at any position
void insertAtPosition(Node * &tail, Node * &head, int position, int d){
	// Insert at start
	if(position == 1){
		inserAtHead(head, d);
		return;
	}

	Node *temp = head;
	int cnt = 1;

	while(cnt < position-1){
		temp = temp -> next;
		cnt++;
	}

	// adding at tail
	if(temp -> next == NULL){
		insertAtTail(tail,d);
		return;
	}

	// create a node for d
	Node *nodeToInsert = new Node(d);
	nodeToInsert -> next = temp -> next;
	temp -> next = nodeToInsert;
}

void deleteNode(int position, Node * &head){
	//deleting first node
	if(position == 1){
		Node *temp = head;
		head = head -> next;
		// memory free
		temp->next = NULL;
		delete temp;
	}
	else{
		// deleting any middle node or last node
		Node *curr = head;
		Node *prev = NULL;

		int cnt = 1;
		while(cnt < position){
			prev = curr;
			curr = curr -> next;
			cnt++;
		}
		prev -> next = curr -> next;
		curr->next = NULL;
		delete curr;
	}
}


int main(){

	// create a new Node
	Node *node1 = new Node(10);
	// cout << node1 -> data << endl;
	// cout << node1 -> next << endl;

	// head pointed to node 1
	Node *head = node1;
	Node *tail = node1;
	print(head);

	insertAtTail(tail, 12);

	print(head);

	insertAtTail(tail, 15);

	print(head);

	insertAtPosition(tail, head, 1, 22);

	print(head);

	cout << "Head -> " << head -> data << endl;
	cout << "Tail -> " << tail -> data << endl;

	deleteNode(1, head);
	print(head);

}