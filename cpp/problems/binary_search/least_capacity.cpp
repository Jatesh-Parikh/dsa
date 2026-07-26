#include <vector>

using namespace std;

class Solution {
    private:
        int find_days(vector<int>& weights, int cap) {
            int days = 1, load = 0;

            for (int i = 0; i < weights.size(); i++) {
                if (load + weights[i] > cap) {
                    days += 1;
                    load = weights[i];
                } else {
                    load += weights[i];
                }
            }

            return days;
        }

    public:
        // Time Complexity - O(n * log(sum - max_element + 1))
        // Space Complexity - O(1)
        int least_capacity(vector<int>& weights, int d) {
            int low = 0, high = 0;

            for (int i = 0; i < weights.size(); i++) {
                low = max(low, weights[i]);
                high += weights[i];
            }

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (find_days(weights, mid) <= d) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        }
};