class Solution {
public:
    // Time Complexity: O(N log N) + O(N)
    // Space Complexity: O(N) -> incase all the intervals 
    // are unique so the intervals will not overlap and we 
    // will have to store all the 'n' intervals.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++) {
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};