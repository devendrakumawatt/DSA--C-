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

Node* uniqueSortedList(Node* head){
	// empty list
	if(head == NULL){
		return NULL;
	}

	// non empty list
	Node* curr = head;

	while(curr != NULL){
		if((curr->next != NULL) && curr->data == curr->next->data){
			Node* nextNode = curr->next->next;
			Node* nodeToDelete = curr->next;
			delete(nodeToDelete);
			curr->next = nextNode;
		}
		else{
			// not equal
			curr = curr->next;
		}
	}
	return head;
}

int main(){
	Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);

    cout << "Given linked list : ";
    print(head);

    head = uniqueSortedList(head);

    cout << "Unique sorted list : ";
    print(head);

}