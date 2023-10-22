from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_two_sum(self):
        testcase = Solution()
        self.assertEqual([1,2], testcase.twoSum([2,7,11,15], 9))
