from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_eval_rpn(self):
        testcase = Solution()
        self.assertEqual(9, testcase.evalRPN(["2","1","+","3","*"]))

    def test_eval_rpn1(self):
        testcase = Solution()
        self.assertEqual(6, testcase.evalRPN(["4","13","5","/","+"]))
