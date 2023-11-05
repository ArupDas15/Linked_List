class Solution {
public:
       // Time Complexity: O(n)
int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int num : left) {
            ans = max(ans, num);
        }
        
        for (int num : right) {
            ans = max(ans, n - num);
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     // Time Complexity: O(n)
//     int getLastMoment(int n, vector<int>& left, vector<int>& right) {
//         int left_time, right_time;
//         if (left.size()==0) {
//             left_time=-1;
//         } else if (right.size() == 0) {
//             right_time=-1;
//         }
//         if (left_time != -1)left_time = INT_MIN;
//         if (right_time != -1)right_time = INT_MAX;
//         for(int i = 0; i < left.size(); i++) {
//             left_time= max(left_time, left[i]);
//         }
//         for(int i = 0; i < right.size(); i++) {
//             right_time = min(right_time, right[i]);
//         }
//         if(left_time == -1) return (n - right_time);
//         else if (right_time == -1) return left_time;
//         return max(left_time, (n - right_time));
//     }
// };
