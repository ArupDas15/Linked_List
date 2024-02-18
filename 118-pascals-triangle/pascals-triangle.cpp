class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int rowcnt = 0;
        vector<vector<int>> p_vec;
        
        while(rowcnt < numRows) {
            vector<int> row_vec;
            if(rowcnt == 0) {
                row_vec.push_back(1);
            } else if(rowcnt == 1){
                row_vec.push_back(1);
                row_vec.push_back(1);
            } else {
                int prev_row_idx = p_vec.size()-1;
                int prev_row_size = p_vec.size();
                row_vec.push_back(1);
                for(int i = 0; i < prev_row_size - 1; i++) {
                    int ele = p_vec[prev_row_idx][i] + p_vec[prev_row_idx][i + 1];
                    row_vec.push_back(ele);
                }
                row_vec.push_back(1);
            }
            p_vec.push_back(row_vec);
            rowcnt++;
        }
        return p_vec;
    }
};