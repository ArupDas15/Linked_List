class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
       int r[9][9], c[9][9], s[3][3][9];
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(s, 0, sizeof(s));
        int current_val;
        int number;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j]=='.'){
                    current_val = 0;
                }
                else current_val = mat[i][j]-'0';
                if (current_val > 0 && current_val <= 9) {
                    number = current_val - 1;
                    if (r[i][number]) 
                        return false;
                    r[i][number] = 1;
                    if (c[j][number]) 
                        return false;
                    c[j][number] = 1;
                    // checking if same box have repeated value except for 0
                    if (s[i / 3][j / 3][number]) 
                        return false;
                    s[i / 3][j / 3][number] = 1;
                }
            }
        }
        return true;
    }
};