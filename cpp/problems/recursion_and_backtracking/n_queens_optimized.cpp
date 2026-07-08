// Time Complexity - O(n!)
// Space Complexity - O(k * n ^ 2)
// Auxiliary Space - O(n)

#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        void solve(
            int col, 
            vector<string>& board, 
            vector<vector<string>>& ans, 
            vector<int>& left_row, 
            vector<int>& lower_diagonal,
            vector<int>& upper_diagonal,
            int n
        ) {
            if (col == n) {
                ans.push_back(board);
                return;
            }

            for (int row = 0; row < n; row++) {
                if (
                    left_row[row] == 0 && 
                    lower_diagonal[row + col] == 0 &&
                    upper_diagonal[n - 1 + col - row] == 0
                ) {
                    board[row][col] = 'Q';
                    left_row[row] = 1;
                    lower_diagonal[row + col] = 1;
                    upper_diagonal[n - 1 + col - row] = 1;
                    
                    solve(col + 1, board, ans, left_row, lower_diagonal, upper_diagonal, n);
                    
                    board[row][col] = '.';
                    left_row[row] = 0;
                    lower_diagonal[row + col] = 0;
                    upper_diagonal[n - 1 + col - row] = 0;
                    
                }
            }
        }

    public:
        vector<vector<string>> n_queens_two(int n) {
            vector<vector<string>> ans;
            vector<string> board(n, string(n, '.'));
            vector<int> left_row(n, 0), lower_diagonal(2 * n - 1, 0), upper_diagonal(2 * n - 1, 0);

            solve(0, board, ans, left_row, lower_diagonal, upper_diagonal, n);

            return ans;
        }
};