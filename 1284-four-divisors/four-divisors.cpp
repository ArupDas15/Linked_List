class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i==0) return false;
        }
        return true;
    }
    bool isCube(int n) {
        long long int cubeRoot = round(cbrt(n));
        return n == cubeRoot * cubeRoot * cubeRoot;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        // There are 2 cases:
        // Case 1: p^3 is cube of prime number p: 1,p,p^2,p^3 
        // Ans = 1+p+p^2+p^3
        for(int idx = 0; idx < nums.size(); idx++) {
            int n = nums[idx];
            int p = round(cbrt(n));
            if (isCube(n) && isPrime(p)) {
                sum = sum + 1 + p + p*p + n;
            }
        }
        // Case 2: n= p*q where p and q are prime e.g. 6 = 2*3, 10=2*5
        // Ans = 1+p+q+n
        // If you have a number \(n\), any divisor \(i\) must have a 
        // "partner" \(j\) such that:
        // \(i\times j=n\quad \text{or}\quad j=\frac{n}{i}\)
        // Mathematically, it is impossible for both \(i\) and \(j\) to be 
        // greater than \(\sqrt{n}\). If \(i>\sqrt{n}\) and \(j>\sqrt{n}\), 
        // then \(i\times j\) would be greater than \(n\).Therefore, in every 
        // divisor pair, at least one divisor must be less than or equal to 
        // \(\sqrt{n}\)
        for(int idx = 0; idx < nums.size(); idx++) {
            int n = nums[idx];
            // Multiplicatin is faster than sqrt().
            for(int i = 2; i*i <= n;i++) {
                if(n % i == 0 && n/i != i && isPrime(i) && isPrime(n/i)) {
                    sum = sum + 1 + i + (n/i) + n;
                    break; 
                }
            }
        }
        return sum;
    }
};