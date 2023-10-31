from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_product_except_self(self):
        testcase = Solution()
        self.assertEqual([24,12,8,6], testcase.productExceptSelf([1,2,3,4]))
