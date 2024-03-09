class Solution {
public:
    int two_ptr_srch(vector<int>& nums1, vector<int>& nums2) {
        int j = 0;
        for(int i = 0; i < nums1.size() && j < nums2.size();) {
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       if(nums1.size() < nums2.size()) {
         return two_ptr_srch(nums1, nums2);
       } 
       return two_ptr_srch(nums2, nums1);
    }
};