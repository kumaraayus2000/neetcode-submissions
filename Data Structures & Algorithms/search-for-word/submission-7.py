class Solution:

    def dfs(
        self,
        x: int,
        y: int,
        board: List[List[str]],
        word: str,
        index: int
    ) -> bool:

        # 1. If we go outside the board, this path is invalid.
        if x < 0 or y < 0 or x >= len(board) or y >= len(board[0]):
            return False

        # 2. Current board character must match
        #    the current character we are looking for in word.
        if board[x][y] != word[index]:
            return False

        # 3. If we matched the last character,
        #    we found the complete word.
        if index == len(word) - 1:
            return True

        # 4. Mark current cell as visited
        #    so we do not use the same cell twice in one path.
        temp = board[x][y]
        board[x][y] = "#"

        # 5. Explore all 4 directions for the next character.
        found = (
            self.dfs(x + 1, y, board, word, index + 1) or   # down
            self.dfs(x, y + 1, board, word, index + 1) or   # right
            self.dfs(x - 1, y, board, word, index + 1) or   # up
            self.dfs(x, y - 1, board, word, index + 1)      # left
        )

        # 6. Backtrack:
        #    restore the original character so this cell
        #    can be used in other paths.
        board[x][y] = temp

        return found


    def exist(self, board: List[List[str]], word: str) -> bool:

        # Try every cell as the starting point
        # because the word can begin anywhere.
        for i in range(len(board)):
            for j in range(len(board[0])):

                # Start searching from this cell
                # and try to match word[0].
                if self.dfs(i, j, board, word, 0):
                    return True

        # No starting point was able to form the word.
        return False