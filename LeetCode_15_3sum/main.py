from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        result_list = []
        nums.sort()
        len_nums = len(nums)

        for k in range(len_nums):
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            i = k + 1
            j = len_nums - 1

            while i < j:
                threesum = nums[i] + nums[j] + nums[k]

                if threesum > 0:
                    j -= 1
                elif threesum < 0:
                    i += 1
                else:
                    result_list.append([nums[k], nums[i], nums[j]])
                    while i < j and nums[i] == nums[i + 1]:
                        i += 1
                    while i < j and nums[j] == nums[j - 1]:
                        j -= 1
                    i += 1
                    j -= 1

        return result_list
