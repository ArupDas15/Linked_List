class Solution {
public:
    int minSwaps(string s) {
        if (s.length() == 0 or 
            (s.find('[') == -1 && s.find(']') == -1)) {
                return 0;
        } 
        int open = 0, close = 0;
        for(char ch:s) {
            if (ch == '[') {
                open++;
            } else if (ch == ']') {
                if(open > 0) {
                    // Match found, balance them
                    open--;
                } else {
                    // Unbalanced paranthesis detected
                    close++;
                }
            }
        }
        return (close+1)/2;
    }
};