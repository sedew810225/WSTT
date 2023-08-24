from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test1_longest_common_subsequence(self):
        testcase = Solution()
        self.assertEqual(3, testcase.longestCommonSubsequence("abcde", "ace"))

    def test2_longest_common_subsequence(self):
        testcase = Solution()
        self.assertEqual(3, testcase.longestCommonSubsequence("abc", "abc"))

    def test3_longest_common_subsequence(self):
        testcase = Solution()
        self.assertEqual(0, testcase.longestCommonSubsequence("abc", "def"))

    def test4_longest_common_subsequence(self):
        testcase = Solution()
        self.assertEqual(2, testcase.longestCommonSubsequence("ezupkr", "ubmrapg"))

    def test5_longest_common_subsequence(self):
        testcase = Solution()
        self.assertEqual(1, testcase.longestCommonSubsequence("bsbininm", "jmjkbkjkv"))

    def test6_longest_common_subsequence(self):
        testcase = Solution()
        self.assertEqual(4, testcase.longestCommonSubsequence("pmjghexybyrgzczy", "hafcdqbgncrcbihkd"))