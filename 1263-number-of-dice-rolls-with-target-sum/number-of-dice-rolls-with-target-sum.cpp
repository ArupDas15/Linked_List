class Solution {
private:
    const int MOD = 1e9 + 7;
    map<pair<int,int>, int> cache; 
public:
    int numRollsToTarget(int n, int k, int target) {
        if(n == 0) {
            if(target == 0) 
                return 1;
            else 
                return 0;
        }
        if(cache.find({n, target}) != cache.end())
            return cache[{n, target}];
        
        int res = 0;

        for(int val = 1; val < k + 1; val++) {
            res = (res + numRollsToTarget(n - 1, k, target - val)) % MOD;
        }
        return cache[{n, target}] = res; 
    }
};