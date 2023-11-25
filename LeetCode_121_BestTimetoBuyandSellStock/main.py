from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prevMin = prices[0]
        maxProfit = 0

        for price in prices:
            temp = price-prevMin
            if maxProfit < temp:
                maxProfit = temp
            if prevMin > price:
                prevMin = price

        return maxProfit

    def maxProfit_tuned(self, prices: List[int]) -> int:
        maxProfit = 0

        for i in range(1, len(prices)):
            temp = prices[i]-prices[i-1]
            if maxProfit < temp:
                maxProfit = temp
            if prices[i-1] < prices[i]:
                prices[i] = prices[i-1]

        return maxProfit