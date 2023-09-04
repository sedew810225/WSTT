from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_fib(self):
        testcase = Solution()
        self.assertEqual(1, testcase.fib(2))

    def test2_fib(self):
        testcase = Solution()
        self.assertEqual(2, testcase.fib(3))

    def test3_fib(self):
        testcase = Solution()
        self.assertEqual(3, testcase.fib(4))