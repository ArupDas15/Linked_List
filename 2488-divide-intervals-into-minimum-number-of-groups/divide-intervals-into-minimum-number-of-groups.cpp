class Solution {
public:
    /* STEPS 
    1.  Sort the intervals by their starting points. If two intervals start at the same point, sort by their ending points.
    2. Maintain a min-heap that keeps track of the end times of the intervals in the current groups.
    3. Iterate Over the Sorted Intervals:
       3.1. For each interval, check if it can extend the group represented by the earliest end time in the heap.
       3.2. If the current interval starts after the earliest end time, you can reuse that group by replacing the end time.
       3.3. If it cannot, add a new group.
    Time Complexity: O(nlogn); O(nlogn) for sorting, logn for every heapification and we do it n times.
    Space complexity: O(n) for storing n intervals.
    */
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (const auto& interval : intervals) {
            if (!minHeap.empty() && interval[0] > minHeap.top()) {
                minHeap.pop(); 
            }
            minHeap.push(interval[1]);
        }
        return minHeap.size();
    }
};