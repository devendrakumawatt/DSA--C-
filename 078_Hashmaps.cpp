#include<iostream>
#include<map>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;


int main(){
	// creation
	unordered_map<string,int> m;

	// insertion
	pair<string,int> p = make_pair("devendra",3);
	m.insert(p);

	pair<string,int> pair2("mera",2);
	m.insert(pair2);

	m["naam"] = 1;

	// search
	cout << m["naam"] << endl;
	cout << m.at("devendra") << endl;

	cout << m["unknownKey"] << endl;
	cout << m.at("unknownKey") << endl;


	// size
	cout << m.size() << endl;

	// to check presence
	cout << m.count("bro") << endl;
	cout << m.count("devendra") << endl;

	// erase
	m.erase("naam");
	cout << m.size() << endl;

	// traversal
	// for(auto i:m){
	// 	cout << i.first << " " << i.second << endl;
	// }

	// iterator
	unordered_map<string,int> :: iterator it = m.begin();

	while(it != m.end()){
		cout << it->first << " " << it->second << endl;
		it++;
	}
}











/*								// *** Maximum Frequency Number ***

int maximumFrequency(vector<int> &arr, int n){
	unordered_map<int,int> count;

	int maxFreq = 0;
	int maxAns = 0;

	for(int i=0; i<arr.size(); i++){
		count[arr[i]]++;
		maxFreq = max(maxFreq, count[arr[i]]);
	}

	for(int i=0; i<arr.size(); i++){
		if(maxFreq == count[arr[i]]){
			maxAns = arr[i];
		}
	}
	return maxAns;
}

int main(){
	vector<int> num = {2,3,4,1,2,1,2,1,3,4,2,1,5,7,1,1,1,1,2,2,2,2,1,7,6};
	int n = 25;

	int res = maximumFrequency(num, n);
	cout << "Maximum Frequency Number is : " << res << endl;
}
*/