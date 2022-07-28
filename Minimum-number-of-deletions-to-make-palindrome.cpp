/*
Minimum number of deletions. - Easy - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.

Note: The order of characters should be maintained.

Example 1:

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".
â€‹Example 2:

Input: n = 3, str = "aba"
Output: 0
Explanation: We don't remove any
character.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minDeletions() which takes the string s and length of s as inputs and returns the answer.

Expected Time Complexity: O(|str|^2)
Expected Auxiliary Space: O(|str|^2)

Constraints:
1 ≤ |str| ≤ 10^3

Reference: https://www.youtube.com/watch?v=CFwCCNbRuLY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=27

*/

int minDeletions(string str, int n) { 
    int t[n+1][n+1];
    string B = string(str.rbegin(),str.rend());
    for(int i = 0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
            else{
                if(str[i-1]==B[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return str.length()-t[n][n];
} 