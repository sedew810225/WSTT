from typing import List

class Solution:

    def binarySearch(self, nums :List[int], bgn :int, edn :int ) -> int:
        if edn == bgn :
            return nums[bgn]

        mid = (bgn+edn)//2

        if nums[bgn] <= nums[mid] <= nums[edn] :
            return nums[bgn]
        elif nums[bgn] >= nums[mid] < nums[edn] :
            edn = mid
        elif nums[bgn] <= nums[mid] > nums[edn] :
            bgn = mid+1

        return self.binarySearch(nums, bgn, edn)

    def findMin(self, nums: List[int]) -> int:
        return self.binarySearch(nums, 0, len(nums)-1)
