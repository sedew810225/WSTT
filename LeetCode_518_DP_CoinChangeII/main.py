from typing import List


class Solution:
    def change2(self, amount: int, coins: List[int]) -> int:
        dp = [[-1 for _ in range(amount+1)] for _ in range(len(coins))]

        for i in range(len(coins)-1,-1,-1):
            for remain in range(amount+1):

                #no selection case
                if remain == 0:
                    dp[i][0] = 1
                    continue

                #included
                if remain - coins[i] < 0:
                    selected = 0
                else:
                    selected = dp[i][remain-coins[i]]

                #included + excluded
                if i == len(coins)-1:
                    dp[i][remain] = selected
                else:
                    dp[i][remain] = selected + dp[i + 1][remain]

        return dp[0][amount]


#space minimized
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [1 for _ in range(amount+1)]

        for i in range(len(coins)-1,-1,-1):
            for remain in range(1, amount+1):

                inclusive = 0 if remain - coins[i] < 0 else dp[remain-coins[i]]

                if i == len(coins)-1:
                    dp[remain] = inclusive
                else:
                    dp[remain] = inclusive + dp[remain]

        return dp[amount]
