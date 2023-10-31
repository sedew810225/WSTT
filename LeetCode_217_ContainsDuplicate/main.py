from typing import List
class Solution:
    def containsDuplicate_bruteforce(self, nums: List[int]) -> bool:
        hashtable = {}

        for num in nums:
            if hashtable.__contains__(num):
                return True
            hashtable[num] = 1

        return False

    def containsDuplicate(self, nums: List[int]) -> bool:

        if len(nums)==len(set(nums)):
            return False
        return True