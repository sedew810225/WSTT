from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_min_eating_speed(self):
        testcase = Solution()
        self.assertEqual(4, testcase.minEatingSpeed([3,6,7,11],8))

    def test1_min_eating_speed(self):
        testcase = Solution()
        self.assertEqual(30, testcase.minEatingSpeed([30,11,23,4,20],5))

    def test2_min_eating_speed(self):
        testcase = Solution()
        self.assertEqual(23, testcase.minEatingSpeed([30,11,23,4,20],6))

    def test3_min_eating_speed(self):
        testcase = Solution()
        self.assertEqual(2, testcase.minEatingSpeed([312884470],312884469))
