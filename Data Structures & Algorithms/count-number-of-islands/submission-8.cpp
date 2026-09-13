class Solution {
public:

    // DFS helper function to mark all connected land ('1') as visited
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        // Base case: if out of bounds, return
        if(x < 0 || y < 0 || x >= n || y >= m){
            return;
        }

        // If current cell is land ('1')
        if(grid[x][y] == '1'){
            grid[x][y] = '0'; // Mark it as visited to avoid revisiting

            // Explore all 4 directions recursively
            dfs(x+1, y, n, m, grid); // down
            dfs(x-1, y, n, m, grid); // up
            dfs(x, y-1, n, m, grid); // left
            dfs(x, y+1, n, m, grid); // right
        }
    }

    // Main function to count number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();      // number of rows
        if(n == 0){
            return 0; // empty grid edge case
        }
        int m = grid[0].size();   // number of columns
        int count = 0;            // number of islands found

        // Traverse each cell in the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // If we find unvisited land
                if(grid[i][j] == '1'){
                    count++;           // Increment island count
                    dfs(i, j, n, m, grid); // Mark the whole island as visited
                }
            }
        }

        return count; // Return total number of islands
    }
};
