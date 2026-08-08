#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int trapping_rainwater_brute(vector<int>& arr) {
            int n = arr.size();
            if (n == 0) return 0;

            int total = 0;
            vector<int> prefix_max(n);
            vector<int> suffix_max(n);

            prefix_max[0] = arr[0];
            for (int i = 1; i < n; i++) {
                prefix_max[i] = max(prefix_max[i - 1], arr[i]);
            }

            suffix_max[n - 1] = arr[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                suffix_max[i] = max(arr[i], suffix_max[i + 1]);
            }

            for (int i = 0; i < n; i++) {
                int left_max = prefix_max[i];
                int right_max = suffix_max[i];

                if (arr[i] < left_max && arr[i] < right_max) {
                    total += min(left_max, right_max) - arr[i];
                }
            }

            return total;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int trapping_rainwater_optimal(vector<int>& arr) {
            int n = arr.size();
            if (n == 0) return 0;

            int left_max = 0, right_max = 0, total = 0;
            int l = 0, r = arr.size() - 1;

            while (l < r) {
                if (arr[l] <= arr[r]) {
                    if (left_max > arr[l]) total += left_max - arr[l];
                    else left_max = arr[l];
                    l += 1;
                } else {
                    if (right_max > arr[r]) total += right_max - arr[r];
                    else right_max = arr[r];
                    r -= 1;
                }
            }

            return total;
        }
};