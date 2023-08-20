import sys
from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [10**4+1 for _ in range(amount+1)]
        dp[0] = 0

        for coin in coins:
            if coin <= amount:
                dp[coin] = 1

        for k in range(1, amount+1):
            for coin in coins:
                if k - coin >= 0:
                    dp[k] = min(dp[k], dp[coin] + dp[k-coin])

        if dp[amount] >= 10**4 + 1:
            dp[amount] = -1

        return int(dp[amount])
