from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_subsets_with_dup(self):
        testcase = Solution()
        self.assertEqual([[],[1],[1,2],[1,2,2],[2],[2,2]], testcase.subsetsWithDup([1,2,2]))

    def test1_subsets_with_dup(self):
        testcase = Solution()
        self.assertEqual([[],[0]], testcase.subsetsWithDup([0]))
