from unittest import TestCase
from main import Solution
class TestSolution(TestCase):
    def test_search_matrix(self):
        testcase = Solution()
        self.assertEqual(True, testcase.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 3))

    def test2_search_matrix(self):
        testcase = Solution()
        self.assertEqual(False, testcase.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 13))

    def test3_search_matrix(self):
        testcase = Solution()
        self.assertEqual(False, testcase.searchMatrix([[1,1]], 0))

    def test4_search_matrix(self):
        testcase = Solution()
        self.assertEqual(False, testcase.searchMatrix([[1]], 2))

    def test5_search_matrix(self):
        testcase = Solution()
        self.assertEqual(True, testcase.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,50]], 11))

    def test6_search_matrix(self):
        testcase = Solution()
        self.assertEqual(True, testcase.searchMatrix([[1],[3]], 3))

    def test7_search_matrix(self):
        testcase = Solution()
        self.assertEqual(True, testcase.searchMatrix([[1],[3],[5]], 3))