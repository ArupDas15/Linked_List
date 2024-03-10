class Solution {
public:
    // Time complexity: O(strs[0].length())
    // Space complexity: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size() - 1;
        int n1 = strs[0].length();
        int n2 = strs[n].length();
        
        sort(strs.begin(), strs.end());
        for(int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
            if(strs[0][i] == strs[n][j]) ans.push_back(strs[0][i]);
            else break;
        }
        return ans;
    }
};