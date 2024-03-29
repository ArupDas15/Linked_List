/*
Max Rectangle In Binary Matrix - MEDIUM - https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
*/
int Solution::maximalRectangle(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    if (cols == 0) return 0;
    vector<vector<int>> max_x(rows, vector<int>(cols, 0));
    int area = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (j == 0)
                    max_x[i][j] = 1;
                else
                    max_x[i][j] = max_x[i][j - 1] + 1;
                int y = 1;
                int x = cols;
                while ((i - y + 1 >= 0) && (matrix[i - y + 1][j] == 1)) {
                    x = min(x, max_x[i - y + 1][j]);
                    area = max(area, x * y);
                    y++;
                }
            }
        }
    }
    return area;
}
