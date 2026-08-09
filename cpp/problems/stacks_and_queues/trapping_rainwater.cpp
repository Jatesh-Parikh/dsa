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
            vector<int> l_max(n);
            vector<int> r_max(n);

            l_max[0] = arr[0];
            for (int i = 1; i < n; i++) {
                l_max[i] = max(l_max[i - 1], arr[i]);
            }

            r_max[n - 1] = arr[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                r_max[i] = max(arr[i], r_max[i + 1]);
            }

            for (int i = 0; i < n; i++) {
                int left_max = l_max[i];
                int right_max = r_max[i];

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
                left_max = max(left_max, arr[l]);
                right_max = max(right_max, arr[r]);

                if (left_max < right_max) {
                    total += left_max - arr[l];
                    l++;
                } else {
                    total += right_max - arr[r];
                    r--;
                }
            }

            return total;
        }
};