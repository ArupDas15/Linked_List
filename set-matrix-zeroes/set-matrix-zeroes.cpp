class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <int> row_list, col_list;
        for (int j=0;j<matrix[0].size();j++){
              long double col_prod = 1;
              for(int i=0;i<matrix.size();i++){
                  col_prod=col_prod*matrix[i][j];
                  if(col_prod==0){
                      col_list.push_back(j);
                      break;
                  }
              }
        }
        for (int i=0;i<matrix.size();i++){
            long double row_prod=1;
            for(int j=0;j<matrix[0].size();j++){
                row_prod=row_prod*matrix[i][j];
                if(row_prod==0){
                    row_list.push_back(i);
                    break;
                }
            }
        }
        for (int indices=0;indices<row_list.size();indices++){
            for(int i=0;i<matrix[0].size();i++){
                matrix[row_list[indices]][i]=0;
            }
        }
        for (int indices=0;indices<col_list.size();indices++){
            for(int i=0;i<matrix.size();i++){
                matrix[i][col_list[indices]]=0;
            }
        }
    }
};