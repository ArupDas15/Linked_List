class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Reference Video: https://www.youtube.com/watch?v=muDPTDrpS28
        int n= nums.size();
        int reachable = 0;
        for(int cur_idx = 0; cur_idx < n; cur_idx++){
            if(reachable < cur_idx){
                return false;
            }
            else{
                // Update the maximum index reachable.
                reachable = max(reachable, cur_idx + nums[cur_idx]);
            
            }
        }
        return true;
    }
};