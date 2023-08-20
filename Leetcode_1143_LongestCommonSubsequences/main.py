class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        t1len = len(text1)
        t2len = len(text2)
        dp = [[0 for _ in range(t1len+1)] for _ in range(t2len+1)]
        ret = 0

        for i in range(1,t2len+1) :
            for j in range(1,t1len+1) :
                if text1[j-1] == text2[i-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] )

                ret = max(ret,dp[i][j])

        return ret

def print_hi(name):
    test = Solution()
    print (test.longestCommonSubsequence("abcde", "ace"))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
