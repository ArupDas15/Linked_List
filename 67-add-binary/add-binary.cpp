#define CHAR_TO_INT(c) ((c)-'0')
class Solution {
public:
    string add_zeros(string b, int zero_pad_len) {
        string temp;
        for(int i = 0; i < zero_pad_len; i++) {
            temp.push_back('0');
        }
        temp = temp+b;
        return temp;
    }
    string addBinary(string a, string b) {
       int sum = 0, carry = 0;
       string ans;

       if(a.length() != b.length()) {
            if(a.length()> b.length()) {
                b = add_zeros(b, a.length() - b.length());
            } else {
                a = add_zeros(a, b.length() - a.length());
            }
        }
        for(int i = a.length()-1; i >= 0; i--) {
            sum = CHAR_TO_INT(a[i]) + CHAR_TO_INT(b[i]) + carry;
            char ops_res;
            if (sum == 3) {
                carry = 1;
                ops_res = '1'; 
            } else if( sum == 2) {
                carry = 1;
                ops_res = '0';
            } else if( sum == 1) {
                carry = 0;
                ops_res = '1';
            } else { // sum = 0
                carry = 0;
                ops_res = '0';
            }
            sum = 0;
            ans.push_back(ops_res);            
        }
        if (carry == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};