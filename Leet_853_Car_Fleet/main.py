from typing import List
from queue import PriorityQueue


class Solution:
    def carFleet2(self, target: int, position: List[int], speed: List[int]) -> int:

        que = PriorityQueue()

        for i in range(len(position)):
            que.put((position[i]*(-1), speed[i]))

        fleet = 0
        convey = 0

        while que.qsize() :
            (i, s) = que.get()
            i *= -1

            t = (target - i) / s

            if t > convey:
                fleet += 1
                convey = t

        return fleet

    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        pair = []
        for i in range(len(position)):
            pair.append((position[i], speed[i]))

        fleet = 0
        convey = 0

        for p, s in sorted(pair)[::-1]:
            t = (target - p) / s

            if t > convey:
                fleet += 1
                convey = t

        return fleet
