#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(logn)
        // Space Complexity - O(1)
        int search_index_position(vector<int>& arr, int m) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int ans = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] >= m) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return ans;
        }
};