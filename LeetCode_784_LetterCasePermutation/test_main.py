from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_letter_case_permutation(self):
        testcase = Solution()
        self.assertEqual( ["a1b2","a1B2","A1b2","A1B2"] , testcase.letterCasePermutation("a1b2"))

    def test2_letter_case_permutation(self):
        testcase = Solution()
        self.assertEqual( ["c","C"] , testcase.letterCasePermutation("C"))
