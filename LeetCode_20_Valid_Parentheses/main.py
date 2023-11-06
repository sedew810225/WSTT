class Solution:
    def isValid(self, s: str) -> bool:

        if len(s) % 2 != 0:
            return False

        a_list = []
        ret = False

        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                a_list.append(ch)
            else:
                if len(a_list) == 0:
                    return False

                temp = a_list.pop()
                if (ch == ')' and temp == '(') \
                        or (ch == '}' and temp == '{') \
                        or (ch == ']' and temp == '['):
                    ret = True
                    continue
                else:
                    return False

        return len(a_list) == 0
