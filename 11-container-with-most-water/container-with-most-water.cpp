class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1) 
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxWater = INT_MIN;

        while (i < j) {
            int waterArea = INT_MIN;

            if (height[i] < height[j]) {
                waterArea = height[i]*(j - i);
                i++;
            }
            else {
                waterArea = height[j]*(j - i);
                j--;
            }
            maxWater = max(maxWater, waterArea);
        }
        return maxWater;
    }
};