class Solution:

    def dfs(self,board:List[List[str]],x:int,y:int):
        rows = len(board)
        cols = len(board[0])

        if x<0 or y<0 or x>=rows or y>=cols:
            return

        if board[x][y]!="O":
            return

        board[x][y] = "T"

        directions = [
            (-1,0),
            (1,0),
            (0,-1),
            (0,1)
        ]

        for dx,dy in directions:
            new_x = x + dx
            new_y = y + dy

            self.dfs(board,new_x,new_y)


    def solve(self, board: List[List[str]]) -> None:
        rows = len(board)
        cols = len(board[0])

        for row in range(rows):
            if board[row][0] =="O":
                self.dfs(board,row,0)

            if board[row][cols-1]=="O":
                self.dfs(board,row,cols-1)

        for col in range(cols):
            if board[0][col]=="O":
                self.dfs(board,0,col)

            if board[rows-1][col]=="O":
                self.dfs(board,rows-1,col)
        
        for x in range(rows):
            for y in range(cols):
                if board[x][y]=="O":
                    board[x][y]="X"

                elif board[x][y] =="T":
                    board[x][y]="O"