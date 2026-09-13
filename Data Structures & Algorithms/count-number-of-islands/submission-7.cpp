class Solution {
public:

    void dfs(int x,int y, int n ,int m,vector<vector<char>>& grid){

        if(x<0 || y<0 || x>=n || y>=m){
            return;
        }
        if(grid[x][y]=='1'){
            grid[x][y]='0';
            dfs(x+1,y,n,m,grid);
            dfs(x-1,y,n,m,grid);
            dfs(x,y-1,n,m,grid);
            dfs(x,y+1,n,m,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return count;
    }
};
