class Solution {
public:
    // When we are doing XOR between two numbers A and B,
    // the maximum result of the XOR will be the 2^ maximum number of bits in A and B.
    // So, the largest maximum result we can get is 2^maximumbit - 1.
    // Thus, if A^B = 2^maximumbit - 1 and we need to find B so B = A ^ (2^maximumbit - 1).
    // ALGORITHM:
    // STEP 1: Find the prefix XOR of nums.
    // STEP 2: 
    //    answer[0] = prefixXOR[n-1]^(2^maximumbit - 1)
    //    answer[1] = prefixXOR[n-2]^(2^maximumbit - 1)
    //    ...
    //    answer[n - 1] = prefixXOR[0]^(2^maximumbit - 1) 
    // Time Complexity: O(n)
    // Space complexity: O(n)
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer(nums.size(), 0);
        vector<int> prefixXOR(nums.size(), 0);
        int maximumXOR = (pow(2, maximumBit) - 1);

        prefixXOR[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = (prefixXOR[i] ^ maximumXOR);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};