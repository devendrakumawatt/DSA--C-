#include<iostream>
#include<queue>
using namespace std;

					// ** Doubly ended Queue **
class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~Deque()
    {
        delete[] arr;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full or not
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
         if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main(){
	 Deque dq(5);

    cout << dq.pushRear(1) << endl;
    cout << dq.pushRear(2) << endl;
    cout << dq.pushFront(3) << endl;
    cout << dq.pushFront(4) << endl;
    cout << dq.pushFront(5) << endl;
    cout << dq.pushFront(6) << endl;

    cout << endl;

    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl << endl;

    cout << dq.popRear() << endl;
    cout << dq.popFront() << endl;
    cout << dq.popFront() << endl << endl;

    cout << dq.isEmpty() << endl;
    cout << dq.isFull() << endl;
}










/*					// ** Doubly ended queue STL **


int main(){
	deque<int> q;

	q.push_front(12);
	q.push_back(15);

	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop_front();

	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop_back();

	cout << q.front() << endl;
	cout << q.back() << endl;

	if(q.empty()){
		cout << "Queue is empty" << endl;
	}
	else{
		cout << "Queue is not empty" << endl;
	}
}
*/










/*						// ** Circular Queue **
class CircularQueue {
	public:
		int *arr;
		int front ;
		int rear;
		int size;


		CircularQueue(int n){
			size = n;
			arr = new int[size];
			front = rear = -1;
		}

		~CircularQueue() {
        delete[] arr;
    	}

		bool enqueue(int value){
			//to check if queue is full or not
			if((front == 0 && rear == size-1 ) || (rear == (front-1)%(size-1))){
				cout << "Queue is full" << endl;
				return false;
			}
			else if(front == -1){ // first element to push
				front = rear = 0;
			}
			else if(rear == size-1 && front != 0){
				rear = 0; //to maintain cyclic nature
			}
			else{
				rear++;
			}
			arr[rear] = value;
			return true;
		}

		int dequeue(){
			if(front == -1){
				cout << "Queue is empty" << endl;
				return -1;
			}
			int ans = arr[front];
			if(front == rear){ //single element is present
				front = rear = -1;
			}

			else if(front == size-1){
				front = 0; // to maintain cyclic nature
			}
			else{
				front++;
			}
			return ans;

		}
};



int main(){

    CircularQueue cq(5);

    // Test enqueue
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); 

    cout << endl;

    // Test dequeue
    cout << "Popped element : " << cq.dequeue() << endl;
    cout << "Popped element : " << cq.dequeue() << endl;

    cout << endl;

    // Continue testing
    cq.enqueue(70);
    cout << "Popped element : " << cq.dequeue() << endl;
    cout << "Popped element : " << cq.dequeue() << endl;
    cout << "Popped element : " << cq.dequeue() << endl;
    cout << "Popped element : " << cq.dequeue() << endl <<endl;
    cout << "Popped element : " << cq.dequeue() << endl;

    cout << endl;

}
*/







/*					// ** Simple Queue **
class Queue {
public:
	int *arr;
	int qfront;
	int rear;
	int size;

	Queue(){
		size = 1000;
		arr = new int[size];
		qfront = 0;
		rear = 0;
	}


	bool isEmpty(){
		if(qfront == rear){
			return true;
		}
		else{
			return false;
		}

	}

	void enqueue(int data){
		if(rear == size){
			cout << "Queue is full "<< endl;
		}
		else{
			arr[rear] = data;
			rear++;
		}
	}

	int dequeue(){
		if(qfront == rear){
			return -1;
		}
		else{
			int ans = arr[qfront];
			arr[qfront] = -1;
			qfront++;
			if(qfront == rear){
				qfront = 0;
				rear = 0;
			}
			return ans;
		}
	}
	int front(){
		if(qfront == rear){
			return -1;
		}
		else{
			return arr[qfront];
		}
	}
};



int main(){
	Queue q;

	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);


	cout << "Popped element : " << q.dequeue() << endl;
	cout << "Is Queue empty : ";
	if(q.isEmpty()){
		cout << "yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
*/





/*
	// create a queue
	queue<int> q;
	q.push(11);
	q.push(15);
	q.push(13);

	cout << "Size of queue is : "<< q.size() << endl;

	q.pop();

	cout << "Size of queue after pop is : " << q.size() << endl;

	if(q.empty())
		cout << "Queue is empty" << endl;

	else
		cout << "queue is not empty" << endl;

	cout << "Front element is : " << q.front() << endl;
}
*/