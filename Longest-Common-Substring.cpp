/*
Longest Common Substring - Medium - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

Given two strings. The task is to find the length of the longest common substring.

Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000

*/

class Solution{
    public:
    
    int longestCommonSubstr (string &S1, string &S2, int n, int m)
    {
        int t[n+1][m+1], mx = 0;
        for(int i =0;i<n+1;i++){
            for(int j =0;j<m+1;j++){
                if(i==0||j==0)
                    t[i][j] = 0;
                else{
                    if(S1[i-1]==S2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                    mx = max(t[i][j],mx); 
                    }    
                    else t[i][j] = 0;
                }
            }
        }
        return mx;
    }
};