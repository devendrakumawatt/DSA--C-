#include<iostream>
#include<vector>
using namespace std;

		// *** Power set of a set ***

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
    //base case
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }
        
    //exclude
    solve(nums, output, index+1, ans);
        
    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);        
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;  
}

int main(){
	vector<int> nums = { 1, 2, 3 };

	cout << "Array :  " ;
	for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }cout << endl;

    vector<vector<int> > res = subsets(nums);

    cout << "Power set of Array  :  ";
    // Print the generated subsets
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << ", ";
    }

}



/*			// *** SubSequence *** 

void solve(vector<string>& ans, string str, string output, int i) {
    //base case
    if(i>=str.length()) {
        if(output.length()>0)
        ans.push_back(output);
        return ;
        }
    
    //exclude
    solve(ans, str, output, i+1);
    //include
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
	
}

int main(){

	string str = "abc";
	 
	cout << "Main String : -> ";
	for(int i = 0; i < str.size(); i++){
        cout << str[i] << " ";
    }cout << endl;

	vector<string> val = subsequences(str);

	cout << "Subsequences : -> ";
	for(int i = 0; i < val.size(); i++){
        cout << val[i] << ", ";
    }
}
*/