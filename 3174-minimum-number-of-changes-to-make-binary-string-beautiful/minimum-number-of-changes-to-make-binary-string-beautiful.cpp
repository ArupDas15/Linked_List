class Solution {
public:
    // Time Complexity: O(n/2) ~ O(n)
    // Space Complexity: O(1)
    int minChanges(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i+=2) {
            if (s[i] != s[i+1]) {
                count++;
            }
        }
        return count;
    }
};