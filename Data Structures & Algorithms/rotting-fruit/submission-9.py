from collections import deque

class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:

        rows = len(grid)
        cols = len(grid[0])

        q = deque()
        fresh = 0

        # Find all rotten oranges
        # and count all fresh oranges
        for i in range(rows):
            for j in range(cols):

                if grid[i][j] == 2:
                    q.append((i, j))

                elif grid[i][j] == 1:
                    fresh += 1

        # No fresh oranges
        if fresh == 0:
            return 0

        minutes = 0

        directions = [
            (1, 0),
            (-1, 0),
            (0, 1),
            (0, -1)
        ]

        # Continue while we still have rotten oranges
        # that can spread and fresh oranges remain
        while q and fresh > 0:

            level = len(q)

            # Process one full minute
            for _ in range(level):

                x, y = q.popleft()

                for dx, dy in directions:

                    new_x = x + dx
                    new_y = y + dy

                    # Boundary check
                    if (
                        new_x < 0 or
                        new_y < 0 or
                        new_x >= rows or
                        new_y >= cols
                    ):
                        continue

                    # Only fresh oranges can become rotten
                    if grid[new_x][new_y] != 1:
                        continue

                    # Rot the orange
                    grid[new_x][new_y] = 2

                    fresh -= 1

                    # Newly rotten orange can spread next minute
                    q.append((new_x, new_y))

            # One BFS level = one minute
            minutes += 1

        # If fresh oranges remain,
        # they were unreachable
        if fresh > 0:
            return -1

        return minutes