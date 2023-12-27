class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int max_time = INT_MIN;

        for(int i = 0; i < colors.length(); i++) {
            bool flg = false;
            int j;

            for(j = i + 1; j < colors.length() && 
                           colors[i] == colors[j]; j++) {
                flg = true;
                ans += neededTime[j];
                max_time = max(max_time, neededTime[j]);
                cout<<colors[j];
            }
            if(flg) {
                ans += neededTime[i] - max(neededTime[i], max_time);
                i = j - 1;
                flg = false;
                max_time = INT_MIN;
            }
        }
        return ans;
    }
};