from unittest import TestCase
from typing import List
from main import MinStack


class TestMinStack(TestCase):
    def test(self, input, data) -> List:
        obj = MinStack()
        result = []
        idx = 0
        for cmd in input:
            if cmd == "MinStack":
                obj.__init__()
                result.append(None)
            elif cmd == "push":
                obj.push(data[idx])
                result.append(None)
            elif cmd == "pop":
                result.append(obj.pop())
            elif cmd == "getMin":
                result.append(obj.getMin())
            elif cmd == "top":
                result.append(obj.top())
            idx += 1
        return result
    def test_eval_rpn(self):
        input = ["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
        data = list([[], [-2], [0], [-3], [], [], [], []])
        self.assertEqual([None, None, None, None, -3, None, 0, -2], self.test(input, data))

    def test_eval_rpn2(self):
        null = None
        input = ["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
        data = list([[],[2],[0],[3],[0],[],[],[],[],[],[],[]])
        self.assertEqual([null,null,null,null,null,0,null,0,null,0,null,2], self.test(input, data))
