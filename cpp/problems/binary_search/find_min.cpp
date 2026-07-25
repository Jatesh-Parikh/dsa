#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(logn)
        // Space Complexity - O(1)
        int find_min(vector<int>& arr) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int ans = INT_MAX;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[low] <= arr[high]) {
                    ans = min(ans, arr[low]);
                    break;
                }

                if (arr[low] <= arr[mid]) { // left-half sorted
                    ans = min(ans, arr[low]);
                    low = mid + 1; 
                } else { // right-half sorted
                    ans = min(ans, arr[mid]);
                    high = mid - 1;
                }
            }

            return ans;
        }
};