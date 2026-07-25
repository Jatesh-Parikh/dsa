#include <vector>
#include <climits>
#include <math.h>

using namespace std;

class Solution {
    private:
        int max_element(vector<int>& arr) {
            int maximum = INT_MIN;

            for (int i = 0; i < arr.size(); i++) {
                maximum = max(maximum, arr[i]); 
            }

            return maximum;
        }

        int total_hrs(vector<int>& arr, int hourly) {
            int total_hrs = 0;

            for (int i = 0; i < arr.size(); i++) {
                total_hrs += ceil((double) arr[i] / (double) hourly);
            }

            return total_hrs;
        }

    public:
        // Time Complexity - O(n * log(max_element))
        // Space Complexity - O(1)
        int koko_eating_bananas(vector<int>& arr, int h) {
            int low = 1, high = max_element(arr);

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int total_hours = total_hrs(arr, mid);
                
                if (total_hours <= h) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        }
};