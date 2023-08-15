from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        dp = [0 for _ in range( len(nums)+1 )]
        ret = 1

        for i in range (0, len(nums)):
            dp[i] = 1

            for j in range (0, i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[j]+1, dp[i])

            ret = max (ret, dp[i])

        return ret
