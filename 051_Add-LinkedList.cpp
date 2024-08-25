#include<iostream>
using namespace std;

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

Node* reverse(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val){
	Node* temp = new Node(val);

	// empty list
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	else{
		tail->next = temp;
		tail = temp;
	}

}

Node* add(Node* first, Node* second){
	int carry = 0;

	Node* ansHead = NULL;
	Node* ansTail = NULL;

	while(first != NULL || second != NULL || carry != 0){

		int val1 = 0;
		if(first != NULL)
			val1 = first->data;

		int val2 = 0;
		if(second != NULL)
			val2 = second->data;

		int sum = carry + val1 + val2;

		int digit = sum%10;

		// create node and add answer linked list
		insertAtTail(ansHead, ansTail, digit);

		carry = sum/10;
		if(first != NULL)
			first = first->next;

		if(second != NULL)
			second = second->next;
	}
	return ansHead;
}

Node* addTwoList(Node* first, Node* second){
	// reverse the input
	first = reverse(first);
	second = reverse(second);

	// add two linked list
	Node* ans = add(first, second);

	// reverse again
	ans = reverse(ans);

	return ans;
}

int main(){
	Node *first = new Node(4);
    first->next = new Node(5);
    first->next->next = new Node(3);

    Node *second = new Node(3);
    second->next = new Node(2);
    second->next->next = new Node(5);
    second->next->next->next = new Node(0);

    cout << " First Linked List  : ";
    print(first);
    cout << " Second Linked List : ";
    print(second);

    first = addTwoList(first, second);
    cout << " Answer of adding two Linked List : ";
    print(first);

}