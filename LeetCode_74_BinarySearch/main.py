from typing import List

class Solution:
    def binsearch(self, start:int,end:int, nums: List[int], target:int):
        if start > end :
            return -1

        mid = int((end+start)/2)

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            return self.binsearch(mid+1, end, nums, target)
        elif nums[mid] > target :
            return self.binsearch(start, mid-1, nums, target)

    def binsearch2(self, start:int,end:int, nums: List[int], target:int):
        while start<= end :
            mid = int((end+start)/2)

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid+1
            elif nums[mid] > target :
                end = mid-1
        return -1
    def search(self, nums: List[int], target: int) -> int:
        return self.binsearch2(0, len(nums)-1, nums, target)