from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_letter_case_permutation(self):
        testcase = Solution()
        self.assertEqual( set(["a1b2","a1B2","A1b2","A1B2"]) , set(testcase.letterCasePermutation("a1b2")))

    def test2_letter_case_permutation(self):
        testcase = Solution()
        self.assertEqual( set(["c","C"]) , set(testcase.letterCasePermutation("C")))
