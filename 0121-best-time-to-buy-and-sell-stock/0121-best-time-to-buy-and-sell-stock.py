class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low_price = prices[0]
        max_profit = 0
        for i in range(len(prices)):
            max_profit = max(max_profit, prices[i] - low_price)
            low_price = min(low_price, prices[i])
        return max_profit