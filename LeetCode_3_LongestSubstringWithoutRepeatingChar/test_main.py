from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_length_of_longest_substring(self):
        testcase = Solution()
        self.assertEqual(3, testcase.lengthOfLongestSubstring("abcabcbb"))

    def test_length_of_longest_substring2(self):
        testcase = Solution()
        self.assertEqual(2, testcase.lengthOfLongestSubstring("abba"))