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

    def binSearch2_col(self, matrixcol: List[int], target: int, startnum: int, endnum: int) -> bool:

        if endnum < startnum:
            return False

        mid_col = int((startnum+endnum)/2)

        if matrixcol[mid_col] == target:
            return True
        elif matrixcol[mid_col] < target:
            startnum = mid_col+1
        elif matrixcol[mid_col] > target:
            endnum = mid_col-1

        return self.binSearch2_col(matrixcol, target, startnum, endnum)

    def binSearch2_row(self, matrix: List[List[int]], target: int, startnum: int, endnum: int) -> bool:

        if endnum < startnum:
            return False

        mid_row = int((startnum+endnum)/2)
        mid_len = len(matrix[mid_row])-1

        if matrix[mid_row][0] <= target <= matrix[mid_row][mid_len]:
            return self.binSearch2_col(matrix[mid_row], target, 0, mid_len)
        elif target < matrix[mid_row][0]:
            endnum = mid_row -1
        elif target > matrix[mid_row][len(matrix[mid_row])-1]:
            startnum = mid_row+1

        return self.binSearch2_row(matrix, target, startnum, endnum)


    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        #rowcnt = len(matrix)
        #colcnt = len(matrix[0])
        #endindex = rowcnt*colcnt-1
        #return self.binSearch(matrix, target, 0, endindex, colcnt)

        return self.binSearch2_row(matrix, target, 0, len(matrix)-1)