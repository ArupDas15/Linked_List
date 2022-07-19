/*
Subset Sum Problem - Medium - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
 
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 10^5
*/

/* Solution using top down memoization approach
*/
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n= arr.size();
        vector<vector<bool>> t( n+1 , vector<bool> (sum+1)); 
        for(int i = 0; i < sum+1; i++)
            t[0][i] = false;
        for(int i = 0; i < n+1; i++)
            t[i][0]=true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};