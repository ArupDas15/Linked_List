class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1)
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;

        for(int i = 0; i < s.length(); i++) {
            for(int j = s.length() - 1; j > i; j--) {
                if(s[i] == s[j]) {
                    ans = max(ans, j - i - 1);
                    break;
                }
            }
        }
        return ans;
    }
};