#include <iostream>
#include <vector>
#include <string>
using namespace std;

					// ** APPROACH - 1 **

string longestCommonPrefix(vector<string> &arr, int n){

	string ans = "";

	// for traversing all characters of first string
	for(int i=0; i<arr[0].length(); i++){
		char ch = arr[0][i];

		bool match = true;

		// for comparing ch with rest of the strings
		for(int j=1; j<n; j++){
			// not match
			if(arr[j].size() < i || ch != arr[j][i]){
				match = false;
				break;
			}
		}
		if(match == false){
			break;
		}
		else{
			ans.push_back(ch);
		}
	}
	return ans;
}

int main(){
	
	vector<string> arr = {"CODING", "CODEZEN", "CODINGNINJA", "CODERS"};
	int n = 4;

	string ans = longestCommonPrefix(arr, n);
	cout << "Longest Common Prefix is  : " << ans << endl;	
}







/*				// *** APPROACH - 2 ***

class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insertUntil(TrieNode* root, const string& word, int index) {
        if (index == word.length()) {
            root->isTerminal = true;
            return;
        }

        int childIndex = word[index] - 'a';
        TrieNode* child;

        if (root->children[childIndex] != NULL) {
            child = root->children[childIndex];
        } else {
            child = new TrieNode();
            root->children[childIndex] = child;
        }

        insertUntil(child, word, index + 1);
    }

    void insertWord(const string& word) {
        insertUntil(root, word, 0);
    }

    string lcp() {
        TrieNode* current = root;
        string prefix = "";

        while (current != NULL) {
            int childCount = 0;
            int index = -1;

            for (int i = 0; i < 26; i++) {
                if (current->children[i] != NULL) {
                    childCount++;
                    index = i;
                }
            }

            if (childCount == 1 && !current->isTerminal) {
                prefix += (char)('a' + index);
                current = current->children[index];
            } else {
                break;
            }
        }

        return prefix;
    }
};

string longestCommonPrefix2(const vector<string>& arr) {
    if (arr.empty()) return "";

    Trie t;
    for (const string& word : arr) {
        t.insertWord(word);
    }

    return t.lcp();
}

int main() {
    vector<string> arr = {"coding", "codezen", "codingninja", "coders"};

    string ans = longestCommonPrefix2(arr);
    cout << "Longest Common Prefix is : " << ans << endl;

    return 0;
}
*/