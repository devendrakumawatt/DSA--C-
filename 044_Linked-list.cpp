#include<iostream>
using namespace std;


/*
		// **** Singly linked list ****
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

*/





/*		// *** Doubly linked list *** 


class Node{
public:
	int data;
	Node* prev;
	Node* next;

	// constructor
	Node(int d){
		this -> data = d;
		this -> prev = NULL;
		this -> next = NULL;
	}


	// destructor
	~Node(){
		int val = this->data;
		if(next != NULL){
			delete next;
			next = NULL;
		}
		cout << "Memory free for node with data "<<val<<endl;
	}
};


// traverse a linked list
void print(Node* &head){
	Node* temp = head;

	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


// gives length of linked list
int getLength(Node* head){
	int len = 0;
	Node* temp = head;

	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}

// insert at head
void insertAtHead(Node* &tail, Node* &head, int d){
	// empty list
	if(head == NULL){
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else{
		Node* temp = new Node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	
}

//insert at tail
void insertAtTail(Node* &head, Node* &tail, int d){
	if(tail == NULL){
		Node* temp = new Node(d);
		tail = temp;
		head = temp;
	}
	else{
		Node* temp = new Node(d);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	
}

// insert at any position
void insertAtPosition(Node* &head, Node* &tail, int position, int d){
	// add at start
	if(position == 1){
		insertAtHead(tail, head, d);
		return;
	}

	Node* temp = head;
	int cnt = 1;

	while(cnt < position-1){
		temp = temp->next;
		cnt++;
	}

	// add at last
	if(temp->next == NULL){
		insertAtTail(head, tail, d);
		return;
	}

	// add in middle
	Node* nodeToInsert = new Node(d);

	nodeToInsert->next = temp->next;
	temp->next->prev = nodeToInsert;
	temp->next = nodeToInsert;
	nodeToInsert->prev = temp;
}


void deleteNode(int position, Node * &head){
	//deleting first node
	if(position == 1){
		Node *temp = head;
		temp->next->prev = NULL;
		head = temp->next;
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
		curr->prev = NULL;
		prev-> next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}



int main(){
	Node* head = NULL;
	Node* tail = NULL;

	print(head);
	// cout << getLength(head) << endl;

	insertAtHead(tail, head, 11);
	print(head);
	cout << "head ->" << head->data << endl;
	cout << "tail ->" << tail->data << endl;

	insertAtHead(tail, head, 14);
	print(head);
	cout << "head ->" << head->data << endl;
	cout << "tail ->" << tail->data << endl;

	insertAtHead(tail, head, 16);
	print(head);
	cout << "head ->" << head->data << endl;
	cout << "tail ->" << tail->data << endl;

	insertAtTail(head, tail, 18);
	print(head);
	cout << "head ->" << head->data << endl;
	cout << "tail ->" << tail->data << endl;


	insertAtPosition(head, tail, 2, 100);
	print(head);
	cout << "head ->" << head->data << endl;
	cout << "tail ->" << tail->data << endl;


	deleteNode(3, head);
	print(head);
	cout << "head ->" << head->data << endl;
	cout << "tail ->" << tail->data << endl;
}

*/




			// **** Circular linked list ****


class Node{
public:
	int data;
	Node* next;

	// constructor
	Node(int d){
		this->data = d;
		this->next = NULL;
	}


	// Destructor
	~Node(){
		int value = this->data;
		if(this->next != NULL){
			delete next;
			next = NULL;
		}
		cout << "Memory is free for node with data " << value << endl;
	}
};

void insertNode(Node* &tail, int element, int d){

	// empty list
	if(tail == NULL){
		Node* newNode = new Node(d);
		tail = newNode;
		newNode->next = newNode;
	}
	// non-empty list
	// assuming that the element is present in the list
	else{
		Node* curr = tail;

		while(curr->data != element){
			curr = curr->next;
		}

		// element found -> curr is representing element wala node
		Node* temp = new Node(d);
		temp->next = curr->next;
		curr->next = temp;
	}
}

void print(Node* tail){
	Node* temp = tail;
	if(tail == NULL){
		cout << "List is empty!" <<endl;
		return;
	}


	do{
		cout << tail->data << " ";
		tail = tail->next;
	}while(tail != temp);
	cout << endl;
}

void deleteNode(Node* &tail, int value){
	// empty list
	if(tail == NULL){
		cout << "list is empty , check again"<<endl;
		return;
	}
	// non-empty list
	else{
		// assuming "value" present in the list
		Node* prev = tail;
		Node* curr = prev->next;

		while(curr->data != value){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;

		// 1 Node linked list
		if(curr == prev){
			tail = NULL;
		} 

		// >=2 Node linked list
		if(tail == curr){
			tail = prev;
		}
		curr->next = NULL;
		delete curr;
	}
}


int main(){
	Node* tail = NULL;

	// empty list mai insert kr rhe hai
	insertNode(tail, 5, 3);
	print(tail);

	insertNode(tail, 3, 5);
	print(tail);

	insertNode(tail, 5, 7);
	print(tail);

	insertNode(tail, 7, 9);
	print(tail);

	insertNode(tail, 9, 11);
	print(tail);

	insertNode(tail, 5, 6);
	print(tail);

	insertNode(tail, 3, 4);
	print(tail);

	insertNode(tail, 11, 12);
	print(tail);


	deleteNode(tail, 5);
	print(tail);
}