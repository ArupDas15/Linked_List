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
            if (isCube(n) && isPrime(round(cbrt(n)))) {
                sum = sum + 1 + round(cbrt(n)) + round(cbrt(n))*round(cbrt(n)) + n;
            }
        }
        // Case 2: n= p*q where p and q are prime e.g. 6 = 2*3, 10=2*5
        // Ans = 1+p+q+n
        for(int idx = 0; idx < nums.size(); idx++) {
            int n = nums[idx];
            for(int i = 2; i <= sqrt(n);i++) {
                if(n % i == 0 && n/i != i && isPrime(i) && isPrime(n/i)) {
                    sum = sum + 1 + i + (n/i) + n;
                    break; 
                }
            }
        }
        return sum;
    }
};