// Same as the Largest Subarray Sum Minimized problem, and Allocate Books problem

#include <vector>
#include <climits>

using namespace std;

class Solution {
    private:
        int count_painters(vector<int>& arr, int area_per_painter) {
            int painters = 1, area = 0;

            for (int i = 0; i < arr.size(); i++) {
                if (area + arr[i] <= area_per_painter) {
                    area += arr[i];
                } else {
                    painters++;
                    area = arr[i];
                }
            }

            return painters;
        }
    
    public:
        // Time Complexity - O(n * log(sum - maximum + 1))
        // Space Complexity - O(1)
        int painters_partition(vector<int>& arr, int k) {
            int maximum = INT_MIN, sum = 0;
            
            for (int i = 0; i < arr.size(); i++) {
                maximum = max(maximum, arr[i]);
                sum += arr[i];
            }

            int low = maximum, high = sum;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int painters = count_painters(arr, mid);

                if (painters > k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return low;
        }
};