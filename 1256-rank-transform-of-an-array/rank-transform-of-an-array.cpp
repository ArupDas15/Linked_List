class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy_arr = arr;
        std::unordered_map<int, int> ump;
        vector<int> ans;

        sort(copy_arr.begin(),copy_arr.end());
        for(int i = 0, rank = 1; i < copy_arr.size(); i++) {
            if (i > 0 && (copy_arr[i] > copy_arr[i - 1])) {
                rank++; 
            }
            ump[copy_arr[i]] = rank;
        }
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back(ump[arr[i]]);
        }
        return ans;
    }
};