class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(n) 
    int reverseDigits(int num) 
    { 
        int rev_num = 0; 
        while (num > 0) { 
            rev_num = rev_num * 10 + num % 10; 
            num = num / 10; 
        } 
        return rev_num; 
    }    
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        int MOD = 1e9 + 7;
        vector<int> arr;
        unordered_map<int, int> dic;
        
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i]-reverseDigits(nums[i]));
        }
        for(int num : arr) {
            ans = (ans + dic[num]) % MOD;
            dic[num]++;
        }
        return ans;
    }
};