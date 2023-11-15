class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 1;
        int n = arr.size();
        vector<int> counts(n + 1, 0);

        for(int num : arr) {
            counts[min(num,n)]++;
        }
        for(int num = 2; num <= n; num++) {
            ans = min(ans + counts[num], num);
        }
        return ans;
    }
};

// class Solution {
// public:
    // Time complexity: O(n⋅log⁡n)
    // Space complexity: O(log⁡n)
    /* ----------------------------------------------------------------------------
    In C++, the sort() function provided by STL uses a hybrid of Quick Sort, 
    Heap Sort and Insertion Sort, with a worst-case space complexity of O(log⁡n).
    -------------------------------------------------------------------------------*/
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         sort(arr.begin(),arr.end());
//         arr[0] = 1;
//         for(int i = 1; i < arr.size(); i++) {
//             if(abs(arr[i] - arr[i - 1]) <= 1) {
//                 continue;
//             } else {
//                 arr[i] = arr[i - 1] + 1;
//             }
//         }
//         return arr[arr.size() - 1];
//     }
// };