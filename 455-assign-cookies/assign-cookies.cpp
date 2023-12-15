class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int j = g.size() - 1;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = s.size() - 1; i >= 0 && j >= 0; ) {
            if(s[i] >= g[j]) {
                ans++;
                i--;
            }
            j--;
        }
        return ans;
    }
};