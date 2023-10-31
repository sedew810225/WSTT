class Solution:
    def isAnagram_bruteforce(self, s: str, t: str) -> bool:
        if sorted(s) == sorted(t):
            return True
        else:
            return False

    def isAnagram(self, s: str, t: str) -> bool:
        hashcnt = {}

        for tempchar in s:
            if hashcnt.__contains__(tempchar):
                hashcnt[tempchar] += 1
            else:
                hashcnt[tempchar] = 1

        for tempchar in t:
            if hashcnt.__contains__(tempchar):
                hashcnt[tempchar] -= 1
                if hashcnt[tempchar]==0:
                    hashcnt.pop(tempchar)
            else:
                return False

        if len(hashcnt)==0:
            return True
        else:
            return False
    def isAnagram_simple(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        letters = "abcdefghijklmnopqrstuvwxyz"
        for letter in letters:
            if s.count(letter) != t.count(letter):
                return False

        return True
