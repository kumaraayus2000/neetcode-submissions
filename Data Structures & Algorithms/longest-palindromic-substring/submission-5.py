class Solution:
    def longestPalindrome(self, s: str) -> str:

        # reslen = length of longest palindrome found so far
        reslen = 0

        # res = actual longest palindromic substring
        res = ""

        # -----------------------------
        # Case 1: Odd-length palindrome
        # Example: "racecar", "aba"
        # -----------------------------
        for i in range(len(s)):

            # For odd-length palindrome,
            # center is a single character.
            l, r = i, i

            # Expand outward while:
            # 1. pointers are inside the string
            # 2. characters on both sides are equal
            while l >= 0 and r < len(s) and s[l] == s[r]:

                # Current palindrome length
                current_len = r - l + 1

                # Update answer if current palindrome is longer
                if current_len > reslen:
                    reslen = current_len
                    res = s[l:r + 1]

                # Expand outward from the center
                l -= 1
                r += 1


        # -----------------------------
        # Case 2: Even-length palindrome
        # Example: "abba", "aa"
        # -----------------------------
        for i in range(len(s)):

            # For even-length palindrome,
            # center is between i and i+1.
            l, r = i, i + 1

            # Expand outward while characters match
            while l >= 0 and r < len(s) and s[l] == s[r]:

                # Current palindrome length
                current_len = r - l + 1

                # Update longest palindrome
                if current_len > reslen:
                    reslen = current_len
                    res = s[l:r + 1]

                # Expand outward
                l -= 1
                r += 1

        return res