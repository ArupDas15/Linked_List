/*
 Minimum number of deletions and insertions. - Easy - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.
Example 2:

Input : str1 = "geeksforgeeks"
str2 = "geeks"
Output: 8
Explanation: 8 deletions
 

Your Task:
You don't need to read or print anything. Your task is to complete the function minOperations() which takes both strings as input parameter and returns the minimum number of operation required.

Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lower case English alphabets

Reference: https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25
*/

class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int m = str1.length();
	    int n = str2.length();
	    int t[m+1][n+1];
	    for(int i = 0; i < m+1; i++){
	        for(int j = 0; j < n+1; j++){
	            if(i==0 || j==0)
	                t[i][j] = 0;
	            else{
	                if(str1[i-1] == str2[j-1]){
	                    t[i][j] = 1 + t[i-1][j-1];
	                }
	                else
	                t[i][j] = max(t[i][j-1],t[i-1][j]);
	            }
	        }
	    }
	    return (m + n - (2*t[m][n])); // ((m - t[m][n]) + (n - t[m][n]))
	    
	} 
};