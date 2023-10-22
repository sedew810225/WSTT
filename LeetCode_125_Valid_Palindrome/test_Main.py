from unittest import TestCase
from Main import Solution

class TestSolution(TestCase):
    def test_is_palindrome(self):
        testcase = Solution()
        self.assertEqual(True, testcase.isPalindrome("A man, a plan, a canal: Panama"))

    def test_is_palindrome2(self):
        testcase = Solution()
        self.assertEqual(False, testcase.isPalindrome("race a car"))

    def test_is_palindrome3(self):
        testcase = Solution()
        self.assertEqual(True, testcase.isPalindrome(" "))

    def test_is_palindrome4(self):
        testcase = Solution()
        self.assertEqual(False, testcase.isPalindrome("0P"))