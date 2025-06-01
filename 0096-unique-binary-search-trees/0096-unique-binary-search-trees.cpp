class Solution {
public:
    // vector<int> cat;
    unsigned long int binCoeff(int n, int r) {
        if (r > n - r) {
            r = n - r;
        }
        
        unsigned long int res = 1;

        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i+1);
        }

        return res;
    }

    int numTrees(int n) {
        // cat.push_back(1);
        // cat.push_back(1);
        
        // for(int i = 2; i <= n; i++) {
        //     cat.push_back(0);
        //     for(int j = 0; j < i; j++)
        //     cat[i] += (cat[j]*cat[i-j-1]);
        // }
        // return cat[n];
        return binCoeff(2*n,n)/(n+1);
    }
};