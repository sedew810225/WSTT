from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        subgroupcnt = 0
        maxareasize = 0

        for item in heights:

            while len(stack) > 0 and stack[-1][0] >= item:
                (height, cnt) = stack.pop()
                temp = height * (cnt + subgroupcnt)
                if temp > maxareasize:
                    maxareasize = temp
                subgroupcnt += cnt
            subgroupcnt += 1

            stack.append([item, subgroupcnt])
            subgroupcnt = 0

        while len(stack) :
            (height, cnt) = stack.pop()
            temp = height * (cnt + subgroupcnt)
            if temp > maxareasize:
                maxareasize = temp
            subgroupcnt += cnt

        return maxareasize