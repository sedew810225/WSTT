from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_two_sum(self):
        testcase = Solution()
        self.assertEqual([0,1], testcase.twoSum([2,7,11,15], 9))

    def test_two_sum2(self):
        testcase = Solution()
        self.assertEqual([1,2], testcase.twoSum([3,2,4], 6))

    def test_two_sum3(self):
        testcase = Solution()
        self.assertEqual([0,1], testcase.twoSum([3,3], 6))
