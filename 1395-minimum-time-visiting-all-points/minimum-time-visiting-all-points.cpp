class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1)
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        
        int steps = 0;
        int prev_x1 = points[0][0];
        int prev_y1 = points[0][1];

        for(int i = 1; i < points.size(); i++) {
            int cur_x1 = points[i][0];
            int cur_y1 = points[i][1];

            steps += max(abs(cur_x1 - prev_x1), abs(cur_y1 - prev_y1));
            prev_x1 = cur_x1;
            prev_y1 = cur_y1;
        }
        return steps;
    }
};

// class Solution {
// public:
    // time complexity: O(nk) where k is the maximum distance between 2 points.
    // space complexity: O(1)
//     int minTimeToVisitAllPoints(vector<vector<int>>& points) {
//         if (points.size() == 1) return 0;
        
//         int steps = 0;
//         int prev_x1 = points[0][0];
//         int prev_y1 = points[0][1];

//         for(int i = 1; i < points.size(); i++) {
//             int cur_x1 = points[i][0];
//             int cur_y1 = points[i][1];

//             while(prev_x1 != cur_x1 || prev_y1 != cur_y1) {
//                 if (prev_x1 > cur_x1) 
//                     prev_x1 = prev_x1 - 1;
//                 else if (prev_x1 < cur_x1) 
//                     prev_x1 = prev_x1 + 1;
//                 if (prev_y1 > cur_y1) 
//                     prev_y1 = prev_y1 - 1;
//                 else if (prev_y1 < cur_y1) 
//                     prev_y1 = prev_y1 + 1;
//                 steps = steps + 1;
//             }
//         }
//         return steps;
//     }
// };
