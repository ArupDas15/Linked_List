class Solution {
public:
    // Time complexity: O(m*n)
    // Space complexity: O(m*n) 
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));
	    int i_idx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	    int j_idx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	
	    for(int i = 0; i < img.size(); i++) {
	        for(int j = 0; j < img[0].size(); j++) {
		        int cnt = 0;
		        int sum = 0;
		        for(int k = 0; k < 9; k++) {
		            int ith_idx = i + i_idx[k];
		            int jth_idx = j + j_idx[k];
		            if(ith_idx >= 0 && ith_idx < img.size() && 
                       jth_idx >= 0 && jth_idx < img[0].size()) {
			            cnt++;
			            sum = sum + img[ith_idx][jth_idx];
		            }
		        }
		        ans[i][j] = floor(sum / cnt);
	        }
	    }
	    return ans;
    }
};