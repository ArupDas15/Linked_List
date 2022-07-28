/*
Longest Palindromic Subsequence - Medium - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

Given a String, find the longest palindromic subsequence.


Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.


Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).


Constraints:
1 ≤ |S| ≤ 1000

Reference: https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26

*/
class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        // Passing reverse iterators to the constructor returns us a reversed string. 
        // https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
        string B = string(A.rbegin(), A.rend());
        int t[n+1][n+1];
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n+1; j++){
                if(i==0||j==0)
                    t[i][j]=0;
                else{
                    if(A[i-1]==B[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                    }
                    else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
                }
            }
        }
        return t[n][n];
    }
};
