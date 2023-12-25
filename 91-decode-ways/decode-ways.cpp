#include <unordered_map>
#include <string>

class Solution {
private:
    int dfs(int i, const std::string& s, std::unordered_map<int, int>& dp) {
        if (dp.find(i) != dp.end()) {
            return dp[i];
        }

        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(i + 1, s, dp);
        if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
            res += dfs(i + 2, s, dp);
        }

        dp[i] = res;
        return res;
    }
    
public:
    int numDecodings(std::string s) {
        std::unordered_map<int, int> dp;
        dp[s.length()] = 1;

        return dfs(0, s, dp);
    }
};
