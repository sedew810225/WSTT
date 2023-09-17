from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_binary_search(self):
        testcase = Solution()
        self.assertEqual(1, testcase.findMin([3,4,5,1,2]))

    def test1_binary_search(self):
        testcase = Solution()
        self.assertEqual(0, testcase.findMin([4,5,6,7,0,1,2]))

    def test2_binary_search(self):
        testcase = Solution()
        self.assertEqual(11, testcase.findMin([11,13,15,17]))

    def test3_binary_search(self):
        testcase = Solution()
        self.assertEqual(1, testcase.findMin([2,1]))
