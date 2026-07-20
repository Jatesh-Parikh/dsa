#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n ^ 2)
        // Space Complexity - O(n ^ 2)
        vector<vector<int>> rotate_matrix(vector<vector<int>> matrix) {
            int n = matrix.size();
            vector<vector<int>> ans(n, vector<int>(n, 0));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans[j][n - 1 - i] = matrix[i][j];
                }
            }

            return ans;
        }

        // Time Complexity - O(n ^ 2)
        // Space Complexity - O(1)
        vector<vector<int>> rotate_matrix_optimal(vector<vector<int>>& matrix) {
            int n = matrix.size();

            // Transpose
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            for (int i = 0; i < n; i++) {
                reverse(matrix[i].begin(), matrix[i].end());
            }
            
            return matrix;
        }
};