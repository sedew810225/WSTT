from unittest import TestCase
from main import Solution

class Test(TestCase):
    def test_solution(self):
        testcase1 = Solution()
        self.assertEqual(True, testcase1.canPartition([1,5,11,5]))

    def test2_solution(self):
        testcase1 = Solution()
        self.assertEqual(False, testcase1.canPartition([1,2,3,5]))

    def test3_solution(self):
        testcase1 = Solution()
        self.assertEqual(False, testcase1.canPartition([1,2,5]))

    def test4_solution(self):
        testcase1 = Solution()
        self.assertEqual(True, testcase1.canPartition([1,5,11,5]))