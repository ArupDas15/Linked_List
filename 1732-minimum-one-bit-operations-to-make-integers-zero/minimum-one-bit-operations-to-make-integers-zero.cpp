class Solution {
public:
    /*
    Video Solution: https://www.youtube.com/watch?v=yRI18_MaG7k
    Suppose, n = 1 0 0 0
    1 0 0 1 - CHANGE 0TH BIT
    1 0 1 1 - change 1st bit
    1 0 1 0 - change 0th bit
    1 1 1 0 - change 2nd bit
    1 1 1 1 - CHANGE 0TH BIT
    1 1 0 1 - change 1st bit
    1 1 0 0 - CHANGE 0TH BIT
    0 1 0 0 - change 3rd bit - After removing the 3rd bit(the most significant bit, our 
                               goal is now reduced to removing the 2nd bit which is now 
                               the most signigicant bit)
    0 1 0 1 - CHANGE 0TH BIT
    0 1 1 1 - change 1st bit
    0 1 1 0 - CHANGE 0TH BIT
    0 0 1 0 - change 2nd bit - After removing the 2nd bit(the most significant bit, our
                               goal is now reduced to removing the 1st bit which is now
                               the most signigicant bit)
    0 0 1 1 - CHANGE 0TH BIT
    0 0 0 1 - change 1st bit - After removing the 1st bit(the most significant bit, our
                               goal is now reduced to removing the 0th bit which is now
                               the most signigicant bit)
    0 0 0 0 - CHANGE 0TH BIT

    So we are always changing the 0th bit and then a different bit. Our goal is to reduce the 
    number evantually to 0 by repeatedly removing the most significant bit.
    We have only 2 choices at a time. We can either change the 0th bit or we can change a  
    different bit "i", provided (i - 1)th bit is 1 and (i - 2)th bit to the rightmost bit are
    0.
    The number of steps taken to reduce n = 1000 to 0 is
    2^3 + 2^2 + 2^1 + 2^0 = 8 + 4 + 2 + 1 = 15
    The above is a mathematical series that we have seen in the case of binary trees. 
    2^k + 2^(k - 1) + 2^(k - 2) + 2^(k - 3) + ... + 2^1 + 2^0 
    = 1.(2^( k + 1) - 1) / (2 - 1) = 2 ^ (K + 1) - 1 
    */
    // Time Complexity: O(log n * log n)
    // Space complexity: O(log n)
    int minimumOneBitOperations(int n) {
        // BASE CASE
        if( n == 0) return 0;
        int k = 0;

        // To find the most significant bit it takes O(log n) time.
        while(pow(2, k) <= n) {
            k++;
        }
        k = k - 1;
        // The recursive function is called log n times. 
        // We subtract because the number of steps reduces when n contains 1's at places other 
        // than the most significant bit.
        return pow(2, k + 1) - 1 - minimumOneBitOperations(((int)pow(2, k)) ^ n);
    }
};