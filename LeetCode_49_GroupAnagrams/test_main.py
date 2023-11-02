from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_group_anagrams(self):
        testcase = Solution()
        self.assertEqual([["bat"],["nat","tan"],["ate","eat","tea"]], testcase.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
