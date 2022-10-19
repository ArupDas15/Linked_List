// Reference: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9 (For DP Approach)
// For accepted Solution: https://www.youtube.com/watch?v=t_f0nwwdg5o
// Problem link: https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

/* Recursive solution

#include <bits/stdc++.h>
int f(int i, int j){
    if(i == 0 && j == 0){
        return 1;
    }
    if(i < 0 || j < 0){
        return 0;
    }
    int up = f(i - 1, j);
    int left = f(i, j - 1);
    return up +  left;
}
int uniquePaths(int m, int n) {
	return f(m - 1, n - 1);
}
*/

// Accepted Solution
#include <bits/stdc++.h>
// Time Complexity: O(n-1) or O(m-1), Space Complexity: O(1)
int uniquePaths(int m, int n) {
	int N = m + n -2;
    int r = m - 1;
    double res = 1;
    for(int i = 1; i <= r; i++)
        res = res * (N - r + i)/ i;
    return (int)res;
}
