from typing import List

class Solution :
    def cardbuying(self, num:int, price:List[int]) -> int:

        dp = [0 for _ in range(len(price))]
        dp[0] = price[0]

        #dp[5] = max ( p5, 4+0, 3+1, 2+2 )
        for i in range (1, num) :
            dp[i] = price[i]
            for j in range (i,int(i/2),-1) :
                dp[i] = max(dp[i], dp[j-1] + dp[i-j])

        return dp[num-1]

def main():
    # Use a breakpoint in the code line below to debug your script.
    test = Solution()
    cardnum = int(input())
    priceString = str(input()).split(' ')
    priceList = list(map(int, priceString))
    ret = test.cardbuying(cardnum , priceList)
    print (ret)

if __name__ == '__main__':
    main()
