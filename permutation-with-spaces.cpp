// Permutation with Spaces: https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    void solve(string ip, string op, vector<string>& ans){
        if(ip.length()==0){
            ans.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        // Include the letter with space in the left side of the recursion tree.
        op1.push_back(' ');
        op1.push_back(ip[0]);
        // Include the letter without space in the right side of the recursion tree.
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1,ans);
        solve(ip,op2,ans);
    }

    vector<string> permutation(string S){
        string op;
        vector<string> ans;
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(S,op,ans);
        return ans;
    }
};

int main(){
	int t;
	cin>>tl
	while(t--){
		string S;
		cin>>S;
		vector<string> ans;
		Solution obj;
		ans = obj.permutation(S);
		for(int i=0;i<ans.size();i++){
			cout<<"(">>ans[i]<<")";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}