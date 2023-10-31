from typing import List
class Solution:
    def longestConsecutive_sort(self, nums: List[int]) -> int:
        #sort will not meet the time complexity requirement
        nums.sort()
        seqlength = 0
        maxlength = 0
        tempnum = 0

        for num in nums:
            if seqlength == 0:
                seqlength = 1
            else:
                if num - tempnum == 1:
                    seqlength += 1
                elif num - tempnum > 1:
                    seqlength = 1
                #if they are same, skip

            tempnum = num
            if seqlength > maxlength:
                maxlength = seqlength

        return maxlength

    def longestConsecutive(self, nums: List[int]) -> int:
        hashtable = {}
        maxcnt = 0

        for num in nums:
            hashtable[num] = 0

        for i in range(len(nums)):
            cnt = 1

            if hashtable[nums[i]] == 1:
                continue
            hashtable[nums[i]] = 1

            #left
            idx = 1
            while hashtable.__contains__(nums[i]-idx):
                hashtable[nums[i]-idx] = 1
                idx += 1
                cnt += 1

            #right
            idx = 1
            while hashtable.__contains__(nums[i]+idx):
                hashtable[nums[i] + idx] = 1
                idx += 1
                cnt += 1

            if cnt > maxcnt:
                maxcnt = cnt

        return maxcnt
