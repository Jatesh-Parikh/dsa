#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n * m)
        // Space Complexity - O(n + m)
        vector<vector<int>> zero_matrix(vector<vector<int>>& matrix, int n, int m) {
            vector<int> row(n, 1);
            vector<int> col(m, 1);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        row[i] = 0;
                        col[j] = 0;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (row[i] == 0 || col[j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }

            return matrix;
        }

        // Time Complexity - O(n * m)
        // Space Complexity - O(1)
        vector<vector<int>> zero_matrix_optimal(vector<vector<int>>& matrix, int n, int m) {
            int col0 = 1;            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;

                        if (j != 0) matrix[0][j] = 0;
                        else col0 = 0;
                    }
                }
            }

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }

            if (matrix[0][0] == 0) for (int i = 0; i < m; i++) matrix[0][i] = 0;

            if (col0 == 0) for (int i = 0; i < n; i++) matrix[i][0] = 0;

            return matrix;
        }
};