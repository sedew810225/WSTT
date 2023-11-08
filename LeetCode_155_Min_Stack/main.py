from typing import List

class MinStack:
    def __init__(self):
        self.minIndexList = []
        self.a_stack = []

    def push(self, val: int) -> None:
        lastIndex = len(self.a_stack) - 1
        if lastIndex == -1:
            self.minIndexList.append(0)
        else:
            minIndex = self.minIndexList[lastIndex]
            s_value = self.a_stack[lastIndex]
            if self.a_stack[minIndex] < s_value:
                self.minIndexList.append(minIndex)
            else:
                self.minIndexList.append(lastIndex)
        self.a_stack.append(val)

    def pop(self) -> None:
        self.a_stack.pop()
        self.minIndexList.pop()

    def top(self) -> int:
        return self.a_stack[-1]

    def getMin(self) -> int:
        minIndex = self.minIndexList[-1]
        return min(self.a_stack[-1], self.a_stack[minIndex])


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
