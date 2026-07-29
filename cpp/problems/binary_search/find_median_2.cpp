#include <vector>
#include <climits>

using namespace std;

class Solution {
    private:
        int upper_bound(vector<int>& arr, int n, int x) {
            int low = 0, high = n - 1;
            int ans = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] > x) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return ans;
        }

        int count_small_equals(vector<vector<int>>& mat, int m, int n, int x) {
            int count = 0;

            for (int i = 0; i < m; i++) {
                count += upper_bound(mat[i], n, x);
            }

            return count;
        }

    public: 
    // Time Complexity - O(log(high - low + 1) *  m logn)
    // Space Complexity - O(1)
        int median(vector<vector<int>>& mat, int m, int n) {
            int low = INT_MAX, high = INT_MIN;

            for (int i = 0; i < m; i++) {
                low = min(low, mat[i][0]);
                high = max(high, mat[i][n - 1]);
            }

            int req = (m * n) / 2;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int small_equals = count_small_equals(mat, m, n, mid);

                if (small_equals <= req) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return low;
        }
};