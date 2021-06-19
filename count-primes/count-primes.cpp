
class Solution {
public:
    int countPrimes(int n) {
        // Initialize a boolean array from 0 to n
        vector<bool> isPrime(n+1,true);
        long long int count = 0;

        for (long long int i = 2; i < n; i++){
            if(isPrime[i]){
                count = count + 1;
                for (long long int j = i * i; j < n; j=j+i){
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};