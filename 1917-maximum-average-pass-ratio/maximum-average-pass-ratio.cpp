
class Solution {
public:
    // Helper function to calculate the possible increment in average ratio
    void heapPush(vector<vector<int>>& costs, int idx, priority_queue<pair<double, int>>& heap) {
        double cur_avg = static_cast<double>(costs[idx][0]) / costs[idx][1];
        double new_avg = static_cast<double>(costs[idx][0] + 1) / (costs[idx][1] + 1);
        double possible_increment = new_avg - cur_avg;
        heap.push({possible_increment, idx});  // Push negative increment to simulate min-heap
    }

    // Function to calculate the maximum average ratio
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> heap;  // Max-heap based on the possible increment
        double final_avg = 0.0;

        // Initialize the heap with the initial possible increments
        for (int i = 0; i < classes.size(); ++i) {
            heapPush(classes, i, heap);
        }

        // Distribute extra students
        while (extraStudents > 0) {
            --extraStudents;
            int class_id = heap.top().second;  // Get the class with the highest possible increment
            heap.pop();
            
            // Increment the class
            classes[class_id][0] += 1;
            classes[class_id][1] += 1;

            // Recalculate the possible increment for this class and push it back into the heap
            heapPush(classes, class_id, heap);
        }

        // Calculate the final average ratio
        for (int i = 0; i < classes.size(); ++i) {
            final_avg += (double)(classes[i][0]) / classes[i][1];
        }

        return final_avg / classes.size();
    }
};
