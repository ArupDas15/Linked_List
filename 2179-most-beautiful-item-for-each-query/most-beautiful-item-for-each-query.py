class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        # Sort items by price (items[i][0])
        items.sort(key=lambda x: x[0])
        
        # Update the beauty values with the maximum beauty seen so far
        maxBeauty = items[0][1]
        for i in range(len(items)):
            maxBeauty = max(items[i][1], maxBeauty)
            items[i][1] = maxBeauty
        
        # Define the binary search function
        def binarySearch(items, targetPrice):
            left, right = 0, len(items) - 1
            maxBeauty = 0
            while left <= right:
                mid = (left + right) // 2
                if items[mid][0] > targetPrice:
                    right = mid - 1
                else:
                    maxBeauty = max(maxBeauty, items[mid][1])
                    left = mid + 1
            return maxBeauty
        
        # Process each query and store the result
        result = []
        for query in queries:
            result.append(binarySearch(items, query))
        
        return result