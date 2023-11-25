from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_max_profit(self):
        testcase = Solution()
        self.assertEqual(5, testcase.maxProfit([7,1,5,3,6,4]))
