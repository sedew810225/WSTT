from unittest import TestCase
from main import solution, greedy_solution, solution_allJumpCombination

class Test(TestCase):
    def test1_solution(self):
        self.assertEqual(5, solution(8, '1 2 5 7 9 10 12 15', 4))

    def test2_solution(self):
        self.assertEqual(5, greedy_solution(8, '1 2 5 7 9 10 12 15', 4))

    def test1_solution_sum(self):
        self.assertEqual(3, solution_allJumpCombination(3, '1 2 3', 2))