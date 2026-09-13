class Solution:

    def isSafe(self,row,col,board,n):
        r = row
        while r>=0:
            if board[r][col] == "Q":
                return False
            r-=1

        r=row
        c=col
        while r>=0 and c>=0:
            if board[r][c]=="Q":
                return False
            r-=1
            c-=1
        
        r=row
        c=col
        while r>=0 and c<n:
            if board[r][c]=="Q":
                return False
            r-=1
            c+=1
        return True

    def solve(self,row,board,ans,n):
        if row == n:
            temp = []

            for i in range(n):
                temp.append("".join(board[i]))

            ans.append(temp)
            return

        for col in range(n):

            if self.isSafe(row,col,board,n):
                board[row][col]="Q"

                self.solve(row+1,board,ans,n)

                board[row][col]="."


    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []

        board = [["."] * n for _ in range(n)]

        self.solve(0,board,ans,n)

        return ans