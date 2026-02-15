#define CHAR_TO_INT(c) ((c)-'0')
class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0, carry = 0;
        string ans;
        int i = a.length()-1;
        int j = b.length()-1;
        
        while(i>=0||j>=0) {
            if(i>=0) sum += CHAR_TO_INT(a[i--]);
            if(j>=0) sum += CHAR_TO_INT(b[j--]);
            sum += carry;
            ans.push_back((sum % 2) + '0');
            carry = sum/2;
            sum = 0;
        }
        if (carry == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};