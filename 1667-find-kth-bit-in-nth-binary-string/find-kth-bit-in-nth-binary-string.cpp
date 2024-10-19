class Solution {
public:
    string invert(string s) {
        string inverted_str = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                inverted_str += '1';
            } else {
                inverted_str += '0';
            }
        }
        return inverted_str;
    }
    char findKthBit(int n, int k) {
        vector<string> s(n,"");
        char kth_bit;
        s[0] = "0";
        for(int i = 1; i < n; i++) {
            string reversed_str = invert(s[i - 1]);
            reverse(reversed_str.begin(), reversed_str.end());
            s[i] = s[i - 1] + "1" + reversed_str;
        }
        for(int i = 0; i < s[n-1].length(); i++){
            if(i == k-1){
                kth_bit = s[n-1][i];
            }
        } 
        return kth_bit;
    }
};