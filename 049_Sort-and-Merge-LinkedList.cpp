#include<iostream>
using namespace std;

/*				// ** Sort 0's, 1's, 2's in linked list **

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

// Approach - 1

Node* sortLinkedList(Node* head){
	int zeroCount = 0;
	int oneCount = 0;
	int twoCount = 0;

	Node* temp = head;
	while(temp != NULL){
		if(temp->data == 0)
			zeroCount++;

		else if(temp->data == 1)
			oneCount++;

		else if(temp->data == 2)
			twoCount++;


		temp = temp->next;
	}
	temp = head;
	while(temp != NULL){
		if(zeroCount != 0){
			temp->data = 0;
			zeroCount--;
		}
		else if(oneCount != 0){
			temp->data = 1;
			oneCount--;
		}
		else if(twoCount != 0){
			temp->data = 2;
		}
		temp = temp->next;
	}
	return head;
}

// Approach -2 

void insertAtTail(Node* &tail, Node* curr){
	tail->next = curr;
	tail = curr;
}

Node* sortLinkedList2(Node* head){
	Node* zeroHead = new Node(-1);
	Node* zeroTail = zeroHead;
	Node* oneHead = new Node(-1);
	Node* oneTail = oneHead;
	Node* twoHead = new Node(-1);
	Node* twoTail = twoHead;

	Node* curr = head;

	// create separate list 0's , 1's, 2's
	while(curr != NULL){
		int value = curr->data;

		if(value == 0){
			insertAtTail(zeroTail, curr);
		}
		else if(value == 1){
			insertAtTail(oneTail, curr);
		}
		else if(value == 2){
			insertAtTail(twoTail, curr);
		}

		curr = curr->next;
	}
	// Merge 3 sublists

	// 1's list is non empty
	if(oneHead->next != NULL){
		zeroTail->next = oneHead->next;
	}
	else{
		// 1's list is empty
		zeroTail->next = twoHead->next;
	}

	oneTail->next = twoHead->next;
	twoHead->next = NULL;

	// setup head
	head = zeroHead->next;

	// delete dummy nodes
	delete zeroHead;
	delete oneHead;
	delete twoHead;

	return head;
}

int main(){
	Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    cout << "Given linked list : ";
    print(head);

    head = sortLinkedList2(head);

    cout << "Sorted linked list : ";
    print(head);
}
*/


				// ** Merge two sorted linked list **

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

Node* solve(Node* &first, Node* &second){

	// if only one node element present in first list, copy second list to first list
	if(first->next == NULL){
		first->next = second;
		return first;
	}

	Node* curr1 = first;
	Node* next1 = curr1->next;
	Node* curr2 = second;
	Node* next2 = curr2->next;

	while(next1 != NULL && curr2 != NULL){
		if(curr2->data >= curr1->data && curr2->data <= next1->data){

			// add node in between the first list
			curr1->next = curr2;
			next2 = curr2->next;
			curr2->next = next1;
			// update pointers
			curr1 = curr2;
			curr2 = next2;
		}
		else{
			// curr1 and next1 ko aage badhana hai
			curr1 = next1;
			next1 = next1->next;

			if(next1 == NULL){
				curr1->next = curr2;
				return first;
			}
		}
	}
	return first;
}


Node* mergeTwoLinkedList(Node* &first, Node* &second){
	if(first == NULL)
		return second;

	if(second == NULL)
		return first;


	if(first->data <= second->data){
		solve(first, second);
	}
	else{
		solve(second, first);
	}
}


int main(){
	Node *first = new Node(1);
    first->next = new Node(3);
    first->next->next = new Node(5);
    first->next->next->next = new Node(7);

    Node *second = new Node(2);
    second->next = new Node(4);
    second->next->next = new Node(6);
    second->next->next->next = new Node(7);
    cout << "Given first linked list : ";
    print(first);

    cout << "Given first linked list : ";
    print(second);

    first = mergeTwoLinkedList(first, second);

    cout << endl << "Merged linked list : ";
    print(first);
}