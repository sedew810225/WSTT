import copy
from typing import List

class Solution:
    def rec(self, i:int, result:str , output:List[str]):
        if i > len(result) :
            return

        output.append(result)

        for j in range(i, len(result)):
            tempresult = copy.deepcopy(result)

            if tempresult[j].isalpha() == False :
                continue

            temp = tempresult[j]

            if temp.islower() == True :
                tempresult = list(tempresult)
                tempresult[j] = temp.upper()
                tempresult = ''.join(tempresult)
            else :
                tempresult = list(tempresult)
                tempresult[j] = temp.lower()
                tempresult = ''.join(tempresult)

            self.rec(j+1,tempresult, output)


    def letterCasePermutation(self, s: str) -> List[str]:
        output = []
        self.rec(0, s, output)
        return output
