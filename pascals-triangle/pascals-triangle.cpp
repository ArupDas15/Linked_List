class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> matrix;
        matrix.push_back(vector<int>());
        matrix[0].push_back(1);
        if(numRows==1)
            return matrix;
        matrix.push_back(vector<int>());
        matrix[1].push_back(1);
        matrix[1].push_back(1);
        if (numRows==2){
            return matrix;
        }
        else {
            for(int i = 2; i < numRows; i++){
                int last_index=matrix[i-1].size()-1;
                matrix.push_back(vector<int>());
                matrix[i].push_back(1);
                int prev_row_index=0;
                for(int j=1;j<matrix[i-1].size()+1;j++){
                    if(prev_row_index<last_index){
                        matrix[i].push_back(matrix[i-1][prev_row_index]+matrix[i-1][prev_row_index+1]); 
                        prev_row_index += 1;
                    }
                    else{
                        matrix[i].push_back(1);
                        break;
                    }
                }
                
            }
            return matrix;
        }
    }
};