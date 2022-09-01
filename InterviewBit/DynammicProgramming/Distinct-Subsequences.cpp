/*
Distinct Subsequences - Medium - https://www.interviewbit.com/problems/distinct-subsequences/

Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
*/

int Solution::numDistinct(string S, string T) {
    int rows = T.size(), cols = S.size();

    if(rows > cols){
        return 0;
    }
    
    vector<vector<int> > temp(rows+1, vector<int>(cols+1, 0));
    
    for(int i = 0; i <= cols; i++){
        temp[0][i] = 1;
    }
    
    for(int i = 1; i <= rows; i++){
        for(int j = i; j <= cols; j++){
            if(S[j-1] == T[i-1]){
                temp[i][j] = temp[i-1][j-1] + temp[i][j-1];
            }
            else{
                temp[i][j] = temp[i][j-1];
            }
        }
    }
    
    return temp[rows][cols];
}
