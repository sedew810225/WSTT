from typing import List

class Solution:
    def twoSum_bruteforce(self, nums: List[int], target: int) -> List[int]:
        len_nums = len(nums)

        for i in range(len_nums):
            temp = target - nums[i]
            for j in range(i+1, len_nums):
                if nums[j] == temp:
                    return [i, j]

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        len_nums = len(nums)
        idxmap = {}

        for i in range(len_nums):
            #if there are same nums, it'll save the last element's index
            idxmap[nums[i]] = i

        for i in range(len_nums):
            temp = target - nums[i]

            if idxmap.__contains__(temp):
                temp_idx = idxmap[temp]
                if i == temp_idx:
                    continue
                return [i, temp_idx]


    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        len_nums = len(nums)
        idxmap = {}

        for i in range(len_nums):
            temp = target - nums[i]

            if idxmap.__contains__(temp):
                temp_idx = idxmap[temp]
                if i == temp_idx:
                    continue
                return [temp_idx, i]
            else:
                idxmap[nums[i]] = i