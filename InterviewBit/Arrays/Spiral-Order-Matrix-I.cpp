/*  Spiral Order Matrix I - EASY - https://www.interviewbit.com/problems/spiral-order-matrix-i/
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
Problem Approach :

VIDEO : https://www.youtube.com/watch?v=siKFOI8PNKM
*/
// Time Complexity: O(m*n), Space Complexity: O(1)
vector<int> Solution::spiralOrder(const vector<vector<int> > &matrix) {
    int top = 0, right = matrix[0].size()-1, bottom = matrix.size()-1, left = 0;
        vector<int> res;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top ++;
            for(int i = top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);                
                }
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);                
                }
                left++;
            }
            
        }
        return res;
}
