class Solution {
public:
    // ALGORITHM
    // The XOR operation adds bits without considering the carry.
    // AND (&) and left shift (<<): Used to calculate the carry.
    // The number of recursive calls is proportional to the number 
    // of bits in the larger number. the time complexity is constant
    // (O(1) for bitwise operations)
    // Time complexity: O(log(max(a, b)))
    // The space complexity is determined by the recursion depth
    // Space complexity: O(log(max(a, b)))
    int getSum(int a, int b) {
        // Base case: when no carry is left, return the sum
        return b==0? a:getSum(a^b, (a&b)<<1); 
    }
};