class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k;
        bool is_feasible=false;
        for (int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                k=i-1;
                is_feasible = true;
                break;
            }
        }
        if(is_feasible){
            int index = k+1;
            for(int i=k+1;i<nums.size();i++){
                if(nums[i]>nums[k]&&nums[i]<nums[index]){
                    // update index
                    index = i;
                }
            }
            int temp=nums[index];
            nums[index]=nums[k];
            nums[k]=temp;
            sort(nums.begin()+k+1,nums.end());
        }
        else{
            reverse(nums.begin(),nums.end());
        }
        
    }
};