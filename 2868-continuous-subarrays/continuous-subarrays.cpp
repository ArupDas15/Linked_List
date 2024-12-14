class Solution {
public:

    long long continuousSubarrays(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int left = 0, right = 0;
        long long int count = 0;

        while (right < nums.size()) {
            // Increase the frequency of the current number
            freq[nums[right]]++;

            // Check if the difference between max and min values in the map exceeds 2
            while (std::max_element(freq.begin(), freq.end(), 
                    [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                        return a.first < b.first; // Compare keys for max
                    })->first - std::min_element(freq.begin(), freq.end(), 
                    [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                        return a.first < b.first; // Compare keys for min
                    })->first > 2) {
                // Decrease the frequency of the element at 'left'
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]); // Remove element if frequency becomes 0
                }
                left++;
            }

            // Increment the count for the valid subarray ranges
            count += right - left + 1;
            right++;
        }

        return count;
    }
     
};