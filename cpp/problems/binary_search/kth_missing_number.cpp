#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int kth_missing_number_linear(vector<int>& arr, int k) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] <= k) k++; 
                else break;
            }

            return k;
        }
        
        // Time Complexity - O(logn)
        // Space Complexity - O(1)
        int kth_missing_number_bs(vector<int>& arr, int k) {
            int low = 0, high = arr.size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int missing = arr[mid] - (mid + 1);

                if (missing < k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return high + 1 + k; // low + k
        }
};