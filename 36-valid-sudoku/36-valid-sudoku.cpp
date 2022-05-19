class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
       unordered_set<string> seen;
        string key;
        string current_val;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9 ; j++){
                current_val = to_string(mat[i][j]);
                if(current_val!="46"){
                    key = current_val+ std::string(" found in row ")+to_string(i);
                    if(seen.find(key) == seen.end()){
                        seen.insert(key);
                    }
                    else 
                        return false;
                    key = current_val+ std::string(" found in column ")+to_string(j);
                    if(seen.find(key) == seen.end()){
                        seen.insert(key);
                    }
                    else 
                        return false;
                    key = current_val+ std::string(" found in box ")+to_string(i/3)+to_string(j/3);
                    if(seen.find(key) == seen.end()){
                        seen.insert(key);
                    }
                    else 
                        return false;
                }
            }
        } 
        return true;
    
    }
};