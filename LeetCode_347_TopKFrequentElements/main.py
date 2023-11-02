from typing import List
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        tempset = {}
        ret = []
        for num in nums:
            if not tempset.__contains__(num):
                tempset[num] = 1
            else:
                tempset[num] += 1

        sortedtemp = sorted(tempset.items(), key=lambda x:x[1], reverse=True)

        for i in range(k):
            ret.append(sortedtemp[i][0])

        return ret




