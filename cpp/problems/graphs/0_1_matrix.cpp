// Distance of nearest cell having 1

// Time Complexity - O(n x m)
// Space COmplexity - O(n x m)

#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
    vector<vector<int>> nearest_one(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue <pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({ i, j });
                }
            }
        }

        int delta_row[] = { -1, 0, 1, 0 };
        int delta_col[] = { 0, 1, 0, -1 };

        while(!q.empty()) {
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
                    vis[nrow][ncol] == 0
                ) {
                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({ nrow, ncol });
                }
            }
        }

        return dist;
    }
};