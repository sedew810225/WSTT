from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_longest_consecutive(self):
        testcase = Solution()
        self.assertEqual(4, testcase.longestConsecutive([100,4,200,1,3,2]))

    def test_longest_consecutive1(self):
        testcase = Solution()
        self.assertEqual(9, testcase.longestConsecutive([0,3,7,2,5,8,4,6,0,1]))
