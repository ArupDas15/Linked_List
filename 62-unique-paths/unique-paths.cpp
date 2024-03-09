class Solution {
public:
    // Intuition: You will move n-1 stepa in the right, m-1 steps downwards
    // to reach m-1, n-1. So, total steps taken is (m-1) + (n-1) = m+n-2
    // Out of m+n-2 steps, if we choose m-1 downwars steps remaining steps
    // will be in rightward direction and vice-versa.

    // Time complexity: min(O(m-1), O(n-1))
    // Space Complexity: O(1)
    int comb(int n, int m) {
        double numerator = 1, denominator = 1;

        for(int i = 1; i <= m; i++) {
            numerator = numerator * n;
            denominator = denominator * i;
            n = n - 1;
        }
        return (int) (numerator/denominator);
    }
    int uniquePaths(int m, int n) {

        return comb(m + n - 2, min(m-1, n-1));
    }
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
    // int countPaths(int m, int n, int i, int j, vector<vector<int>>& dp) {
    //     if(i >= m || j >= n) return 0;
    //     else if(i == m - 1 && j == n - 1) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = countPaths(m, n, i + 1, j, dp) + countPaths(m, n, i, j + 1, dp);
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return countPaths(m, n, 0, 0, dp);
    // }
};