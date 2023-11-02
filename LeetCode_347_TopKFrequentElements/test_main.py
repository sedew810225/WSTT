from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_top_kfrequent(self):
        testcase = Solution()
        self.assertEqual([1,2], testcase.topKFrequent([3,1,1,2,2], 2))
