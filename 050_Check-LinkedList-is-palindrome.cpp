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

Node* getMid(Node* head){
	Node* slow = head;
	Node* fast = head->next;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
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


bool isPalindrome(Node* head){
	if(head->next == NULL){
		return true;
	}

	// step-1: find middle
	Node* middle = getMid(head);

	// step-2: reverse the list after middle
	Node* temp = middle->next;
	middle->next = reverse(temp);

	// step-3: compare both halves
	Node* head1 = head;
	Node* head2 = middle->next;

	while(head2 != NULL){
		if(head1->data != head2->data){
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	// step-4: repeat step-2
	temp = middle->next;
	middle->next = reverse(head);


	return head;
}

int main(){

	Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    cout << "Given first linked list : ";
    print(head);

    if(isPalindrome(head))
    	cout << "The Linked List is Palindrome " << endl;

    else
    	cout << "The Linked List is not Palindrome " << endl;
}