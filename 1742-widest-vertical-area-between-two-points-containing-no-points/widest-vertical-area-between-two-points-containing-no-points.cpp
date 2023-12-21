class Solution {
public:
    // Time Complexity: O(nlogn)
    // Space complexity: O(log n)
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = INT_MIN;

        sort(points.begin(), points.end());
        for(int i = 0; i < points.size() - 1; i++) {
            ans = max(points[i + 1][0] - points[i][0], ans);
        }
        return ans;
    }
};