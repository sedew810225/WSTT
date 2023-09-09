from typing import List
class Solution:

    def binSearch(self, matrix:List[List[int]], target:int, startnum:int, endnum:int , colcnt:int) -> bool:

        if (endnum < startnum) :
            return False

        mid = int((endnum+startnum)/2)
        col_mid = int(((endnum+startnum)/2)%colcnt)
        row_mid = int(((endnum+startnum)/2)/colcnt)

        if matrix[row_mid][col_mid] == target:
            return True
        elif matrix[row_mid][col_mid] < target:
            return self.binSearch(matrix, target, mid+1, endnum, colcnt)
        else:
            return self.binSearch( matrix, target, startnum, mid-1, colcnt)

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        rowcnt = len(matrix)
        colcnt = len(matrix[0])
        endindex = rowcnt*colcnt-1

        return self.binSearch( matrix, target, 0, endindex, colcnt)


