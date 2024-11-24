class Solution {
public:
    // Time Compelity: O(n*n)
    // Space complexity: O(1)
    /* OBSERVATIONS
    1. If there are even number of negative result is sum of absolute values of all elements
    2. If there is odd negatives, 
       result is sum of absolute values of all elements - smallest absolute value of the element 
       in the matrix becuase the negative sign is transferrable due to the given matrix operation.
    */
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int maxNegative = INT_MAX;
        int negative_count = 0;
        long long int sum = 0;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                int num = matrix[i][j];
                sum = sum + abs(num);
                if (num < 0 ) {
                    negative_count++;
                }
                maxNegative = min(maxNegative, abs(num));
            }
        }
        if (negative_count % 2) {
            sum = sum - 2*maxNegative;
        }
        return sum;
    }
};