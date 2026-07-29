#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(log(n * m))
        // Space Complexity - O(1)
        bool search_matrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int low = 0, high = n * m - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int row = mid / m, col = mid % m;

                if (matrix[row][col] == target) return true;
                else if (matrix[row][col] < target) low = mid + 1;
                else high = mid - 1;
            }

            return false;
        }
};