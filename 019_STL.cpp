// Array STL ------------------

// #include<iostream>
// #include<array>
// using namespace std;

// int main(){

// 	int basic[3] = {1,2,3};
// 	array<int,4> a = {1,2,3,4};
// 	int size = a.size();

// 	for(int i=0; i<size; i++){
// 		cout << a[i] <<endl;
// 	}

// 	cout << "Element at 2nd index : "<<a.at(2)<<endl;
// 	cout << "Element or not in array : "<<a.empty()<<endl;
// 	cout << "First Element : "<<a.front()<<endl;
// 	cout << "Last Element : "<<a.back()<<endl;

// }




// Vector STL ------------

// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){

// 	vector<int> v;
// 	cout<<"capacity : "<<v.capacity() <<endl;

// 	v.push_back(1);
// 	cout<<"capacity : "<<v.capacity() <<endl;

// 	v.push_back(2);
// 	cout<<"capacity : "<<v.capacity() <<endl;

// 	v.push_back(3);
// 	cout<<"capacity : "<<v.capacity() <<endl;

// 	cout<<"Size : "<<v.size()<<endl;

// 	cout<<"element at 1 index : " <<v.at(1)<<endl;
// }



// Deque STL ------------

// #include<iostream>
// #include<deque>
// using namespace std;

// int main(){

// 	deque<int> d;

// 	d.push_back(1);
// 	d.push_front(2);

// 	for(int i:d){
// 		cout<<i<<" ";
// 	}

// 	cout<<endl;
// 	cout<<"element at 1st index : "<<d.at(1)<<endl;


// }




// List STL ------------

// #include<iostream>
// #include<list>
// using namespace std;

// int main(){

// 	list<int> l;

// 	l.push_back(3);
// 	l.push_front(1);

// 	for(int i:l){
// 		cout<<i<<" ";
// 	}
// 	cout<<endl;

// }




// Stack STL ------------

// #include<iostream>
// #include<stack>
// using namespace std;

// int main(){

// 	stack<string> s;

// 	s.push("Devendra");
// 	s.push("kumar");
// 	s.push("kumawat");

// 	cout<<"top element = "<<s.top()<<endl;


// 	s.pop();
// 	cout<<"top element = "<<s.top()<<endl;
// }


// Queue STL ------------

// #include<iostream>
// #include<queue>
// using namespace std;

// int main(){

// 	queue<string> q;

// 	q.push("Devendra");
// 	q.push("kumar");
// 	q.push("kumawat");

// 	cout<<"first element = "<<q.front()<<endl;

// 	cout<<"size before pop : "<<q.size()<<endl;

// 	q.pop();
// 	cout<<"first element = "<<q.front()<<endl;


// 	cout<<"size after pop : "<<q.size()<<endl;
// }




// Priority Queue STL ------------

// #include<iostream>
// #include<queue>
// using namespace std;

// int main(){

// 	// max heap
// 	priority_queue<int> maxi;

// 	// min heap
// 	priority_queue<int,vector<int>, greater<int> > mini;


// 	maxi.push(1);
// 	maxi.push(4);
// 	maxi.push(3);
// 	maxi.push(6);

// 	cout<<"maxi size : "<<maxi.size()<<endl;

// 	int n = maxi.size();
// 	for(int i=0; i<n; i++){
// 		cout<<maxi.top()<< " ";
// 		maxi.pop();
// 	}cout<<endl;

// 	mini.push(2);
// 	mini.push(4);
// 	mini.push(8);
// 	mini.push(1);

// 	cout<<endl;
// 	cout<<"mini size : "<<mini.size()<<endl;

// 	int x = mini.size();
// 	for(int i=0; i<x; i++){
// 		cout<<mini.top()<< " ";
// 		mini.pop();
// 	}
// }



// Set STL ----------------------
// #include<iostream>
// #include<set>
// using namespace std;

// int main(){
// 	set<int> s;

// 	s.insert(5);
// 	s.insert(5);
// 	s.insert(5);
// 	s.insert(5);
// 	s.insert(5);

// 	s.insert(14);
// 	s.insert(12);
// 	s.insert(2);


// 	for(int i:s){
// 		cout<<i<<" ";
// 	}cout<<endl;

// 	cout<<"Count : "<<s.count(5)<<endl;


// }




// Map STL ----------------------
// #include<iostream>
// #include<map>
// using namespace std;

// int main(){
// 	map<int,string> m;

// 	m[1]="Devendra";
// 	m[2]="Libra";
// 	m[3]="M5";

// 	m.insert({4,"Vegas"});

// 	for(auto i:m){
// 		cout<<i.first<<" : "<<i.second<<endl;
// 	}

// 	cout<<"finding 13 : "<<m.count(13)<<endl;


// }




// Algorithms==========================

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

	vector<int> v;
	v.push_back(4);
	v.push_back(6);
	v.push_back(10);
	v.push_back(15);


	cout<<"Finding 10 => "<<binary_search(v.begin(),v.end(),10)<<endl;
	cout<<"lower bound => "<<lower_bound(v.begin(),v.end(),15)-v.begin()<<endl;
	cout<<"upper bound => "<<upper_bound(v.begin(),v.end(),15)-v.begin()<<endl;


	int a=3;
	int b=5;

	cout<<"max = "<<max(a,b)<<endl;
	cout<<"min = "<<min(a,b)<<endl;



	int c=10;
	int d=8;

	swap(c,d);
	cout<<"value of c = "<<c<<endl;
	cout<<"value of d = "<<d<<endl;


	string str = "Devendra";
	reverse(str.begin(),str.end());
	cout<<"str after reversed = "<<str<<endl;

	rotate(v.begin(),v.begin()+1,v.end());
	cout<<"after rotate : " ;
	for(int i:v){
		cout<<i<<" " ;
	}cout<<endl;


	sort(v.begin(), v.end());
	cout<<"after sorting --- ";
	for(int i:v){
		cout<<i<<" ";
	}cout<<endl;
}