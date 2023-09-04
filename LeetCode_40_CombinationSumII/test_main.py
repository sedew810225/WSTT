from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_combination_sum2(self):
        testcase = Solution()
        self.assertEqual([[1,1,6],[1,2,5],[1,7],[2,6]], testcase.combinationSum2([10,1,2,7,6,1,5], 8))

    def test2_combination_sum2(self):
        testcase = Solution()
        self.assertEqual([[1,2,2],[5]], testcase.combinationSum2([2,5,2,1,2], 5))
