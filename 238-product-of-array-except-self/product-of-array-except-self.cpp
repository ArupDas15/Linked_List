class Solution {
public:
    /* ALGORITHM
       1. Initialise prefixProduct = suffixProduct = 1
       2. Initialise a vector prefixSuffixProduct to store the product.
       --- PREFIX PRODUCT CALCULATION
       3. Iterate over all elements of nums from 0 to nums.size()-1
          3.1. The prefix of an element is the product until the previous element.
               The prefix product of element at index 0 is 1.
       --- SUFFIX PRODUCT CALCULATION
       4. Iterate over all elements of nums from nums.size() - 1 to 0.
          4.1. The suffix of an element is the product after the current element.
               The suffix product of an element at index nums.size() - 1 is 1.
       5. Multiply the vectors prefix and suffix to find the prefixSuffixProduct vector.
    */
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSuffixProduct(nums.size(), 1);
        int prefixProduct = 1;
        int suffixProduct = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            prefixSuffixProduct[i] *= prefixProduct;
            prefixProduct *= nums[i];
        }
        cout<<endl;
        for(int i = nums.size() - 1; i >= 0; i--) {
            prefixSuffixProduct[i] *= suffixProduct; 
            suffixProduct *= nums[i];
        }
        return prefixSuffixProduct;
    }
};