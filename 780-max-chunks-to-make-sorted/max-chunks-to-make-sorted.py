class Solution:
    """
    You want to be able to stitch the chunks back together without any additional 
    sorting or merging or whatever. In that example, sorting any chunks smaller 
    than the whole would leave you with extra sorting to do once the chunks were sorted.
    In the second example, you cannot sort [1], [0], [2], [3], [4] you can only concatenate. 
    Thus the largest number of permissible chunks are [1, 0], [2], [3], [4] -> which after sorting becomes
    [0, 1], [2], [3], [4]

    We will iterate over the array and maintain a stack to represent the maximum values of the chunks created so far. 
    As we loop over the array, we decide whether the current element (arr[i]) can start a new chunk or should merge
    with an existing chunk.

    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        stack = deque()

        for i in range(n):
            # Case 1: arr[i] > max_element i.e. stack top
            if not stack or arr[i] > stack[-1]:
                stack.append(arr[i])
            # Case 2: arr[i] < max_element then it should merge with a chunk
            # Remember the elements in the stack represent the max element in the chunk
            else:
                max_element = stack[-1]
                while stack and arr[i] < stack[-1]:
                    stack.pop()
                stack.append(max_element)

        return len(stack)