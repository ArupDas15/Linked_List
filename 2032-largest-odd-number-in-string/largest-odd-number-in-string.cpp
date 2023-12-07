class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    // Intuition: What this question is asking for is the longest 
    // substring starting from index 0 that ends in an odd number.
    string largestOddNumber(string num) {
      for(int i = num.length() - 1; i >= 0; i--) {
          // NOTE: the ASCII values for characters with even values are
          // themselves even, and odd for characters that represent odd 
          // digits. So no need to do (num[i] - '0') % 2 != 0 to determine
          // if the ith digit in num is an odd digit.
          if((num[i]) % 2 != 0) {
            return num.substr(0, i + 1);
          }
      }
      return ""; 
    }
};
