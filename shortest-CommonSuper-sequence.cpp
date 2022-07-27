/*
 Shortest Common Supersequence - Medium - https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.
Your Task:
Complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100

Reference: https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25
*/

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int t[m+1][n+1];
        for(int i = 0; i < m + 1; i++){
            for( int j = 0; j < n + 1; j++){
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else{
                    if(X[i - 1] == Y[j - 1])
                        t[i][j] = 1 + t[i - 1][j - 1];
                    else
                        t[i][j] = max (t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return (m + n - t[m][n]);
    }
};