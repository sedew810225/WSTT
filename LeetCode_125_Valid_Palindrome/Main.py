class Solution:
    def isPalindrome(self, s: str) -> bool:
        len_s = len(s)
        front_index = 0
        end_index = len_s-1

        while front_index <= end_index:

            while not(s[front_index].isalnum()):
                front_index += 1
                if front_index >= len_s:
                    return True

            while not(s[end_index].isalnum()):
                end_index -= 1
                if end_index < 0:
                    return True

            if s[front_index].lower() != s[end_index].lower():
                return False

            front_index += 1
            end_index -= 1
            
        return True

