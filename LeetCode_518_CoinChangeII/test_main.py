from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_change(self):
        testcase = Solution()
        self.assertEqual(4, testcase.change(5, [1,2,5]))

    def test1_change(self):
        testcase = Solution()
        self.assertEqual(0, testcase.change(3, [2]))

    def test2_change(self):
        testcase = Solution()
        self.assertEqual(1, testcase.change(10, [10]))

    def test3_change(self):
        testcase = Solution()
        self.assertEqual(2, testcase.change(100, [99,1]))