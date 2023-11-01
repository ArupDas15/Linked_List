class Solution {
public:
    static int hammingWeight(int n) {
        int hamming_wt = 0;
        while(n > 0) {
            hamming_wt++;
            n &= (n - 1);
        }
        return hamming_wt;
    }
    
    static bool compare(int a, int b) {
        int wt_a = hammingWeight(a);
        int wt_b = hammingWeight(b);

        if(wt_a == wt_b) {
            return a < b;
        }
        return wt_a < wt_b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};