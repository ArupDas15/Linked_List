class Solution {
private:
    int getres(string s, string t) {
        int cnt = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i])
                cnt++;
        }
        return cnt;
    }
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int minOperations(string s) {
        int flg1 = 0;
        int flg2 = 1;
        string temp1 = "";
        string temp2 = "";

        for(int i = 0; i < s.length(); i++) {
            temp1.push_back('0' + flg1);
            temp2.push_back('0' + flg2);
            flg1 = flg1 ^ 1;
            flg2 = flg2 ^ 1;
        }
        return min(getres(s, temp1), getres(s, temp2));;
    }
};