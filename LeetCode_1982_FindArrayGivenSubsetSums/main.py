import copy
from typing import List

class Solution:
    def checkN(self, index: int, selec: List[int], sums: List[int], checklist: List[int], subsum: int, checklen:int) -> bool :
        ret = False

        if index >= len(selec)-1:
            if checklist[checklen] == checklen:
                return True
            return False

        for i in range(index + 1, len(selec)):
            subsumtmp = subsum + selec[i]
            flag = 0

            for j in range(len(sums)):
                if checklist[j] == 1:
                    continue
                elif sums[j] == subsumtmp:
                    checklist[j] = 1
                    checklist[checklen] = checklist[checklen] + 1
                    flag = 1
                    ret = self.checkN(i, selec, sums, checklist, subsumtmp, checklen)
                    break
            if flag == 0:
                return False

        return ret

    def selectN(self, index: int, n: int, sums: List[int], checklist: List[int], selec: List[int], subsum:int, checklen:int) -> (List[int]):

        if n <= 0:
            for i in range(len(selec)):
                ret = self.checkN(i, selec, sums, checklist, selec[i], checklen)
                if ret:
                    return selec
            return []

        for j in range(index, len(sums)):
            selectmp = copy.deepcopy(selec)
            checklisttmp = copy.deepcopy(checklist)
            checklisttmp[j] = 1
            checklisttmp[checklen] = checklisttmp[checklen] + 1
            selectmp.append(sums[j])
            tmpsum = subsum + sums[j]

            result = self.selectN(j + 1, n - 1, sums, checklisttmp, selectmp, tmpsum, checklen)
            if result :
                return result

    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        #last array to save the matched number
        checklist = [0 for _ in range(len(sums)+1)]

        for i in range(len(sums)):
            if sums[i] == 0 and checklist[i] == 0:
                checklist[i] = 1
                break

        checklist[len(sums)] = 1

        return self.selectN(0, n, sums, checklist, [], 0, len(sums) )