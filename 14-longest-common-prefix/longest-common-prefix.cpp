class Solution {
public:
    // Time complexity: O(strs[0].length())
    // Space complexity: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size() - 1;
        int n1 = strs[0].length();
        
        sort(strs.begin(), strs.end());
        for(int i = 0; i < n1; i++) {
            if(strs[0][i] == strs[n][i]) ans.push_back(strs[0][i]);
            else break;
        }
        return ans;
    }
};