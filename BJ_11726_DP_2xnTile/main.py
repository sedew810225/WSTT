
#1. Check all available conditions in the problem
#2. define target solution using the conditions
#   - 2 way to fill the tile, 1x2 and 2x1
#       case 1 : adding 1x2 title for 1 array in n position, then the available count is dp[n-1]
#       case 2 : adding 2 2x1 title for 2 array in n position, then the available count is dp[n-2]
#       So, in n position, it can have case1 + case 2 ways

class Solution:
    def tiling(self, n:int) -> int:

        # Target solution is 'available number of filling tiles'
        dp = [0 for _ in range(n+1)]
        dp[0] = 0
        dp[1] = 1

        if n>=2:
            dp[2] = 2

        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]

        return dp[n] % 10007

def main():
    test1 = Solution()
    ret = test1.tiling(int(input()))
    print(ret)

if __name__ == "__main__":
    main()
