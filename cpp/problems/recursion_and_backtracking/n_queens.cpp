// Time Complexity - O (n! * n)
// Space Complexity -  O(k * n ^ 2), where k is the number of valid solutions
// Auxiliary Space - O(n), recursion stack with at most n calls

#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        bool is_safe(int row, int col, vector<string>& board, int n) {
            int dup_row = row;
            int dup_col = col;

            while (row >= 0 && col >= 0) {
                if (board[row][col] == 'Q') return false;
                row--;
                col--;
            }

            row = dup_row;
            col = dup_col;

            while (col >= 0) {
                if (board[row][col] == 'Q') return false;
                col--;
            }

            col = dup_col;

            while(row < n && col >= 0) {
                if (board[row][col] == 'Q') return false;
                row++;
                col--;
            }

            return true;
        }

        void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
            if (col == n) {
                ans.push_back(board);
                return;
            }

            for (int row = 0; row < n; row++) {
                if (is_safe(row, col, board, n)) {
                    board[row][col] = 'Q';
                    solve(col + 1, board, ans, n);
                    board[row][col] = '.';
                }
            }
        }

    public:
        vector<vector<string>> n_queens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n, string(n, '.'));

            solve(0, board, ans, n);

            return ans;
        }     
}; 