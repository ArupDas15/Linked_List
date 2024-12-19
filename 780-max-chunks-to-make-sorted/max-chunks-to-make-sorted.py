class Solution:
    """
    If max_so_far == i, it means that the largest element seen so far is equal to the current index. 
    This is an important property because:
    The sorted array is a sequence of numbers from 0 to n-1. The number at index i in the sorted array must be i.
    If max_so_far == i, it means that all elements in the array from index 0 to i are less than or equal to the value of i 
    (i.e., the chunk ending at index i can be sorted independently of the remaining part of the array).
    """
    def maxChunksToSorted(self, arr):
        n = len(arr)
        chunks = 0
        max_element = 0

        # Iterate over the array
        for i in range(n):
            # Update max_element
            max_element = max(max_element, arr[i])

            if max_element == i:
                # All values in range [0, i] belong to the prefix arr[0:i]; a chunk can be formed
                chunks += 1

        return chunks