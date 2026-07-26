#include <vector>
#include <climits>
#include <math.h>

using namespace std;

class Solution {
    private:
        int find_max(vector<int>& arr) {
            int maximum = INT_MIN;

            for (int i = 0; i < arr.size(); i++) {
                maximum = max(maximum, arr[i]);
            }

            return maximum;
        }

        int sum_by_d(vector<int>& arr, int divisor) {
            int sum = 0;

            for (int i = 0; i < arr.size(); i++) {
                sum += ceil((double)arr[i] / (double)divisor);
            }

            return sum;
        }
    
    public:
        // Time Complexity - O(n * log(max_element))
        // Space Complexity - O(1)
        int smallest_divisor(vector<int>& arr, int threshold) {
            if (arr.size() > threshold) return -1; // Since, arr.size() can be the minimum sum
            
            int low = 1, high = find_max(arr);

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (sum_by_d(arr, mid) <= threshold) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        }
};