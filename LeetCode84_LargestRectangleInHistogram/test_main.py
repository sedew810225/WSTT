from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_largest_rectangle_area(self):
        testcase = Solution()
        self.assertEqual(10, testcase.largestRectangleArea([2,1,5,6,2,3]))

    def test_largest_rectangle_area(self):
        testcase = Solution()
        self.assertEqual(4, testcase.largestRectangleArea([2,4]))

    def test_largest_rectangle_area(self):
        testcase = Solution()
        self.assertEqual(2, testcase.largestRectangleArea([1,1]))