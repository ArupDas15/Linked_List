class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minbp = prices[0]
        profit = 0

        for i in range(1, len(prices)):
            cur_profit = prices[i] - minbp
            profit = max(profit, cur_profit)
            minbp = min(minbp, prices[i])
        return profit
        