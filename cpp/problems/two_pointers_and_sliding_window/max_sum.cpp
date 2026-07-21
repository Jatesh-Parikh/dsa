#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(k)
        // Space Complexity - O(1)
        int max_sum(vector<int>& arr, int k) {
            int n = arr.size();
            int left_sum = 0, right_sum = 0, max_sum = 0;

            for (int i = 0; i < k; i++) left_sum += arr[i];
            max_sum = left_sum;

            int right_index = n - 1;

            for (int i = k - 1; i >= 0; i--) {
                left_sum -= arr[i];
                right_sum += arr[right_index];
                right_index--;
                max_sum = max(max_sum, left_sum + right_sum);
            }

            return max_sum;
        }
};