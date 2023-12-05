class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        int prev = 1;
        int count = 0;

        while (prev <= k) {
            int next = fib.back() + fib[fib.size() - 2];
            fib.push_back(next);
            prev = next;
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
