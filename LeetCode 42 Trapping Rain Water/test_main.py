from unittest import TestCase
from main import Solution


class TestSolution(TestCase):
    def test_trap(self):
        testcase = Solution()
        self.assertEqual(6, testcase.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))

    def test_trap2(self):
        testcase = Solution()
        self.assertEqual(9, testcase.trap([4,2,0,3,2,5]))
