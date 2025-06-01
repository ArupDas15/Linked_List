class Solution {
public:
    vector<int> cat;
    int numTrees(int n) {
        cat.push_back(1);
        cat.push_back(1);
        
        for(int i = 2; i <= n; i++) {
            cat.push_back(0);
            for(int j = 0; j < i; j++)
            cat[i] += (cat[j]*cat[i-j-1]);
        }
        return cat[n];
    }
};