
class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows = len(grid)
        cols = len(grid[0])

        q = deque()

        for x in range(rows):
            for y in range(cols):
                if grid[x][y]==0:
                    q.append((x,y))


        directions = [
            (1,0),
            (-1,0),
            (0,-1),
            (0,1)
        ]

        while q:
            x,y = q.popleft()

            for dx,dy in directions:
                new_x = x + dx
                new_y = y + dy

                if (
                    new_x <0 or
                    new_y <0 or
                    new_x >=rows or
                    new_y >=cols
                ):
                    continue

                if grid[new_x][new_y] != 2147483647:
                    continue

                grid[new_x][new_y] = grid[x][y] + 1

                q.append((new_x,new_y))

