from typing import List
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dp_min = [0 for _ in range(len(nums)+1)]
        dp_max = [0 for _ in range(len(nums)+1)]

        dp_max[0] = nums[0]
        dp_min[0] = nums[0]
        ret = dp_max[0]

        for i in range(1,len(nums)):
            dp_min[i] = min(nums[i], nums[i]*dp_min[i-1], nums[i]*dp_max[i-1])
            dp_max[i] = max(nums[i], nums[i]*dp_min[i-1], nums[i]*dp_max[i-1])
            ret = max(ret, dp_max[i], dp_min[i])

        return ret

    def maxProduct2(self, nums: List[int]) -> int:
        dp_min = nums[0]
        dp_max = nums[0]
        ret = dp_max

        for i in range(1,len(nums)):
            tempmin = dp_min
            tempmax = dp_max
            dp_min = min(nums[i], nums[i]*tempmin, nums[i]*tempmax)
            dp_max = max(nums[i], nums[i]*tempmin, nums[i]*tempmax)
            ret = max(ret, dp_max, dp_min)

        return ret

    def maxProduct3(self, nums: List[int]) -> int:
        dp_min = nums[0]
        dp_max = nums[0]
        ret = dp_max

        for num in nums[1:]:
            tempmin = dp_min
            tempmax = dp_max
            dp_min = min(num, num*tempmin, num*tempmax)
            dp_max = max(num, num*tempmin, num*tempmax)
            ret = max(ret, dp_max, dp_min)

        return ret