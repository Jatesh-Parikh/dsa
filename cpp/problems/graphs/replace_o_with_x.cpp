// Time Complexity - O(n x m)
// Space Complexity - O(n x m)

#include <vector>

using namespace std;

class Solution {
    private:
    void dfs(
        int row, 
        int col, 
        vector<vector<int>>& vis, 
        vector<vector<char>>& mat, 
        int delta_row[], 
        int delta_col[], 
        int n, 
        int m
    ) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delta_row[i];
            int ncol = col + delta_col[i];

            if (
                nrow >= 0 &&
                nrow < n &&
                ncol >= 0 &&
                ncol < m && 
                !vis[nrow][ncol] && 
                mat[nrow][ncol] == 'O'
            ) {
                dfs(nrow, ncol, vis, mat, delta_row, delta_col, n, m);
            }
        }
    }

    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delta_row, delta_col, n, m);
            }

            if (!vis[n-1][j] && mat[n-1][j] == 'O') {
                dfs(n-1, j, vis, mat, delta_row, delta_col, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delta_row, delta_col, n, m);
            }

            if (!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m - 1, vis, mat, delta_row, delta_col, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};