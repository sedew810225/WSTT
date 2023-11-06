from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_is_valid(self):
        testcase = Solution()
        self.assertEqual(True, testcase.isValid("()"))

    def test_is_valid1(self):
        testcase = Solution()
        self.assertEqual(True, testcase.isValid("()[]{}"))

    def test_is_valid2(self):
        testcase = Solution()
        self.assertEqual(False, testcase.isValid("(]"))


