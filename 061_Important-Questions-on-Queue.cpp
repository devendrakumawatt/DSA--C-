#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;


						// ** Reverse Queue **

queue<int> rev(queue<int> q){
	stack<int> s;

	while(!q.empty()){
		int element = q.front();
		q.pop();
		s.push(element);
	}

	while(!s.empty()){
		int element = s.top();
		s.pop();
		q.push(element);
	}
	return q;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
	queue<int> q;
	q.push(4);
	q.push(3);
	q.push(1);
	q.push(10);
	q.push(2);
	q.push(6);

	cout << "Given Queue : " ;
	printQueue(q);

	q = rev(q);

	cout << "Reversed Queue : ";
	printQueue(q);

}





/*							 // ** Find -ve no. in window size K ** 

vector<long long> printNegativeInteger(long long int A[], long long int N, long long int K){
	deque<long long int> dq;
	vector<long long> ans;

	// process first window of k size

	for(int i=0; i<K; i++){
		if(A[i] < 0){
			dq.push_back(i);
		}
	}

	// store answer of first k size element
	if(dq.size() > 0){
		ans.push_back(A[dq.front()]);
	}
	else{
		ans.push_back(0);
	}

	//process for remaining window
	for(int i=K; i<N; i++){
		// removal
		if(!dq.empty() && i - dq.front() >= K){
			dq.pop_front();
		}

		// addition
		if(A[i] < 0){
			dq.push_back(i);
		}

		// ans
		if(dq.size() > 0){
			ans.push_back(A[dq.front()]);
		}
		else{
			ans.push_back(0);
		}
	}
	return ans;
}

int main(){
	vector<long long> num = {-8,2,3,-6,10};
	long long int N = num.size();
	long long int K = 2;

	cout << "Given Integer Array : ";
	for(int i=0; i<N; i++){
		cout << num[i] << " ";
	}cout<<endl;

	vector<long long> ans = printNegativeInteger(num.data(), N, K);
	
	cout << "Negative Integer Array : ";
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}cout<<endl;	
}
*/




/*							// ** Reverse first k element of queue **

queue<int> modifyQueue(queue<int> q, int k){

	// pop first k elements from queue and put into stack
	stack<int> s;
	for(int i=0; i<k; i++){
		int val = q.front();
		q.pop();
		s.push(val);
	}

	// fetch element from stack and push into queue
	while(!s.empty()){
		int val = s.top();
		s.pop();
		q.push(val);
	}
	// fetch (n-k) element from queue and push back
	int t = q.size()-k;

	while(t--){
		int val = q.front();
		q.pop();
		q.push(val);
	}
	return q;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	int k = 3;

	cout << "Given Queue : " ;
	printQueue(q);

	q = modifyQueue(q, k);

	cout << "Modified Queue : ";
	printQueue(q);
}
*/




/*								// ** find non-repeating character in a stream **

class Solution {
public:
	string firstNonRepeating(string A){
		unordered_map<char, int> count;
		queue<int> q;
		string ans = "";

		for(int i=0; i<A.length(); i++){
			char ch = A[i];

			count[ch]++;

			q.push(ch);

			while(!q.empty()){
				if(count[q.front()] > 1){
					q.pop();
				}
				else{
					ans.push_back(q.front());
					break;
				}
			}
			if(q.empty()){
				ans.push_back('#');
			}
		}
		return ans;
	}
};

int main(){
	Solution s;
	string str = "aabbbccdeee";
	cout << "Given string : " << str << endl;

	string ans = s.firstNonRepeating(str);

	cout << "Output string : " << ans << endl;
}
*/



/*							// ** Circular Tour **


struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
	public:


		int tour(petrolPump p[], int n){
			int deficient = 0;
			int balance = 0;
			int start = 0;

			for(int i=0; i<n; i++){
				balance = balance + p[i].petrol - p[i].distance;
				if(balance < 0){
					deficient = deficient + balance;
					start = i+1;
					balance = 0;
				}
			}

			if(deficient + balance >= 0){
				return start;
			}
			else{
				return -1;
			}
		}
};

int main(){
	Solution sol;

    petrolPump pump1[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n1 = sizeof(pump1) / sizeof(pump1[0]);

    cout << "Petrol and Distance for each pump:" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "       " << i << ": {" << pump1[i].petrol << ", " << pump1[i].distance << "}" << endl;
    }cout << endl;

    cout << "Index to start tour: " << sol.tour(pump1, n1) << endl;
}
*/





