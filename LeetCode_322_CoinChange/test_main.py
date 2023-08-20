from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test1_coin_change(self):
        testcase = Solution()
        self.assertEqual(3, testcase.coinChange([1,2,5], 11))

    def test2_coin_change(self):
        testcase = Solution()
        self.assertEqual(-1, testcase.coinChange([2], 3))

    def test3_coin_change(self):
        testcase = Solution()
        self.assertEqual(0, testcase.coinChange([1], 0))

    def test4_coin_change(self):
        testcase = Solution()
        self.assertEqual(2, testcase.coinChange([2], 4))