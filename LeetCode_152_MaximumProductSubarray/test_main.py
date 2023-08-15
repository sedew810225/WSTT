from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_max_product(self):
        testcase = Solution()
        self.assertEqual(6, testcase.maxProduct3([2,3,-2,4]))

    def test1_max_product(self):
        testcase = Solution()
        self.assertEqual(0, testcase.maxProduct3([-2,0,-1]))