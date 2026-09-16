class Solution:

    def part(self, s: str, indx: int, path: List[str], result: List[List[str]]):

        # If we used the entire string,
        # store the current partition
        if indx == len(s):
            result.append(path.copy())
            return

        # Try every substring starting from indx
        for i in range(indx, len(s)):

            s1 = s[indx:i + 1]

            # Only continue if substring is palindrome
            if s1 == s1[::-1]:

                # Choose
                path.append(s1)

                # Explore from the next unused index
                self.part(s, i + 1, path, result)

                # Backtrack
                path.pop()


    def partition(self, s: str) -> List[List[str]]:
        result = []
        path = []

        self.part(s, 0, path, result)

        return result