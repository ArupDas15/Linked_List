class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int el = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(el != nums[i]) {
                cnt--;
            } else {
                cnt++;
            }
            if(cnt == 0) {
                if(i+1<nums.size()) {
                    cnt = 0;
                    el = nums[i+1];
                }
            }
        }
        return el;
    }
};