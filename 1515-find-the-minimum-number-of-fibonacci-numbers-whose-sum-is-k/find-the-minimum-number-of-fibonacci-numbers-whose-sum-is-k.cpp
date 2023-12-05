class Solution {
public:
    // Time complexity: O(k)
    // Space complexity: O(k)
    int findMinFibonacciNumbers(int k) {
        int prev = 1;
        int count = 0;
        vector<int> fib;

        fib.push_back(1);
        fib.push_back(1);
        while (prev <= k) {
            fib.push_back(fib.back() + fib[fib.size() - 2]);
            prev = fib.back();  
        }
        for (int i = fib.size() - 2; i >= 0 && k > 0; i--) {
            if (fib[i] <= k) {
                count++;
                k = k - fib[i];
            }
        }
        return count;
    }
};
