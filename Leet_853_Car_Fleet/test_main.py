from unittest import TestCase
from main import Solution
class TestSolution(TestCase):
    def test_car_fleet(self):
        testcase = Solution()
        self.assertEqual(3, testcase.carFleet(12, [10,8,0,5,3], [2,4,1,1,3]) )

    def test_car_fleet2(self):
        testcase = Solution()
        self.assertEqual(1, testcase.carFleet(10, [0,4,2], [2,1,3]) )
