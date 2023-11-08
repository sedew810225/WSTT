from typing import List


class Solution:
    def dailyTemperatures2(self, temperatures: List[int]) -> List[int]:
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

    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        len_temp = len(temperatures)
        result = [0] * len_temp
        stack = []

        for i in range(len_temp):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                index = stack.pop()
                result[index] = i - index
            stack.append(i)
        return result
