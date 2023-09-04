import copy
from typing import List

class Solution:
    def checkSum (self, i: int, candidates: List[int], sum: int, result: List[int], output: List[List[int]]):

        prev = 0
        for j in range (i, len(candidates)) :
            if candidates[j] == prev :
                continue
            else :
                prev = candidates[j]
                tempsum = sum - candidates[j]
                tempresult = copy.deepcopy(result)

                if tempsum == 0:
                    tempresult.append(candidates[j])
                    output.append(tempresult)
                elif tempsum > 0:
                    tempresult.append(candidates[j])
                    self.checkSum(j+1, candidates, tempsum, tempresult, output)
                else :
                    prev = 0
                    break

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        output = []
        midresult = []

        candidates.sort()
        self.checkSum (0, candidates, target, midresult, output)

        return output