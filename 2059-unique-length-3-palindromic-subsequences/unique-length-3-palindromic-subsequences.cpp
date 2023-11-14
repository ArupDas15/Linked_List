class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> left;
        unordered_map<char,int> right;
        set<pair<char,char>> res;

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