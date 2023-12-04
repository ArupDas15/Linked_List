class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1)
    string largestGoodInteger(string num) {
        string ans = "";
        int max_int = -1;
        int count = 1;
        char prev = num[0];

        for(int i = 1; i < num.length(); i++) {
            if(prev == num[i]) count++;
            else {
                prev = num[i];
                count = 1;
            }
            if(count == 3 and prev > max_int) {
                ans = "";
                ans.push_back(char(prev));
                ans.push_back(char(prev));
                ans.push_back(char(prev));
                max_int = prev;
            }
        }
        return ans;
    }
};