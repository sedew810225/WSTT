from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_search(self):
        testcase = Solution()
        self.assertEqual(4, testcase.search([-1,0,3,5,9,12], 9))

    def test2_search(self):
        testcase = Solution()
        self.assertEqual(-1, testcase.search([-1,0,3,5,9,12], 2))

    def test3_search(self):
        testcase = Solution()
        self.assertEqual(-1, testcase.search([-1,0,3,5,9,12], 13))