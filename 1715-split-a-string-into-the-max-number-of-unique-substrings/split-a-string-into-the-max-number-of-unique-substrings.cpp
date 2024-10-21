
class Solution {
public:
    int maxUniqueSplit(std::string s) {
        std::unordered_set<std::string> cur_set;
        return dfs(0, cur_set, s);
    }

private:
    int dfs(int i, std::unordered_set<std::string>& cur_set, const std::string& s) {
        if (i == s.length()) {
            return 0;
        }
        
        int res = 0;

        for (int j = i; j < s.length(); ++j) {
            std::string substr = s.substr(i, j - i + 1);
            if (cur_set.count(substr) > 0) {
                continue;
            }
            cur_set.insert(substr);
            res = std::max(res, 1 + dfs(j + 1, cur_set, s));
            cur_set.erase(substr);
        }

        return res;
    }
};
