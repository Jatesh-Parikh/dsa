// Same as the Painters Partition problem, and Allocate Books problem

#include <vector>
#include <climits>

using namespace std;

class Solution {
    private:
        int count_subarrays(vector<int>& arr, int max_sum) {
            int subarray_count = 1, sum = 0;

            for (int i = 0; i < arr.size(); i++) {
                if (sum + arr[i] <= max_sum) {
                    sum += arr[i];
                } else {
                    subarray_count++;
                    sum = arr[i];
                }
            }

            return subarray_count;
        }
    
    public:
        // Time Complexity - O(n * log(sum - maximum + 1))
        // Space Complexity - O(1)
        int largest_subarray_sum_minimized(vector<int>& arr, int k) {
            int maximum = INT_MIN, sum = 0;

            for (int i = 0; i < arr.size(); i++) {
                maximum = max(maximum, arr[i]);
                sum += arr[i];
            }

            int low = maximum, high = sum;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int subarray_count = count_subarrays(arr, mid);

                if (subarray_count > k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return low;
        }
};