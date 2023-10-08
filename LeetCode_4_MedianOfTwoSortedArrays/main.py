from typing import List

class Solution:
    def countList(self, nums1: List[int], nums2: List[int], nums1len: int, nums2len: int, odd: int, target: int) -> float:
        j = 0
        k = 0
        temp1 = 0.0
        temp2 = 0.0

        for i in range(target+1):
            temp2 = temp1
            if j >= nums1len :
                temp1 = nums2[k]
                k = k+1
            elif k >= nums2len :
                temp1 = nums1[j]
                j = j+1
            elif nums1[j] <= nums2[k]:
                temp1 = nums1[j]
                j = j+1
            else:
                temp1 = nums2[k]
                k = k+1

        if odd == 1:
            return temp1
        else:
            return (temp1+temp2)/2


    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1len = len(nums1)
        nums2len = len(nums2)
        odd = (nums1len + nums2len) % 2
        target = (nums1len + nums2len) // 2

        return self.countList(nums1, nums2, nums1len, nums2len, odd, target)