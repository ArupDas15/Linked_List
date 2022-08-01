
class Solution {
public:
//     int solve(int e, int n, vector<vector<int>> &t){
//         if(t[e][n] != -1)
//             return t[e][n];
            
//         if( e == 1  || n == 0 || n == 1){
//             return n;
//         }
        
//         int low, high, mn = INT_MAX;
//         int temp_ans;
//         for(int k = 1; k <= n; k++ ){
//             if(t[e - 1][k - 1] != -1)
//                 low = t[e - 1][k - 1];
//             else{
//                 low = solve(e - 1, k - 1, t);
//                 t[e - 1][k - 1] = low;
//             }
//             if(t[e][n - k] != -1)
//                 high = t[e][n - k];
//             else{
//                 high = solve(e, n - k, t);
//                 t[e][n - k] = high;
//             }
            
//             temp_ans = 1 + max(low, high);
//             mn = min(mn, temp_ans);
//         }
//         return t[e][n] = mn;
//     }
    int helper(int K, int N, vector<vector<int>>& memo){
        if (N <= 1) {
            return N;
        }
        if (K == 1) {
            return N;
        }
        if (memo[K][N] > 0) {
            return memo[K][N];
        }
        
        int low = 1, high = N, result = N;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int left = helper(K - 1, mid - 1, memo);
            int right = helper(K, N - mid, memo);
            result = min(result, max(left, right) + 1);
            if (left == right) {
                break;
            } else if (left < right) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        memo[K][N] = result;
        return result;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int superEggDrop(int k, int n) {
        vector<vector<int>>t(k+1,vector<int>(n+1,-1));
        return helper(k, n, t);
        
    }
};