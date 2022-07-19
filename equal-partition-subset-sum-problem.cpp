/*

Partition Equal Subset Sum- Medium- https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

*/

class Solution{
public:
    int subsetSum(int arr[],int n, int sum){
        int t[n+1][sum+1];
        for(int i=0;i<sum+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j)
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        if(sum%2!=0)// If sum is an odd number then we cannot partition the array intp equal sum partition.
            return 0;
        else return subsetSum(arr,N,sum/2);
    }
};
