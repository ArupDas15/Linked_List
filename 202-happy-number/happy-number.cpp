class Solution {
public:
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
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};