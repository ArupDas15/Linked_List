class Solution {
public:
    // Intuition: There can be atmost 2 elements that appear more than ⌊ n/3 ⌋ times.
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int mini = floor(n/3);
        vector<int> ans;
        int el1 = INT_MIN, el2 = INT_MIN;

        for(int x : nums) {
            if(cnt1 == 0 && el2 != x) {
                cnt1 = 1;
                el1 = x;
            } else if(cnt2 == 0 && el1 != x) {
                cnt2 = 1;
                el2 = x;
            } else if(el1 == x) cnt1++;
            else if(el2 == x) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int x : nums) {
            if(el1 == x) cnt1++;
            else if(el2 == x) cnt2++;
        }
        if(cnt1 > mini) ans.push_back(el1);
        if(cnt2 > mini) ans.push_back(el2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};