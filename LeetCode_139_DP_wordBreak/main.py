import sys
from typing import List
class Solution:

    # Record checked result to reuse
    memo = [[-1 for _ in range(301)] for _ in range(301) ]
    def checkWord(self, start:int, end:int, s:str, wordDict: List[str]) -> bool:

        # if it's checked already, return result
        if self.memo[start][end] == 1 :
            return True
        if self.memo[start][end] == 0 :
            return False

        # if it's not checked before, check from here
        for word in wordDict:
            if word == s[start:end+1]:
                self.memo[start][end] = 1
                print(start, "-", end, "=", s[start:end + 1])
                return True

        # current str is not in the dict
        self.memo[start][end] = 0

        # end condition for the recursion
        if start == end:
                return False

        #if it's not matched, slice all available sub-strings
        for i in range(start, end):
            ret1 = self.checkWord(start, i, s, wordDict)
            ret2 = self.checkWord(i+1, end, s, wordDict)
            #print(s[start:i + 1], "-", s[i + 1:end + 1])

            if (ret1 == True) and (ret2 == True):
                # combined path should be set true also !!!!
                self.memo[start][end] = 1
                return True

        return False

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        # initialize global array
        for i in range(len(self.memo)):
            for j in range(len(self.memo[i])):
                self.memo[i][j] = -1

        ret = self.checkWord(0, len(s)-1, s, wordDict)
        #print (ret)
        return ret

class Solution2:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        # Dp = True if some segment is one or more dictionary words
        dp = [0 for _ in range(len(s)+1)]
        dp[0] = 1

        # There will be previous true segments in dp
        # If the next char of those segment are in the dictionary, previous segment + len(new word) is True
            # It can have multiple match with starting the char
        # If dp[len(str)] is true, that means done

        for i in range (len(s)+1):
            if dp[i] == 1 :
                #find the next starting letter from dic
                for word in wordDict :
                 if word[0] == s[i] :
                     if i+len(word) > len(s):
                         continue

                #if there is matched word, update dp
                     if word == s[i:i+len(word)]:
                         dp[i+len(word)] = 1

            if dp[len(s)] == 1:
                return True