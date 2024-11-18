class Solution {
public:
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    // Observe in this question the contraints are below 500 that is they are really very small.
    // so that gives an indication that the Brute-Force solution should work on this problem.
    // The only tricky part here is when k < 0.
    // (i - cnt + n) % n where cnt is say absolute value of k (when k < 0). thus i -cnt is negative
    // (i.e. you are moving pasth the begining of the array), adding n ensure a non-negative index 
    // and the module operation wraps the index correctly for the circular array.
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n  = code.size();

        if (k == 0) {
            return vector<int>(n, 0);
        } else if (k > 0) {
            for(int i = 0; i < n; i++) {
                int cnt = k;
                int sum = 0;

                while (cnt > 0) {
                    sum += code[(i + cnt) % n];
                    cnt--;
                }
                ans.push_back(sum);
            }
        } else {
            for(int i = 0; i < n; i++) {
                int cnt = k;
                int sum = 0;
                int j = 0;

                while (cnt < 0) {
                    sum += code[(i + cnt + n) % n];
                    cnt++;
                    j++;
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};