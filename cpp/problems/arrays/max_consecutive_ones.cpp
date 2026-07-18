#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int max_consecutive_ones(vector<int>& arr, int n) {
            int maximum = 0, count = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] == 1) {
                    count++;
                    maximum = max(maximum, count);
                } else {
                    count = 0;
                }
            }

            return maximum;
        }
};