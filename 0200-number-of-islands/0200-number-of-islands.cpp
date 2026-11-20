
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        // Check boundaries and water
        if (row < 0 || col < 0 || row >= m || col >= n ||
            grid[row][col] == '0') {
            return;
        }

        // Mark current land as visited
        grid[row][col] = '0';

        // Explore all four directions
        dfs(grid, row + 1, col); // Down
        dfs(grid, row - 1, col); // Up
        dfs(grid, row, col + 1); // Right
        dfs(grid, row, col - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    islands++;

                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
