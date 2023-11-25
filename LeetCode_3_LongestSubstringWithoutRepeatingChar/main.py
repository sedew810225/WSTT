class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        aDict = {}
        startIdx = 0
        maxlen = 0

        for i in range(len(s)):
            if aDict.__contains__(s[i]):
                startIdx = max(startIdx, aDict[s[i]] + 1)

            aDict[s[i]] = i
            maxlen = max(maxlen, i - startIdx + 1)

        return maxlen