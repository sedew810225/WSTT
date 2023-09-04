from typing import List

class Solution:

    def rec (self, depth:int, idxStart:int, prevdt:List[int], nums:List[int] , output, visited:List[int]) -> int:
        depth -= 1   #stop condition

        for i in range(idxStart, len(nums)):
            tempdt = prevdt.copy()
            tempdt.append(nums[i])

            if  visited[i] != 1 :
                visited[i] = 1
                output.append( [nums[i]] )

            if depth > 0 :
                self.rec(depth, i+1, tempdt, nums, output, visited)
            else :
                output.append(tempdt)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        output = [[]]
        visited = [0 for _ in range(len(nums))]

        for depth in range(2,len(nums)+1):
            self.rec(depth, 0, [], nums, output, visited)

        return output

