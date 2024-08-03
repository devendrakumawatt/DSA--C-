// length of char array 
// reverse of char array
// palindrome of char array
// max occuring character
// replace space by symbols
// removing occurence part
// permutation in string
// string compression

#include<iostream>
#include<vector>
using namespace std;

int getLength(char name[]){
	int count = 0;
	for(int i=0; name[i] != '\0'; i++){
		count++;
	}
	return count;
}

void reverse(char name[], int n){
	int s = 0;
	int e = n-1;
	while(s<e){
		swap(name[s++],name[e--]);
	}
}


char toLowerCase(char ch){
	if(ch >= 'a' && ch <= 'z'){
		return ch;
	}
	else{
		char temp = ch + 32;
		return temp;
	}
}


bool checkPalindrome(char arr[], int n){
	int s=0;
	int e=n-1;
	while(s<=e){

		if(toLowerCase( arr[s] ) != toLowerCase( arr[e] )){
			return 0;
		}
		else{
			s++;
			e--;
		}
	}
	return 1;
}


char getMaxOccChar(string s){
	int arr[26] ={0};

	for(int i=0; i<=s.length(); i++){
		char ch = s[i];
		int num = 0;
		num = ch - 'a';
		arr[num]++;
	}
	int maxi = -1, ans = 0;
	for(int i = 0; i<26; i++){
		if(maxi < arr[i]){
			ans = i;
			maxi = arr[i];
		}
	}
	char finlAns = 'a'+ans;
	return finlAns;
}


string replaceSpace(string &s){
	string temp = " ";

	for(int i=0; i<s.length(); i++){
		if(s[i] == ' '){
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');
		}
		else{
			temp.push_back(s[i]);
		}
	}
	return temp;
}


string removeOccurence(string s, string part){
	while(s.length() != 0 && s.find(part) < s.length()){
		s.erase(s.find(part), part.length());
	}
	return s;
}


bool checkEqual(int a[26], int b[26]){
	for(int i=0; i<26; i++){
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}


bool chackPermutation(string s1, string s2){
	int count[26] = {0};

	for(int i=0; i<s1.length(); i++){
		int index = s1[i] - 'a';
		count[index]++;
	}

	int i=0;
	int winSize = s1.length();
	int count2[26] = {0};

	while(i < winSize && i < s2.length( )){
		int index = s2[i] - 'a';
		count2[index]++;
		i++;
	}
	if(checkEqual(count, count2))
		return 1;

	while(i < s2.length()){
		char newChar = s2[i];
		int index = newChar - 'a';
		count2[index]++;

		char oldChar = s2[i-winSize];
		index = oldChar - 'a';
		count2[index]--;

		i++;

		if(checkEqual(count, count2)){
			return 1;
		}
	}
	return 0;
}


// int compress(vector<char> &chars){
// 	int i = 0;
// 	int ansIdx = 0;
// 	int n = chars.size();

// 	while(i<n){
// 		int j=i+1;
// 		while(j<n && chars[i] == chars[j]){
// 			j++;
// 		}

// 		chars[ansIdx++] = chars[i];

// 		int count = j-i;

// 		if(count>1){
// 			string cnt = to.string(court);
// 			dor(char ch: cnt){
// 				chars[ansIdx++] = ch;
// 			}
// 		}

// 		i=j;
// 	}
// 	return ansIdx;
// }




int main(){

	// char name[20];

	// cout<<"Enter your name : "<<endl;
	// cin >> name;

	// cout<<"Your name is : ";
	// cout<<name<<endl;

	// int len = getLength(name);
	// cout<<"Length : "<< len <<endl;


	// reverse(name,len);
	// cout << "Reverse : "<<name<<endl;


	// cout << "Char Array is Palindrome or Not: "<<checkPalindrome(name, len) <<endl;


	// string s;
	// cout << "Enter the String: ";
	// cin >> s;

	// cout <<"Maximum Occuring character of string is: "<< getMaxOccChar(s) <<endl;


	// string str;
	// cout << "Enter sample string sentence with space in between :"<<endl;
	// getline(cin,str);
	// cout << "Replaced string is: "<<replaceSpace(str) ;


	// string s;
	// cout << "Enter the string : ";
	// cin >> s;
	// cout << "The string left after removing occurence part : " <<removeOccurence(s,"abc");



	// string s1, s2;
	// cout << "Enter the string : ";
	// cin >> s1;
	// cout << "Enter the permutation string : ";
	// cin >> s2;

	// cout << "Is string has permutation in it : "<<chackPermutation(s1,s2)<<endl; 


	// vector<char> chars;
	// cout << "Enter the char array : ";
	// cin >> chars;


}