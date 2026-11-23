
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    if (newRow >= 0 && newRow < m &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        fresh--;

                        q.push({newRow, newCol});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
