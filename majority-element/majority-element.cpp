class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, chk =0 , major, mj;
        if (nums.size()<2){
            return nums[0];
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                chk++;
                mj = nums[i];
                if(count<chk){
                count = chk;
                major=mj;
                }
            }
            else {
                chk = 0;
            }
        }
        return major;
    }
};