class Solution:

    def part(self, digits, mp, ind, current, res):
        # Base case:
        # If we have processed all digits,
        # current contains one complete combination.
        if ind == len(digits):
            res.append(current)
            return

        # Get all possible letters for the current digit.
        # Example: if digits[ind] == "2",
        # l1 = "abc"
        l1 = mp[digits[ind]]

        # Try every possible letter for this digit.
        for ch in l1:
            # Choose current letter and move to the next digit.
            #
            # We use current + ch because strings are immutable.
            # This creates a new string, so no explicit pop/backtrack
            # is needed after the recursive call.
            self.part(
                digits,
                mp,
                ind + 1,
                current + ch,
                res
            )

    def letterCombinations(self, digits: str) -> List[str]:
        # If no digits are given, there are no combinations.
        if not digits:
            return []

        # Phone keypad mapping.
        mp = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }

        # Stores all final combinations.
        res = []

        # Start backtracking from index 0
        # with an empty current string.
        self.part(digits, mp, 0, "", res)

        return res