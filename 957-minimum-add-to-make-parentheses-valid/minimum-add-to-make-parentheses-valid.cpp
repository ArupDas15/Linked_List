class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (char ch : s) {
            if (ch == '(') {
                open++; // Count unmatched opening brackets
            } else if (ch == ')') {
                if (open > 0) {
                    open--; // Match found, reduce unmatched openings
                } else {
                    close++; // Unmatched closing bracket
                }
            }
        }
        return open+close;
    }
};