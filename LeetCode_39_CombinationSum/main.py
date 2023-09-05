import copy
from typing import List


class Solution:
    def rec(self, index:int, sum:int, candidates:List[int], temp:List[int], output:List[List[int]]):
        for i in range(index, len(candidates)) :
            midList = copy.deepcopy(temp)
            midList.append(candidates[i])
            tempsum = sum - candidates[i]
            
            if tempsum == 0 :
                output.append (midList)
                break
            elif tempsum > 0 :
                self.rec(i, tempsum, candidates, midList, output)
            elif tempsum < 0 :
                break
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        output = []
        candidates.sort()

        self.rec(0,target, candidates,[], output)
        return output
