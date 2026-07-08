// Time Complexity - O(4 ^ (n * m))
// Space Complexity - O(n * m)

#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        void solve(
            int i, 
            int j, 
            vector<vector<int>>& m,
            int n, 
            string& move,
            vector<string>& ans,  
            vector<vector<int>>& vis
        ) {
            if (i == n-1 && j == n - 1) {
                ans.push_back(move);
                return;
            }

            // Downward
            if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1) {
                vis[i + 1][j] = 1;
                move.push_back('D');
                solve(i + 1, j, m, n, move, ans, vis);
                vis[i + 1][j] = 0;
                move.pop_back();
            }

            // Left
            if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1) {
                vis[i][j - 1] = 1;
                move.push_back('L');
                solve(i, j - 1, m, n, move, ans, vis);
                vis[i][j - 1] = 0;
                move.pop_back();
            }

            // Right
            if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1) {
                vis[i][j + 1] = 1;
                move.push_back('R');
                solve(i, j + 1, m, n, move, ans, vis);
                vis[i][j + 1] = 0;
                move.pop_back();
            }

            // Upward
            if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1) {
                vis[i - 1][j] = 1;
                move.push_back('U');
                solve(i - 1, j, m, n, move, ans, vis);
                vis[i - 1][j] = 0;
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

