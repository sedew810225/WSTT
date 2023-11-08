from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_generate_parenthesis(self):
        testcase = Solution()
        self.assertEqual(["((()))","(()())","(())()","()(())","()()()"], testcase.generateParenthesis(3))
