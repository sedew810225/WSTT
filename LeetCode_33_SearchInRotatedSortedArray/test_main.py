from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_search(self):
        testcase = Solution()
        self.assertEqual(4, testcase.search([4,5,6,7,0,1,2], 0))

    def test1_search(self):
        testcase = Solution()
        self.assertEqual(-1, testcase.search([4,5,6,7,0,1,2], 3))

    def test2_search(self):
        testcase = Solution()
        self.assertEqual(-1, testcase.search([1], 0))