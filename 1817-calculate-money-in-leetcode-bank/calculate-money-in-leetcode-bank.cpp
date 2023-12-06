class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int totalMoney(int n) {
        int bal = 0;
        int total = 0;
        int monday = 0;

        // while-loop iterates n/7 times.
        while(n > 0) {
            if(n < 7) {
              bal = n;
              n = 0;
            }
            else {
              bal = 7;
              n = n - 7;
            }
            monday += 1;
            // Sum on n terms in an AP where d = 1.
            // Sn = n/2*(2a+(n-1)d)
            // As per the constraints, 1 <= n <= 1000
            // that is why we modified Sn = (n*(2a+(n-1)d))/2
            // otherwise we would need to convert Sn to 
            // floating type and return an integer.
            total += (bal*((2*monday) + (bal - 1)))/2;
        }    
        return total;
    }
};
