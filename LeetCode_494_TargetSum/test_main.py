from unittest import TestCase
from main import Solution

class TestSolution(TestCase):

    def test_change(self):
        testcase = Solution()
        self.assertEqual(5, testcase.findTargetSumWays([1,1,1,1,1],3))

    def test1_change(self):
        testcase = Solution()
        self.assertEqual(1, testcase.findTargetSumWays([1],1))

    def test2_change(self):
        testcase = Solution()
        self.assertEqual(1, testcase.findTargetSumWays([1000],-1000))

    def test3_change(self):
        testcase = Solution()
        self.assertEqual(256, testcase.findTargetSumWays([0,0,0,0,0,0,0,0,1],1))