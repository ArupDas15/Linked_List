class Solution {
public:
    vector<vector<int>> memo;
    std::vector<std::vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
    };
    const int MOD = 1e9 + 7;
    
    int dp(int remain, int square) {
        if(remain == 0) return 1;
        if(memo[remain][square] != 0) return memo[remain][square];
        int ans = 0;
        for(int nextsquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextsquare)) % MOD;
        }
        memo[remain][square] = ans;
        return ans;
    }
    // Time complexity: O(n)
    // Space complexity: O(n)
    int knightDialer(int n) {
        memo = vector(n + 1, vector(10, 0));
        int ans = 0;
        for(int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
        }
        return ans;
    }
};