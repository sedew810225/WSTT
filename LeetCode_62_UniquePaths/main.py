from typing import List

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        dp = [[1 for _ in range(n)] for _ in range(m)]

        for i in range(1,m) :
            for j in range(1,n) :
                dp[i][j] = dp[i][j-1] + dp[i-1][j]

        return dp[m-1][n-1]


def print_hi():
    test = Solution()
    m = int(input())
    n = int(input())
    print(test.uniquePaths(m,n))

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
