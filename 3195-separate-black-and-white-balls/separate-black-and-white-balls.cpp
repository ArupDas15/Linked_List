class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int first = 0;
        int second = s.length() - 1;

        while(first < second) {
            if(s[first] == '1') {
                while(s[second] == '1' and first < second) {
                    second--;
                }
                if(s[second] == '0') {
                    ans += (second - first);
                    second--;
                }
            }
            first++;
        }
        return ans;
    }
};