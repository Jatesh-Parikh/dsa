#include <vector>
#include <climits>

using namespace std;

class Solution {
    private:
        int find_max_index(vector<vector<int>>& mat, int n, int col) {
            int max_index = -1;
            int max_value = -1;

            for (int i = 0; i < n; i++) {
                if (mat[i][col] > max_value) {
                    max_value = mat[i][col];
                    max_index = i;
                }
            }

            return max_index;
        }

    public:
        // Time Complexity - O(n * logm)
        // Space Complexity - O(1)
        vector<int> find_peak(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            int low = 0, high = m - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int max_row_index = find_max_index(mat, n, mid);
                int left = mid - 1 >= 0 ? mat[max_row_index][mid - 1] : -1;
                int right = mid + 1 < m ? mat[max_row_index][mid + 1] : -1;

                if (mat[max_row_index][mid] > left && mat[max_row_index][mid] > right) return { max_row_index, mid }; 
                else if (mat[max_row_index][mid] < left) high = mid - 1;
                else low = mid + 1;
            }

            return { -1, -1 };
        }
};