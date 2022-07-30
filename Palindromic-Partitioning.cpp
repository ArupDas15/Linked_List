/*
Palindromic Partitioning - Hard - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500

Reference: https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35
*/

// Solution based on recursion and Matrix Chain Multiplication.

/* This solution will give TLE.
class Solution{
public:
    int isPalindrome(string S, int i, int j ){
        int k = i;
        int n = j - i + 1;
        while(k < i + (n/2)){
            if(S[k] == S[j]){
                j--;
                k++;
            }
            else 
                return 0;
        }
        return 1;
    }
    int solve(string s, int i, int j){
        if(i >= j || isPalindrome(s, i, j))
            return 0;
        int ans = INT_MAX;
        int temp_ans;
        for(int k = i; k <= j - 1; k++){
            temp_ans = 1 + solve(s,i,k) + solve(s,k+1,j);
            ans = min(ans, temp_ans);
        }
        return ans;
    }
    int palindromicPartition(string str)
    {
        return solve(str, 0, str.length()-1);
    }
};
*/
// Not optimised memoised solution.
/*
static int t[501][501];
class Solution{
public:
    int isPalindrome(string &S, int i, int j ){
        int k = i;
        int n = j - i + 1;
        while(k < i + (n/2)){
            if(S[k] == S[j]){
                j--;
                k++;
            }
            else 
                return 0;
        }
        return 1;
    }
    int solve(string &s, int i, int j){
        if(i >= j || isPalindrome(s, i, j))
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        int ans = INT_MAX;
        int temp_ans;
        for(int k = i; k <= j - 1; k++){
            temp_ans = 1 + solve(s,i,k) + solve(s,k+1,j);
            ans = min(ans, temp_ans);
        }
        return t[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        for(int i = 0; i<str.length()+1;i++)
            for(int j = 0; j<str.length()+1;j++)
                t[i][j]=-1;
        return solve(str, 0, str.length()-1);
    }
};
*/
//Optimised Memoised Code which got accepted in InterviewBit.
static int t[501][501];
class Solution{
public:
    int isPalindrome(string &S, int i, int j ){
        int k = i;
        int n = j - i + 1;
        while(k < i + (n/2)){
            if(S[k] == S[j]){
                j--;
                k++;
            }
            else 
                return 0;
        }
        return 1;
    }
    int solve(string &s, int i, int j){
        if(i >= j || isPalindrome(s, i, j))
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        int ans = INT_MAX;
        int left, right, temp_ans;
        for(int k = i; k <= j - 1; k++){
            if(t[i][k] != -1)
                left = t[i][k];
            else{
                left = solve(s,i,k);
                t[i][k] = left;
            }
            if(t[k + 1][j] != -1)
                right = t[k + 1][j];
            else{
                right = solve(s,k + 1, j);
                t[k + 1][j] = right;
            }
            temp_ans = 1 + left + right;
            ans = min(ans, temp_ans);
        }
        return t[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        for(int i = 0; i<str.length()+1;i++)
            for(int j = 0; j<str.length()+1;j++)
                t[i][j]=-1;
        return solve(str, 0, str.length()-1);
    }
}; 