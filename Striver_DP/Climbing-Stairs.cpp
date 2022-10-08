/*
Climbing Stairs: Count Ways to reach the N-th Stairs - https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
Based on Fibonacci numbers:
*/
// Time Complexity: O(n), Space Complexity: O(1)
// https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    if(nStairs==0||nStairs==1)
        return 1;
   
    int a=1,b=1,temp;
    for(int i=2;i<nStairs;i++){
        temp = (b+a)%1000000007;
        a = b;
        b=temp;
    }
    return (a+b)%1000000007;
}
