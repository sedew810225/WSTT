from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_rec(self):
        testcase = Solution()
        self.assertEqual([[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]], testcase.subsets([1,2,3]))
