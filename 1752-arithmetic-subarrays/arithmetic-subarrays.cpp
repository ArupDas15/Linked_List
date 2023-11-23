//--- Without sorting----
class Solution {
public:
    // Time Complexity: O(nm)
    // Space Complexity: O(n)
    bool check(vector<int>& arr) {
        unordered_set<int>s;
        int maxEle = INT_MIN;
        int minEle = INT_MAX;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            maxEle = max(maxEle, arr[i]);
            minEle = min(minEle, arr[i]);
            s.insert(arr[i]);
        }
        if(((maxEle - minEle) % (n - 1)) != 0) return false;
        int diff = ((maxEle - minEle) / (n - 1));
        for(int k = 1; minEle + (k*diff) < maxEle; k++) {
            if(s.find(minEle + (k*diff)) == s.end()) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int m = l.size();

        for(int i = 0; i < m; i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        return ans;
    }
};

//----With sorting-----
// class Solution {
// public:
    // Time complexity: O(m⋅n⋅log⁡n)
    // Space complexity: O(n)
//     bool check(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int diff = nums[1] - nums[0];

//         for(int i = 2; i < nums.size(); i++) {
//             if(nums[i] - nums[i - 1] != diff) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
//         vector<bool> ans;
//         int m = l.size();
        
//         for(int i = 0; i < m; i++) {
//             vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
//             ans.push_back(check(arr));
//         }
//         return ans;
//     }
// };
