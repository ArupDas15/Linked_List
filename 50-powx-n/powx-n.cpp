class Solution {
public:
    double myPow(double x, int n) {
        double nn = n;
        if(n < 0) nn = (double)-1*n;
        double ans = 1.0;
        while(nn != 0) {
            if(remainder(nn, 2) != 0) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if(n<0)return 1.0/ans;
        return ans;
    }
};