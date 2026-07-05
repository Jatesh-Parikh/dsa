// Time Complexity - O(n x m)
// Space Complexity - O(n x m)

#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
    int number_of_enclaves(vector<vector<int>>& grid) {
        queue <pair<int, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                q.push({ 0, j });
                vis[0][j] = 1;
            }

            if (grid[n - 1][j] == 1) {
                q.push({ n - 1, j });
                vis[n - 1][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                q.push({ i, 0 });
                vis[i][0] = 1;
            }

            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                q.push({ i, m - 1 });
                vis[i][m - 1] = 1;
            }
        }

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];

                if (
                    nrow >= 0 &&
                    nrow < n &&
                    ncol >= 0 &&
                    ncol < m && 
                    !vis[nrow][ncol] &&
                    grid[nrow][ncol] == 1
                ) {
                    q.push({ nrow, ncol });
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};