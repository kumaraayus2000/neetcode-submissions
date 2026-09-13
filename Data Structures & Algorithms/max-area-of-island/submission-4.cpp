class Solution {
public:

    // DFS function to calculate area of island starting at (x, y)
    int dfs(int x, int y, int n, int m, vector<vector<int>>& grid){
        // 1. Boundary check: if outside grid, return 0
        if(x < 0 || y < 0 || x >= n || y >= m){
            return 0;
        }

        // 2. If current cell is land (1), process it
        if(grid[x][y] == 1){
            grid[x][y] = 0;  // Mark as visited to avoid revisiting

            // 3. Area = 1 (current cell) + areas of all 4 neighbors
            return 1 
                + dfs(x+1, y, n, m, grid)  // down
                + dfs(x-1, y, n, m, grid)  // up
                + dfs(x, y-1, n, m, grid)  // left
                + dfs(x, y+1, n, m, grid); // right
        }

        // 4. If water cell (0) or already visited, area contribution = 0
        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();       // Number of rows
        int m = grid[0].size();    // Number of columns
        int max1 = 0;              // Store max area

        // 5. Traverse all cells of the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // 6. If cell is land, compute island area via DFS
                if(grid[i][j] == 1){
                    max1 = max(max1, dfs(i, j, n, m, grid));
                }
            }
        }

        // 7. Return the largest island area
        return max1;
    }
};