/*									// ** 'K'-Queues in an array

class Kqueue {
public:
	int n;
	int k;
	int *front;
	int *rear;
	int *arr;
	int freespot;
	int *next;

	Kqueue(int  n, int k){
		this->n = n;
		this->k = k;
		front = new int[k];
		rear = new int[k];

		for(int i=0; i<k; i++){
			front[i] = -1;
			rear[i] = -1;
		}

		next = new int[n];
		for(int i=0; i<n; i++){
			next[i] = i+1;
		}
		next[n-1] = -1;

		arr = new int[n];
		freespot = 0;
	}

	void enqueue(int data, int qn){
		// overflow checck
		if(freespot == -1){
			cout << "No empty space is present" << endl;
		}

		// first free index
		int index = freespot;

		// update freespot
		freespot = next[index];

		// check whether first element
		if(front[qn-1] == -1){
			front[qn-1] = index;
		}
		else{
			// link new element to the prev element
			next[rear[qn-1]] = index;
		}

		// update next
		next[index] = -1;

		// update rear
		rear[qn-1] = index;

		// push element
		arr[index] = data;
	}

	int dequeue(int qn){
		// underflow
		if(front[qn-1] == -1){
			cout << "Queue underflow" << endl;
			return -1;
		}
		
		// find index to pop
		int index = front[qn-1];

		// front update
		front[qn-1] = next[index];

		// freespot manage
		next[index] = freespot;
		freespot = index;

		return arr[index];
	}

	~Kqueue() {
        delete[] front;
        delete[] rear;
        delete[] arr;
        delete[] next;
    }
};


int main(){
	Kqueue kq(10, 3);

    kq.enqueue(10, 1);
    kq.enqueue(20, 1);
    kq.enqueue(30, 2);
    kq.enqueue(40, 3);

    cout << "Dequeued from queue 1: " << kq.dequeue(1) << endl;
    cout << "Dequeued from queue 2: " << kq.dequeue(2) << endl;
    cout << "Dequeued from queue 3: " << kq.dequeue(3) << endl;

    cout << "Dequeued from queue 1: " << kq.dequeue(1) << endl;
    cout << "Dequeued from queue 1: " << kq.dequeue(1) << endl;
}
*/





/*							// ** Sum of maximum and minimum element of all sub-arrays of size k **

int solve(int *arr, int n, int k){
	deque<int> maxi(k);
	deque<int> mini(k);

	// addition of first k size window
	for(int i=0; i<k; i++){

		while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
			maxi.pop_back();
		}

		while(!mini.empty() && arr[mini.back()] >= arr[i]){
			mini.pop_back();
		}

		maxi.push_back(i);
		mini.push_back(i);
	}

	int ans = 0;
	for(int i=k; i<n; i++){
		ans = ans + arr[maxi.front()] + arr[mini.front()];

		// next window
		// removal
		while(!maxi.empty() && i - maxi.front() >= k){
			maxi.pop_front();
		}

		while(!mini.empty() && i - mini.front() >= k){
			mini.pop_front();
		}

		// addition
		while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
			maxi.pop_back();
		}

		while(!mini.empty() && arr[mini.back()] >= arr[i]){
			mini.pop_back();
		}

		maxi.push_back(i);
		mini.push_back(i);
	}

	// make sure to consider last window
	ans = ans + arr[maxi.front()] + arr[mini.front()];
	return ans;

}

int main(){
	int arr[7] = {2, 5, -1, 7, -3, -1, -2};
	int k = 4;

	cout << "Given Array : ";
	for(int i=0; i<7; i++){
		cout << arr[i] << " ";
	}cout<<endl;

	cout << "Sum of max and min of all sub-arrays of size-4 : " << solve(arr, 7, k) << endl;
}
*/