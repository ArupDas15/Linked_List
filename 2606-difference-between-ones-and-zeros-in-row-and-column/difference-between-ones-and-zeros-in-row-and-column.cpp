class Solution {
public:
    // Time complexity: O(m * n)
    // Space complexity: O(m + n)
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int cnt1;
        int cnt0;
        vector<int> onesRow;
        vector<int> onesCol;
        vector<int> zeroRow;
        vector<int> zeroCol;
        vector<vector<int>> diff (grid.size(), vector<int>(grid[0].size()));

        for(int i = 0; i < grid.size(); i++) {
            cnt1 = 0;
            cnt0 = 0;
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) cnt0++;
                else cnt1++;
            }
            onesRow.push_back(cnt1);
            zeroRow.push_back(cnt0);
        }
        for(int j = 0; j < grid[0].size(); j++) {
            cnt1 = 0;
            cnt0 = 0;
            for(int i = 0; i < grid.size(); i++) {
                if(grid[i][j] == 0) cnt0++;
                else cnt1++;
            }
            onesCol.push_back(cnt1);
            zeroCol.push_back(cnt0);
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                diff[i][j] = onesRow[i] + onesCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        return diff;
    }
};
