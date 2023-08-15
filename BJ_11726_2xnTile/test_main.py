from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test1_tiling(self):
        testcase = Solution()
        self.assertEqual(2, testcase.tiling(2))
    def test2_tiling(self):
        testcase = Solution()
        self.assertEqual(1, testcase.tiling(1))
    def test3_tiling(self):
        testcase = Solution()
        self.assertEqual(55, testcase.tiling(9))