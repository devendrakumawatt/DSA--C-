#include<iostream>
#include<map>
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

					//** Detect loop in Linked List **
bool detectLoop(Node* head){
	if(head == NULL)
		return false;

	map<Node*, bool> visited;

	Node* temp = head;

	while(temp != NULL){
		// cycle is present
		if(visited[temp] == true){
			cout << "Loop present on element " << temp->data << endl;
			return true;
		}

		visited[temp] = true;
		temp = temp->next;
	}
	return false;
}

					//*** Floyd's Loop detection algo ***

Node* floydDetectLoop(Node* head){
	if(head == NULL){
		return NULL;
	}

	Node* slow = head;
	Node* fast = head;

	while(slow != NULL && fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
		}

		slow = slow->next;

		if(slow == fast){
			// cout << "Loop present at  " << slow->data << endl;
			return slow;
		}
	}
	return NULL;
}

					// ** Getting starting Node of a loop in Linked List **

Node* getStartingNode(Node* head){
	if(head == NULL){
		return NULL;
	}

	Node* intersection = floydDetectLoop(head);
	Node* slow = head;

	while(slow != intersection){
		slow = slow->next;
		intersection = intersection->next;
	}
	return slow;
}

					// *** Removing Loop ***

void removeLoop(Node* head){
	if(head == NULL){
		return;
	}

	Node* startLoop = getStartingNode(head);
	Node* temp = startLoop;
	
	while(temp->next != startLoop){
		temp = temp->next;
	}

	temp->next = NULL;
}



int main(){
	Node *head = new Node(22);

    head->next = new Node(20);
    head->next->next = new Node(17);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(11);
    head->next->next->next->next->next =  head->next->next;

    // cout << "Given Linked list : ";
    // print(head);

    // if(detectLoop(head)){
   	// 	cout << "Loop present" << endl;
   	// }
   	// else{
   	// 	cout << "Loop is not present" << endl;
   	// }

   	if(floydDetectLoop(head) != NULL){
   		cout << "Loop present in Linked List " << endl;
   	}
   	else{
   		cout << "Loop is not present" << endl;
   	}

   	Node* loop = getStartingNode(head);
   	cout << "Loop starts at Node : " << loop->data << endl;


   	removeLoop(head);
   	cout << "Loop removed now " << endl;
   	cout << "Linked List is : " ;
   	print(head);


    // Free allocated memory (cleanup)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}