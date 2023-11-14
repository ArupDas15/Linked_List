class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int countPalindromicSubsequence(string s) {
        set<pair<char,char>> res;
        unordered_set<char> left;
        unordered_map<char,int> right;

        for(int i = 0; i < s.length(); i++) {
            right[s[i]] += 1;
        }
        for(int i = 0; i < s.length(); i++) {
            right[s[i]] -= 1;
            if(right[s[i]] == 0) {
                right.erase(s[i]);
            }
            for(int j = 0; j < 26; j++) {
                char c = 'a' + j;
                if((left.find(c) != left.end()) and (right.find(c) != right.end())) {
                    res.insert({s[i],c});
                }
            }
            left.insert(s[i]);
        }
        return res.size();
    }
};
