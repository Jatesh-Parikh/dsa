#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(logn)
        // Space Complexity - O(1)
        int find_ceil(vector<int>& arr, int target) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int ans = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] >= target) {
                    ans = arr[mid];
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return ans;
        }
};