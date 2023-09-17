import math
from typing import List

class Solution:
    def timeCheck(self, piles: List[int], k: int) -> int:
        eatingTime = 0
        for pile in piles:
            eatingTime = eatingTime + math.ceil(pile/k)
        return eatingTime

    def findSlowtime(self, piles: List[int], lt: int, rt: int, h: int) -> int:
        if rt <= lt :
            return lt

        mid = (lt + rt) // 2
        mid_time = self.timeCheck(piles, mid)

        if h >= mid_time:
            rt = mid
        elif h < mid_time:
            lt = mid+1

        return self.findSlowtime(piles, lt, rt, h)

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        return self.findSlowtime(piles, 1, max(piles), h)
