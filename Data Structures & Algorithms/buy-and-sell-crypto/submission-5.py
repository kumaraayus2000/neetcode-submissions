class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min1 = prices[0]
        max1 = 0
        price = 0
        for x in prices:
            min1 = min(x,min1)
            price = max(x-min1,price)

        return price
