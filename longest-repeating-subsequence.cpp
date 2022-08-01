/*
Longest Repeating Subsequence - Easy- https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Example 1:

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.

Your Task:
You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.


Expected Time Complexity: O(n^2)
Expected Space Complexity: O(n^2)


Constraints:
1 <= |str| <= 10^3

*/

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n =str.length();
		    int t[n+1][n+1];
		    for(int i = 0;i<n+1;i++){
		        for(int j = 0;j<n+1;j++){
		            if(i==0||j==0)
		                t[i][j]=0;
		            else{
		                if(str[i-1]==str[j-1]&&i!=j)
		                    t[i][j]=1+t[i-1][j-1];
		                else
		                    t[i][j]=max(t[i-1][j],t[i][j-1]);
		            }
		        }
		    }
		    return t[n][n];
		}

};