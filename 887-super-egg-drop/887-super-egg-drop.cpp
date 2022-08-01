class Solution {
public:
    int solve(int e, int n, vector<vector<int>> &t){
        if(t[e][n] != -1)
            return t[e][n];
            
        if( e == 1  || n == 0 || n == 1){
            return n;
        }
        
        int l = 1, h = n, mn = INT_MAX, mid, low, high;
        int temp_ans;
        
        while (l < h) {
            mid = l + (h - l) / 2;
            if(t[e - 1][mid - 1] != -1)
                low = t[e - 1][mid - 1];
            else{
                low = solve(e - 1, mid - 1, t);
                t[e - 1][mid - 1] = low;
            }
            if(t[e][n - mid]!= -1)
                high = t[e][n - mid];
            else{
                high = solve(e, n - mid, t);
                t[e][n - mid] = high;
            }
            mn = min(mn, max(low, high) + 1);
            if (low == high) {
                break;
            } else if (low < high) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        
        return t[e][n] = mn;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int superEggDrop(int k, int n) {
        vector<vector<int>>t(k+1,vector<int>(n+1,-1));
        return solve(k, n, t);
        
    }
};