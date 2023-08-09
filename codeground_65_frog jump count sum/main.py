import sys
# dt : stone status
# dp : partial shorted jump

def solution(N, stones, K):
    dt = [0 for _ in range(1000001)]
    dp = [-1 for _ in range(1000001)]

    dt[0] = 1
    dp[0] = 0
    idx_last = 0

    # update stone status from input string
    for stone in stones.split(' '):
        idx_stone = int(stone)
        dt[idx_stone] = 1
        idx_last = idx_stone

    # If frog can arrive current stone
    # compare all previous jumps result + 1 to current stone
    # and find minimum value
    for idx in range(1, idx_last+1):
        if dt[idx] == 1:
            for backStep in range(1, K+1):
                if idx-backStep >= 0 and dt[idx-backStep] == 1:
                    if dp[idx] == -1 :
                        dp[idx] = dp[idx - backStep] + 1
                    elif dp[idx - backStep]+1 < dp[idx] :
                        dp[idx] = dp[idx - backStep] + 1

    return dp[idx_last]

def greedy_solution(N, stones, K) :
    gap=0
    previousJumpLength=0
    jumpcnt=1
    idx_last = 0

    stonelist = [-1 for _ in range(1000001)]

    # get stone's position
    for stone in stones.split(' '):
        stonelist[idx_last] = int(stone)
        idx_last += 1

    for idx in range(0, idx_last+1) :
        # calculate the gab from previous stone
        if idx>0 :
            gap = stonelist[idx] - stonelist[idx-1]
        else :
            gap = stonelist[idx]

        # Error case handling
        if gap>K :
            return -1

        # Frog will jump to longest length always.
        # If current stone cannot be reached,
        # frog will try another jump from previous stone
        if (gap+previousJumpLength > K) :
            jumpcnt += 1
            previousJumpLength = gap
        else :
            previousJumpLength += gap

    return jumpcnt

def solution_allJumpCombination(N, stones, K):
    dt = [0 for _ in range(1000001)]
    dp = [0 for _ in range(1000001)]
    idx_last = 0

    #In this case, frog start from number 1 stone
    dt[0] = 0
    dp[0] = 0
    dt[1] = 1
    dp[1] = 1

    # update stone status from input string
    for stone in stones.split(' '):
        idx_stone = int(stone)
        dt[idx_stone] = 1
        idx_last = idx_stone

    for idx in range(2, idx_last+1):
        if dt[idx] == 1 :
            for backStep in range(1, K+1) :
                if idx-backStep >= 1 and dt[idx-backStep] == 1 :
                    if dp[idx] == -1 :
                        dp[idx] = dp[idx - backStep]
                    else :
                        dp[idx] += dp[idx - backStep]

    return dp[idx_last]