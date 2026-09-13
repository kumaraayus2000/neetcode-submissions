class Solution {
public:

    int dfs(int x,int y, int n,int m, vector<vector<int>>& grid){
        
        if(x<0 || y<0 || x>=n || y>=m){
            return 0;
        }

        if(grid[x][y]==1){
            grid[x][y]=0;
          return 1 + dfs(x+1,y,n,m,grid)+
            dfs(x-1,y,n,m,grid)+
            dfs(x,y-1,n,m,grid)+
            dfs(x,y+1,n,m,grid);
        }

    return 0;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m= grid[0].size();
        int max1= 0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                max1=max(max1,dfs(i,j,n,m,grid));
            }

        }
       }
    return max1;
    }
};
