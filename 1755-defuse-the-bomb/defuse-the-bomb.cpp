class Solution {
public:
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