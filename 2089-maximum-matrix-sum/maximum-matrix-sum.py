class Solution:
    # Time Complexity: O(n*n)
    # Space Complexity: O(1)
    
    # OBSERVATIONS:
    # 1. If there are an even number of negative elements, the result is the sum of absolute values of all elements.
    # 2. If there is an odd number of negative elements, the result is the sum of absolute values minus the smallest absolute value
    #    in the matrix because the negative sign is transferrable due to the given matrix operation.
    
    def maxMatrixSum(self, matrix):
        maxNegative = float('inf')  # Track the smallest absolute value (most negative number)
        negative_count = 0
        total_sum = 0

        # Traverse the matrix to calculate the sum of absolute values
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                num = matrix[i][j]
                total_sum += abs(num)  # Add the absolute value of each number
                if num < 0:
                    negative_count += 1
                maxNegative = min(maxNegative, abs(num))  # Track the smallest absolute value

        # If the number of negative elements is odd, subtract twice the smallest absolute value
        # By subtracting twice we remove the presence of maxNegative from sum and then we subtract maxNegative from sum of positives.
        if negative_count % 2 != 0:
            total_sum -= 2 * maxNegative
        
        return total_sum
