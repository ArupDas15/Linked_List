class Solution {
public:
    // Time complexity: O(k)
    // Space complexity: O(k)
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        int prev = 1;
        int count = 0;
        for (int i = 1; prev <= k; i++) {
            if (i == 1 || i == 2) {
                fib.push_back(1);
            } else {
                fib.push_back(fib.back() + fib[fib.size() - 2]);
                prev = fib.back();  
            }
        }
        for (int i = fib.size() - 1; i >= 0 && k > 0; i--) {
            if (fib[i] <= k) {
                count++;
                k = k - fib[i];
            }
        }
        return count;
    }
};
