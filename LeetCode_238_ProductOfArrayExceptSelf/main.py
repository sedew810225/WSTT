from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        ret = [1] * length

        #left
        prev = 1
        for i in range(length):
            ret[i] = prev
            prev = prev*nums[i]

        #right
        prev = 1
        for i in range(length-1, -1, -1):
            ret[i] = ret[i] * prev
            prev = prev*nums[i]

        return ret

    def productExceptSelf_tune(self, nums: List[int]) -> List[int]:
        length = len(nums)
        ret = [1] * length

        #left
        for i in range(1, length):
            ret[i] = ret[i-1] * nums[i-1]

        #right
        prev = 1
        for i in range(length-1, -1, -1):
            ret[i] = ret[i] * prev
            prev = prev*nums[i]

        return ret
