from typing import List
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i=0
        j=len(numbers)-1

        while 1:
            twosum = numbers[i]+numbers[j]

            if twosum > target:
                j -= 1
            elif twosum < target:
                i += 1
            else:
                return [i+1, j+1]