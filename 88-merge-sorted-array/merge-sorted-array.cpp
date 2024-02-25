class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i< m + n && j < n; i++, j++) {
            nums1[i] = nums2[j];
        }

        int gap = ceil(floor(m + n) / 2);
        int left = 0;
        int right = left + gap;
        
        for(;gap > 0; gap = ceil(floor(gap) / 2)) {
            left = 0;
            right = left + gap;
            while(right < m + n ) {
                if(nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                left++;
                right++;
            }
            if(gap == 1) {
                    break;
                }
        }
        
    }
};