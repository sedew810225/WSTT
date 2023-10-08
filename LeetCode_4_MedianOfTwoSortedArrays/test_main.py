from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_find_median_sorted_arrays(self):
        testcase = Solution()
        self.assertEqual(2.0, testcase.findMedianSortedArrays([1,3], [2]))

    def test2_find_median_sorted_arrays(self):
        testcase = Solution()
        self.assertEqual(2.5, testcase.findMedianSortedArrays([1,2], [3,4]))