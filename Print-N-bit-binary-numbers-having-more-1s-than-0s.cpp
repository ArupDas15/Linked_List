/* https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

Print N-bit binary numbers having more 1s than 0s

Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
Example 2:

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	void solve(int N, int ones, int zeroes, string op, vector<string>& ans){
        if(N == 0){
            ans.push_back(op);
            return;
        }
        string op1 = op;
        op1.push_back('1');
        solve(N-1,ones+1, zeroes, op1, ans);
        if(zeroes < ones){
            string op2 = op;
            op2.push_back('0');
            solve(N-1,ones, zeroes+1, op2, ans);
        }
    }
	vector<string> NBitBinary(int N)
	{
	    vector<string> ans;
	    string op = "1";
	    solve(N-1, 1, 0, op, ans);
	    return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Solution ob;
		vector<string> ans = on.NBitBinary(n);
	
		for(auto i:ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}