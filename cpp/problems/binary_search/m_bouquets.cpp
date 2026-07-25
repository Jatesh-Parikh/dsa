#include <vector>
#include <climits>

using namespace std;

class Solution {
    private:
        bool possible(vector<int>& arr, int day, int m, int k) {
            int count = 0;
            int bouquets = 0;

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] <= day) {
                    count++;
                } else {
                    bouquets += count / k;
                    count = 0;
                }
            }
            bouquets += count / k;

            return bouquets >= m;
        }

    public:
        // Time Complexity - O(n * log(maximum - minimum + 1))
        // Space Complexity - O(1)
        int m_bouquets(vector<int>& arr, int r, int b) {
            long long val = (long long)r * b;

            if (val > arr.size()) return -1;

            int minimum = INT_MAX, maximum = INT_MIN;
            for (int i = 0; i < arr.size(); i++) {
                maximum = max(maximum, arr[i]);
                minimum = min(minimum, arr[i]);
            }

            int low = minimum, high = maximum;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (possible(arr, mid, b, r)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        }

};