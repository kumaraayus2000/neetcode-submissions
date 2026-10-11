from typing import List


class Solution:

    def dfs(self, heights, visited, x, y):

        rows = len(heights)
        cols = len(heights[0])

        # Boundary check
        if (
            x < 0 or
            y < 0 or
            x >= rows or
            y >= cols
        ):
            return

        # If already visited, don't process again
        if (x, y) in visited:
            return

        # Mark current cell visited
        visited.add((x, y))

        directions = [
            (-1, 0),   # up
            (0, -1),   # left
            (0, 1),    # right
            (1, 0)     # down
        ]

        for dx, dy in directions:

            new_x = x + dx
            new_y = y + dy

            # Check boundary BEFORE accessing grid
            if (
                new_x < 0 or
                new_y < 0 or
                new_x >= rows or
                new_y >= cols
            ):
                continue

            # Already visited
            if (new_x, new_y) in visited:
                continue

            # Reverse DFS:
            # We can only move to same or higher height
            if heights[new_x][new_y] < heights[x][y]:
                continue

            self.dfs(
                heights,
                visited,
                new_x,
                new_y
            )


    def pacificAtlantic(
        self,
        heights: List[List[int]]
    ) -> List[List[int]]:

        rows = len(heights)
        cols = len(heights[0])

        pacific = set()
        atlantic = set()

        # Pacific touches TOP row
        for col in range(cols):
            self.dfs(heights, pacific, 0, col)

        # Pacific touches LEFT column
        for row in range(rows):
            self.dfs(heights, pacific, row, 0)

        # Atlantic touches BOTTOM row
        for col in range(cols):
            self.dfs(
                heights,
                atlantic,
                rows - 1,
                col
            )

        # Atlantic touches RIGHT column
        for row in range(rows):
            self.dfs(
                heights,
                atlantic,
                row,
                cols - 1
            )

        result = []

        # Cell must be reachable from BOTH oceans
        for x in range(rows):
            for y in range(cols):

                if (
                    (x, y) in pacific
                    and
                    (x, y) in atlantic
                ):
                    result.append([x, y])

        return result