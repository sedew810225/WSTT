from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        a_list = []
        for ch in tokens:
            if ch in "+-*/":
                temp2 = a_list.pop()
                temp1 = a_list.pop()
                if ch == '+':
                    a_list.append(temp1 + temp2)
                elif ch == '-':
                    a_list.append(temp1 - temp2)
                elif ch == '*':
                    a_list.append(temp1 * temp2)
                elif ch == '/':
                    a_list.append(int(temp1 / temp2))
            else:
                a_list.append(int(ch))

        return a_list.pop()
