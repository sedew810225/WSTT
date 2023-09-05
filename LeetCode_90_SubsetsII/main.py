import copy
from typing import List

class Solution:

    def rec(self, index:int, tempList:List[int], nums:List[int], output:List[List[int]]):
        prev = -100

        for i in range(index, len(nums)) :
            if prev == nums[i] :
                continue
            prev = nums[i]

            midList = copy.deepcopy(tempList)
            midList.append(nums[i])
            output.append(midList)
            self.rec(i+1, midList, nums, output)
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        output = [[]]
        nums.sort()

        self.rec(0,[], nums, output)
        return output
    