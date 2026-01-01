class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int add = 0;
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--) {
            add = digits[i] + carry;
            carry = add / 10;
            add = add % 10;
            res.push_back(add);
        }
        if (carry) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};