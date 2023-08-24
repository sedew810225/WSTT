from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_unique_paths(self):
        testcase = Solution()
        self.assertEqual(28, testcase.uniquePaths(3,7))

    def test2_unique_paths(self):
        testcase = Solution()
        self.assertEqual(3, testcase.uniquePaths(3,2))
