class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> unique_nums_set(nums.begin(), nums.end());
        vector<long long int>unique_nums_vec;
        for (int num : unique_nums_set) {
            unique_nums_vec.push_back(num);
        }
        long long int thrice_sum = 3*accumulate(unique_nums_vec.begin(), unique_nums_vec.end(), 0LL);
        long long int arr_sum = accumulate(nums.begin(), nums.end(), 0LL);
        return (int)((thrice_sum - arr_sum)/2);
    }
};