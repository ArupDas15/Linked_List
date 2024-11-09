class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        for(int i = 1; i < n ; i++) {
            result = (result + 1)|x;
        }
        
        return result;
    }
};