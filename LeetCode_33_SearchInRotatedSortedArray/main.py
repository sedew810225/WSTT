from typing import List
class Solution:

    def isReversed(self, nums: List[int], bgn: int, edn: int) -> bool:
        if nums[bgn] <= nums[edn] :
            return False
        else :
            return True
    def binarySearch(self, target: int, nums: List[int], bgn: int, edn: int) -> int:
        if bgn > edn:
            return -1
        elif bgn == edn :
            if nums[bgn] == target :
                return bgn
            else :
                return -1

        if ((self.isReversed(nums, bgn, edn) and (nums[bgn] <= target or target <= nums[edn]))
                or (not(self.isReversed(nums, bgn, edn)) and (nums[bgn] <= target <= nums[edn]))):
            mid = (bgn+edn)//2

            if ((self.isReversed(nums, bgn, mid) and (nums[bgn] <= target or target <= nums[mid]))
                    or (not(self.isReversed(nums, bgn, mid)) and (nums[bgn] <= target <= nums[mid]))):
                return self.binarySearch(target, nums, bgn, mid)

            elif ((self.isReversed(nums, mid, edn) and (nums[mid] < target or target <= nums[edn]))
                  or (not(self.isReversed(nums, mid, edn)) and (nums[mid] < target <= nums[edn]))):
                return self.binarySearch(target, nums, mid+1, edn)

            else :
                return -1

        else :
            return -1


    def search(self, nums: List[int], target: int) -> int:
        return self.binarySearch(target, nums, 0, len(nums)-1)
