// Time Complexity - O(3 ^ (n * m))
// Space Complexity - O(n * m)

#include <vector>
#include <string>

using namespace std;
class Solution {
    private:
        void solve(
            int row,
            int col,
            vector<vector<int>>& m,
            int n,
            vector<string>& ans,
            string& move,
            vector<vector<int>>& vis,
            const int delta_row[],
            const int delta_col[],
            const char arr[]
        ) {
            if (row == n - 1 && col == n - 1) {
                ans.push_back(move);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int next_row = row + delta_row[i];
                int next_col = col + delta_col[i];

                if (
                    next_row >= 0 && 
                    next_row < n &&
                    next_col >= 0 &&
                    next_col < n &&
                    !vis[next_row][next_col] &&
                    m[next_row][next_col] == 1 
                ) {
                    vis[next_row][next_col] = 1;
                    move.push_back(arr[i]);
                    
                    solve(next_row, next_col, m, n, ans, move, vis, delta_row, delta_col, arr);
                    
                    vis[next_row][next_col] = 0;
                    move.pop_back();
                }
            }
        }

    public:
        vector<string> find_path(vector<vector<int>>& m, int n) {
            vector<vector<int>> vis(n, vector<int>(n, 0));
            vector<string> ans;
            string move;

            const int delta_row[] = {1, 0, 0, -1};
            const int delta_col[] = {0, -1, 1, 0};
            const char arr[] = {'D', 'L', 'R', 'U'};

            if (m[0][0] == 0) return ans;

            vis[0][0] = 1;

            solve(0, 0, m, n, ans, move, vis, delta_row, delta_col, arr);

            return ans;
        }
};