class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.length() == 0 or 
            (s.find('(') == -1 && s.find(')') == -1)) {
                return 0;
        } 
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