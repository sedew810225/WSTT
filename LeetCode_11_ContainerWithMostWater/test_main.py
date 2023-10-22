from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_max_area(self):
        testcase = Solution()
        self.assertEqual(49, testcase.maxArea([1,8,6,2,5,4,8,3,7]))
