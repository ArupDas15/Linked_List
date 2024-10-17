class Solution {
public:
    /* STEPS
    1. Scan the integer from right to left
       and store the index of the max digit from the current position 
       which can be swapped in a vector named maxRightIdx.
    2. Scan the integer from left to right
       and if the digit at current position i is 
       less than the digit at maxRightIdx[i] then perform 
       the swap and output the ans.
    TC: O(n), SC: O(n)
    */
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.length();
        vector<int> maxRightIdx (n,-1);
        int ans = num;

        // First pass
        maxRightIdx[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            maxRightIdx[i] = 
                (numStr[i] > numStr[maxRightIdx[i + 1]]) 
                ? i : maxRightIdx[i + 1];
        }

        // Second pass
        for(int i = 0; i < n; i++) {
            if (numStr[i] < numStr[maxRightIdx[i]]) {
                swap(numStr[i], numStr[maxRightIdx[i]]);
                ans = stoi(numStr);
                break;
            }
        }
        return ans;
    }
};