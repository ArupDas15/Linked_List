class Solution {
public:
    int totalMoney(int n) {
        int bal;
        int total = 0;
        int monday = 0;

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
            total += (bal*((2*monday) + (bal - 1)))/2;
        }    
        return total;
    }
};