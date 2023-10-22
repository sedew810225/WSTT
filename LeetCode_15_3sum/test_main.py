from unittest import TestCase
from main import Solution


class TestSolution(TestCase):
    def test_three_sum(self):
        testcase = Solution()
        self.assertEqual([[-1, -1, 2], [-1, 0, 1]], testcase.threeSum([-1, 0, 1, 2, -1, -4]))

    def test_three_sum2(self):
        testcase = Solution()
        self.assertEqual([], testcase.threeSum([0,1,1]))

    def test_three_sum3(self):
        testcase = Solution()
        self.assertEqual([[0,0,0]], testcase.threeSum([0,0,0]))