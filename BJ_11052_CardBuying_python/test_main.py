from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_cardbuying(self):
        testcase = Solution()
        self.assertEqual(10, testcase.cardbuying(4,[1,5,6,7]))

    def test2_cardbuying(self):
        testcase = Solution()
        self.assertEqual(50, testcase.cardbuying(5,[10, 9, 8, 7, 6]))

    def test2_cardbuying(self):
        testcase = Solution()
        self.assertEqual(55, testcase.cardbuying(10,[1, 1, 2, 3, 5, 8, 13, 21, 34, 55]))