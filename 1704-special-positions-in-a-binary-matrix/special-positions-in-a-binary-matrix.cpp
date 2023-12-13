class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rsum;
        vector<int> csum;
        int sum = 0;
        int cnt = 0;

        for(int i = 0; i < mat.size(); i++) {
            sum = 0;
            for(int j = 0; j < mat[0].size(); j++) {
                sum = sum + mat[i][j];
            }
            rsum.push_back(sum);
        }
        for(int j = 0; j < mat[0].size(); j++) {
            sum = 0;
            for(int i = 0; i < mat.size(); i++) {
                sum = sum + mat[i][j];
            }
            csum.push_back(sum);
        }
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if( mat[i][j] == 1 && (rsum[i] == 1 && csum[j] == 1)) 
                    cnt++;
            }
        }
        return cnt;
    }
};