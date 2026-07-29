#include <vector>

using namespace std;

class Solution {
    private:
        int lower_bound(vector<int>& a, int n, int x) {
            int low = 0, high = n - 1;
            int ans = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                if (a[mid] >= x) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return ans;
        }
        
    public:
        // Time Complexity - O(n * logm)
        // Space Complexity - O(1)
        int row_with_max_1s(vector<vector<int>>& matrix, int n, int m) {
            int max_count = 0;
            int index = -1;

            for (int i = 0; i < n; i++) {
                int count_ones = m - lower_bound(matrix[i], m, 1);

                if (count_ones > max_count) {
                    max_count = count_ones;
                    index = i;
                }
            }

            return index;
        }
};