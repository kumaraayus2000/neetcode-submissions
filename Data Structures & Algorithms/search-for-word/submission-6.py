class Solution:

    def dfs(self, x:int,y:int, board:List[List[str]], word:str,index:int)->bool:
        
        if x<0 or y<0 or x>= len(board) or y>=len(board[0]):
            return False

        if board[x][y] != word[index]:
            return False

        if index == len(word)-1:
            return True

        temp = board[x][y]
        board[x][y] = "#"
        found = (
            self.dfs(x+1,y,board,word,index+1) or
            self.dfs(x,y+1,board,word,index+1) or
            self.dfs(x-1,y,board,word,index+1) or
            self.dfs(x,y-1,board,word,index+1)
         )

        board[x][y] = temp
        return found


    def exist(self, board: List[List[str]], word: str) -> bool:
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(i,j,board,word,0):
                    return True

        return False