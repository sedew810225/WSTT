import copy
from typing import List

class Solution:
    def checkSum (self, i: int, candidates: List[int], sum: int, result: List[int], output: List[List[int]]):
        sum -= candidates[i]
        result.append(candidates[i])

        if sum == 0 :
            output.append(result)
        elif sum > 0 :
            prev = 0
            for j in range (i+1, len(candidates)) :
                if candidates[j] == prev :
                    continue
                else :
                    prev = candidates[j]
                    tempresult = copy.deepcopy(result)
                    self.checkSum(j, candidates, sum, tempresult, output)

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        output = []

        candidates.sort()
        prev = 0

        for i in range(len(candidates)) :
            midresult = []
            if candidates[i] == prev :
                continue
            else :
                prev = candidates[i]
                self.checkSum (i, candidates, target, midresult, output)

        return output