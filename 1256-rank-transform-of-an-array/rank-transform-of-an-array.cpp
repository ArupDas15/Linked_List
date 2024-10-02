class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy_arr = arr;
        std::unordered_map<int, int> ump;
        vector<int> ans;

        if (arr.size() == 0) return ans;
        sort(copy_arr.begin(),copy_arr.end());
        ump[copy_arr[0]] = 1;
        for(int i = 1, rank = 2; i < copy_arr.size(); i++) {
            if (copy_arr[i] > copy_arr[i - 1]) {
                ump[copy_arr[i]] = rank;
                rank++; 
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back(ump[arr[i]]);
        }
        return ans;
    }
};