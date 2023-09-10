from unittest import TestCase
from main import Solution

class TestSolution(TestCase):
    def test_recover_array(self):
        testcase = Solution()
        self.assertEqual( set([1,2,-3]) or set([3,-2,-1]) , set(testcase.recoverArray(3, [-3,-2,-1,0,0,1,2,3])) )

    def test2_recover_array(self):
        testcase = Solution()
        self.assertEqual( set([0,0]), set(testcase.recoverArray(2, [0,0,0,0])) )

    def test3_recover_array(self):
        testcase = Solution()
        self.assertEqual( set([0,-1,4,5]), set(testcase.recoverArray(4, [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8])) )

    def test4_recover_array(self):
        testcase = Solution()
        self.assertEqual( set([354,883,787,397,-48]), set(testcase.recoverArray(5, [1586,1093,835,1184,354,1232,751,0,2067,2373,1189,1136,2421,1670,2019,1490,349,1280,1141,2024,883,306,787,703,397,1538,1237,1976,739,-48,1622,1634])) )

    def test5_recover_array(self):
        testcase = Solution()
        self.assertEqual( set([354,883,787,397,-48]), set(testcase.recoverArray(5, [1586,1093,835,1184,354,1232,751,0,2067,2373,1189,1136,2421,1670,2019,1490,349,1280,1141,2024,883,306,787,703,397,1538,1237,1976,739,-48,1622,1634])) )
