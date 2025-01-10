class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            int found_idx = words[i].find(pref);
            if ( found_idx != string::npos and found_idx == 0) ans++;
        }
        return ans;
    }
};