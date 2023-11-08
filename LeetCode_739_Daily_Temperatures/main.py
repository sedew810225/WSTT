from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        len_temp = len(temperatures)
        result = [-1 for n in range(len_temp)]

        def checkNextWarm(cur: int, next: int, n: int):
            if temperatures[cur] < temperatures[next]:
                return next - cur
            else:
                if result[next] == 0:
                    return 0
                return checkNextWarm(cur, next + result[next], n)

        result[len_temp - 1] = 0

        for i in range(len_temp - 2, -1, -1):
            result[i] = checkNextWarm(i, i + 1, len_temp - 1)

        return result
