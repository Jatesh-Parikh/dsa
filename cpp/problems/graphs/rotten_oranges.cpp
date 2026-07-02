#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    public:
        int rotten_oranges(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            queue<pair<pair<int, int>, int>> q; // {{r, c}, t}

            vector<vector<int>> vis;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 2) {
                        q.push({{i, j}, 0});
                        vis[i][j] = 2;
                    } else {
                        vis[i][j] = 0;
                    }
                }
            }

            int time = 0;

            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};

            while (!q.empty()) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                time = max(time, t);

                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = r + delta_row[i];
                    int ncol = c + delta_col[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] && !vis[nrow][ncol]) {
                        q.push({{nrow, ncol}, time + 1});
                        vis[nrow][ncol] = 2;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(vis[i][j] == 1) {
                        return -1;
                    }
                }
            }

            return time;
        }
};