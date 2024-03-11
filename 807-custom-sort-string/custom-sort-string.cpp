class Solution {
public:
    string customSortString(string order, string s) {
        string ls = "";
        string ans = "";
        unordered_map<char,int>mp1;

        for(char c : order) {
            mp1[c] = 0;
        }
        for(char c : s) {
            if(mp1.find(c) != mp1.end()) {
                mp1[c]++;
            } else ls.push_back(c);
        }
        for(char c : order) {
            int cnt = 0;
            while(cnt < mp1[c]) {
                ans.push_back(c);
                cnt++;
            }
        }
        ans = ans + ls;
        return ans;
    }
};