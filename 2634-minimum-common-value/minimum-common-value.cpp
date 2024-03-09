class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       if(nums1.size() < nums2.size()) {
         for(int x : nums1) {
             if(binary_search(nums2.begin(), nums2.end(), x)) return x;
         }  
       } 
       for(int x : nums2) {
           if(binary_search(nums1.begin(), nums1.end(), x)) return x;
       }
       return -1;
    }
};