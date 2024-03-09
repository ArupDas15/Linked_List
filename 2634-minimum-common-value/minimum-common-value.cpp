class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() + nums2.size() > min(nums1.size(), nums2.size())*log (max(nums1.size(), nums2.size()))) {
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
        else {
            int i = 0;
            int j = 0;
            while(i < nums1.size() && j < nums2.size()) {
                if(nums1[i] == nums2[j]) return nums1[i];
                else if(nums1[i] < nums2[j]) i++;
                else j++;
            }
            return -1;
        }

        
    }
};