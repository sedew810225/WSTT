from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_contains_duplicate(self):
        testcase = Solution()
        self.assertEqual(True, testcase.containsDuplicate([1,2,3,1]))
