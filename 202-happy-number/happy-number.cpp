class Solution {
public:
/*
    Once you begin summing the squares of its digits, the resulting number will quickly decrease, often falling within a smaller range.
    Thus the outer while loop will run a constant number of times. While the inner 
    loop will run O(log n to base 10) times.
    Space complexity is O(1).
*/
    bool isHappy(int n) {
        set<int> s;

        while(s.find(n) == s.end()) {
            int sum = 0;

            s.insert(n);
            while(n != 0) {
                int dig = n % 10;
                n = n / 10;
                dig = pow(dig, 2);
                sum = sum + dig;
            }
            n = sum;
        }
        return n == 1;
    }
};