class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool is_Col = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i=0;i<rows;i++){
            if(matrix[i][0]==0){
                    is_Col = true;
                }
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(!matrix[i][0]||!matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<cols;j++){
                matrix[0][j]=0;
            }
        }
        if(is_Col){
                for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
        
        }
};