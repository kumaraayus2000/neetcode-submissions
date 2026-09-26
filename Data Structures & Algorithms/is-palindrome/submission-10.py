class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = ""
        for i in range(len(s)):
            if (
                ('A' <= s[i] <= 'Z') or
                ('a' <= s[i] <= 'z') or
                ('0' <= s[i] <= '9')
            ):
                s1 = s1 + s[i].lower()

        return s1 == s1[::-1]