from typing import List
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = [[0 for _ in range(2000+1)]for _ in range(len(nums))]

        # 0 can be +0 and -0, so initial will be 2 for 0
        dp[0][nums[0]] = 1 if nums[0] != 0 else 2

        for i in range(1, len(nums)):
            for j in range(1000+1):
                dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][abs(j-nums[i])]

        return dp[len(nums)-1][abs(target)]
