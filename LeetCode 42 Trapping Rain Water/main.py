from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        rt = 0
        n = len(height)
        heights_lt = [0] * n
        height_lt_max = 0
        heights_rt = [0] * n
        height_rt_max = 0

        #prev max of left
        for idx in range(n):
            heights_lt[idx] = height_lt_max
            height_lt_max = max(height_lt_max, height[idx])

        #prev max of right
        for idx in range(n-1, -1, -1):
            heights_rt[idx] = height_rt_max
            height_rt_max = max(height_rt_max, height[idx])

        for pmid in range(1, n-1):
            min_height = min(heights_lt[pmid], heights_rt[pmid])
            if min_height > height[pmid]:
                rt += min_height - height[pmid]

        return rt
