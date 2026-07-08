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
            string& move,
            vector<string>& ans,  
            vector<vector<int>>& vis
        ) {
            if (row == n - 1 && col == n - 1) {
                ans.push_back(move);
                return;
            }

            // Downward
            if (row + 1 < n && !vis[row + 1][col] && m[row + 1][col] == 1) {
                vis[row + 1][col] = 1;
                move.push_back('D');
                solve(row + 1, col, m, n, move, ans, vis);
                vis[row + 1][col] = 0;
                move.pop_back();
            }

            // Left
            if (col - 1 >= 0 && !vis[row][col - 1] && m[row][col - 1] == 1) {
                vis[row][col - 1] = 1;
                move.push_back('L');
                solve(row, col - 1, m, n, move, ans, vis);
                vis[row][col - 1] = 0;
                move.pop_back();
            }

            // Right
            if (col + 1 < n && !vis[row][col + 1] && m[row][col + 1] == 1) {
                vis[row][col + 1] = 1;
                move.push_back('R');
                solve(row, col + 1, m, n, move, ans, vis);
                vis[row][col + 1] = 0;
                move.pop_back();
            }

            // Upward
            if (row - 1 >= 0 && !vis[row - 1][col] && m[row - 1][col] == 1) {
                vis[row - 1][col] = 1;
                move.push_back('U');
                solve(row - 1, col, m, n, move, ans, vis);
                vis[row - 1][col] = 0;
                move.pop_back();
            }
        }
    
    public:
        vector<string> find_path(vector<vector<int>>& m, int n) {
            vector<string> ans;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            string move;

            if (m[0][0] == 0) return ans;
            
            vis[0][0] = 1;

            solve(0, 0, m, n, move, ans, vis);
            
            return ans;
        }
};

