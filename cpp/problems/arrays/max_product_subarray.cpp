#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(m)
        // Space Complexity - O(1)
        int max_product_subarray(vector<int>& arr) {
            int n = arr.size();
            int ans = INT_MIN;
            int prefix = 1, suffix = 1;

            for (int i = 0; i < n; i++) {
                if (prefix == 0) prefix = 1;
                if (suffix == 0) suffix = 1;

                prefix = prefix * arr[i];
                suffix = suffix * arr[n - 1 - i];
                ans = max(ans, max(prefix, suffix));
            }

            return ans;
        }
};