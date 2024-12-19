class Solution:
    """
     ALGORITHM:
    1. We are going to use 2 pointer technique. Where the left pointer will be initialised
        to starting of height and right pointer will be intialised to ending of height.
    2. Observation: Max water between 2 heights is the min(height[left], height[right])*(right-left). Thus,
       we are going to shift the pointer that points to the lower line because the height of the
       lower line limits the maximum water that the container can store. By always moving the pointer 
       pointing to the shorter line, you're trying to find a taller line that could increase the area. 
       Moving the taller line won't help because it isn't limiting the area—it's the shorter line that is. 
    3. If height[left] < height[right] we move left pointer to the right because if you move right pointer
       to the left, the distance between the lines decreases, and the area would become smaller or stay
       the same (since height[left] is already the limiting factor).
    4. Similarly, if height[right] < height[left] we move the right pointer to the left.
    
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxWaterArea = -float('inf')

        while left < right:
            waterArea = -float('inf')
            if height[left] < height[right]: 
                waterArea = height[left] * (right-left)
                left += 1
            else: 
                waterArea = height[right] * (right-left)
                right -= 1
            maxWaterArea = max(maxWaterArea, waterArea)
        return maxWaterArea
