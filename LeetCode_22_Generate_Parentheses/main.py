from typing import List


class Solution:

    def generateParenthesis(self, n: int) -> List[str]:

        result = []
        def addMore(aStack: str, lcnt: int, rcnt: int, n: int):

            if n == lcnt == rcnt:
                result.append(aStack)
                return

            if lcnt < n or lcnt == rcnt:
                addMore(aStack + '(', lcnt + 1, rcnt, n)

            if rcnt < n and lcnt != rcnt and lcnt > rcnt:
                addMore(aStack + ')', lcnt, rcnt + 1, n)

        addMore("(", 1, 0, n)
        return result
