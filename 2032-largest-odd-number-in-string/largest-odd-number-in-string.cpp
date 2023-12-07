class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1) 
    string largestOddNumber(string num) {
        int largest_odd_pos = -1;

        for(int i = num.length() - 1; i >= 0; i--) {
            if((num[i]-'0') % 2 != 0) {
                largest_odd_pos = i;
                break;
            }
        }
        return largest_odd_pos == -1 ? "" : num.substr(0, largest_odd_pos + 1); 
    }
};