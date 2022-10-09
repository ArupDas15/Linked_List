// Reference: https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4
// Problem - Frog Jump upto 2 steps - EASY - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//Memoization solution
/*
Time complexity: O(n), Space complexity: O(n) for recursion + O(n) for dp table
#include <bits/stdc++.h>
int f(int n, vector<int>& heights, vector<int>& dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int left = f(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1)
        right = f(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    dp[0]=0;
    return f(n-1,heights,dp);
}
*/
// Time complexity: O(n), Space complexity: O(1)
#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
    int prev=0,prev2=0,curi;
    for(int i=1;i<n;i++){
         int fs=prev+abs(heights[i]-heights[i-1]);
         int ss=INT_MAX;
         if(i>1)
             ss=prev2+abs(heights[i]-heights[i-2]);
        curi=min(fs,ss);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
