from unittest import TestCase
from main import Solution

class Test(TestCase):
    def test1_solution(self):
        testcase1 = Solution()
        self.assertEqual(True, testcase1.wordBreak("leetcode", ["leet","code"]))

    def test2_solution(self):
        testcase2 = Solution()
        self.assertEqual(True, testcase2.wordBreak("applepenapple", ["apple","pen"]))

    def test3_solution(self):
        testcase3 = Solution()
        self.assertEqual(False, testcase3.wordBreak("catsandog", ["cats","dog","sand","and","cat"]))

    def test4_solution(self):
        testcase4 = Solution()
        self.assertEqual(True, testcase4.wordBreak("catsandogcat", ["cats","dog","sand","and","cat", "an"]))