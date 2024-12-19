# Time Complexity: O(n)
# Space Complexity: O(n)
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stack = []
        ans = [0] * len(prices)

        for idx, ele in enumerate(prices):
            while (len(stack) > 0) and (stack[len(stack)-1][0] >= ele):
                old_price, item_idx = stack.pop()
                new_price = old_price - ele
                ans[item_idx] = new_price

            stack.append((ele, idx))
        while len(stack) > 0:
            old_price, item_idx = stack.pop()
            ans[item_idx] = old_price
        
        return ans
