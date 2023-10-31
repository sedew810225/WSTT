from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_is_anagram(self):
        testcase = Solution()
        self.assertEqual(True, testcase.isAnagram("anagram", "nagaram"))

    def test_is_anagram2(self):
        testcase = Solution()
        self.assertEqual(False, testcase.isAnagram("rat", "cat"))
