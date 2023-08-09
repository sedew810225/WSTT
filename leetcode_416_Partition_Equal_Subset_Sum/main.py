class Solution:
    def canPartition(self, nums: list[int]) -> bool:

        target = int(sum(nums) / 2)
        dp = [0 for _ in range(target +1)]
        dp[0] = 1

        # if half of sum is odd, it's always false
        if sum(nums) % 2 == 1:
            return False

        #dp saves current sum
        #if dp[target] is true, that means it reached answer
        for a in nums:
            for i in range(target,-1,-1):
                if dp[i] == 1:
                    if i + a <= target:
                        dp[i + a] = 1

                if dp[target] == 1:
                    return True

        return False
