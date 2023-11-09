class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Intuition: For a character at index 'i', the total number of ways a string
    // can end at that index is (i + 1). We are accounting for 1 by initialising
    // ans with s.size(). 
    int countHomogenous(string s) {
        int MOD = 1000000007;
        int ans = (int) s.size();
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                ans = (ans + cnt) % MOD;
                cnt++;
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};
