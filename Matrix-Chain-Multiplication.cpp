/*
Matrix Chain Multiplication - HARD - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.

Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N^3)
Expected Auxiliary Space: O(N^2)

Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500

*/
// Solution using purely recursive approach - This solution will give TLE.

/*
class Solution{
public:
    int solve(int arr[],int i, int j){
        if(i>=j)
            return 0;
        int mn = INT_MAX;
        int temp_ans;
        for(int k = i; k <= j - 1; k++){
            temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            mn = min(temp_ans, mn);
        }
        return mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr,1,N-1);
    }
};
*/
// Using Bottom Up DP
class Solution{
public:
    int t [101][101];
    int solve(int arr[],int i, int j){
        if(i>=j)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        int mn = INT_MAX;
        int temp_ans;
        for(int k = i; k <= j - 1; k++){
            temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            mn = min(temp_ans, mn);
        }
        return t[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        
        for(int i = 0; i < N + 1; i++)
            for(int j = 0; j < N + 1; j++)
                t[i][j] = -1;
        return solve(arr,1,N-1);
    }
};