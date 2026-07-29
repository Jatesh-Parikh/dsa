#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n + m)
        // Space Complexity - O(1)
        bool search_matrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int row = 0, col = m - 1;

            while (row < n && col >= 0) {
                if (matrix[row][col] == target) return true;
                else if (matrix[row][col] < target) row++;
                else col--;
            }

            return false;
        }
};