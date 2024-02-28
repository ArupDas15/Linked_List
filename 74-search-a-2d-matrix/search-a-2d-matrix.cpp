class Solution {
public:
    bool binary_search(vector<vector<int>>& matrix, int target) {
        int low = 0; 
        int high = matrix.size()*matrix[0].size() - 1;
        
        while(low <= high) {
            int mid = low+((high - low)/2);
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            if(matrix[row][col] == target)return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0;i < m; i++) {
            if((matrix[i][0] <= target) && (matrix[i][n - 1] >= target)) {
                return binary_search(matrix, target);
            }
        }
        return false;
    }
};