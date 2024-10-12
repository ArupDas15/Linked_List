class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals based on their starting points
        sort(intervals.begin(), intervals.end());
        
        // Min-heap to track end times of current groups
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (const auto& interval : intervals) {
            // If the current interval can extend the earliest ending group
            if (!minHeap.empty() && interval[0] > minHeap.top()) {
                minHeap.pop(); // Remove the group that can be extended
            }
            // Add the current interval's end time to the heap
            minHeap.push(interval[1]);
        }
        
        // The size of the heap is the number of groups needed
        return minHeap.size();
    }
};