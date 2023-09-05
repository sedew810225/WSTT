from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_combination_sum(self):
        testcase = Solution()
        self.assertEqual([[2,2,3],[7]], testcase.combinationSum([2,3,6,7], 7))
    def test2_combination_sum(self):
        testcase = Solution()
        self.assertEqual([[2,2,2,2],[2,3,3],[3,5]], testcase.combinationSum([2,3,5], 8))
    def test3_combination_sum(self):
        testcase = Solution()
        self.assertEqual([], testcase.combinationSum([2], 1))

    def test4_combination_sum(self):
        testcase = Solution()
        self.assertEqual([[8,3],[7,4],[4,4,3]], testcase.combinationSum([8,7,4,3], 11))