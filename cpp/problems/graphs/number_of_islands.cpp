#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    private:
        void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid) {
            visited[row][col] = 1;
            queue<pair<int, int>> q;
            q.push({ row, col });

            int n = grid.size();
            int m = grid[0].size();

            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int delta_row = -1; delta_row <= 1; delta_row++) {
                    for (int delta_col = -1; delta_col <= 1; delta_col++) {
                        int nrow = row + delta_row;
                        int ncol = col + delta_col;

                        if (
                            nrow >= 0 && 
                            nrow < n && 
                            ncol >= 0 && 
                            ncol < m && 
                            grid[nrow][ncol] == '1' && 
                            !visited[nrow][ncol]
                        ) {
                            visited[nrow][ncol] = 1;
                            q.push({ nrow, ncol });
                        }
                    }
                }
            }
        }

    public:
        int num_of_islands(vector<vector<char>> &grid) {
            int n = grid.size();
            int m = grid[0].size();

            vector<vector<int>> visited(n, vector<int>(m, 0));
            
            int count = 0;

            for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                    if (grid[row][col] == '1' && !visited[row][col]) {
                        count++;
                        bfs(row, col, visited, grid);
                    }
                }
            }

            return count;
        }
};