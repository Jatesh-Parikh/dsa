#include <vector>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        tuple<long long, int, int> max_subarray_sum(vector<int>& arr, int n) {
            long long sum = 0, max_sum = LLONG_MIN;

            int ans_start = 0, ans_end = 0, start = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];

                if (sum > max_sum) {
                    max_sum = sum;
                    ans_start = start;
                    ans_end = i;
                } 

                if (sum < 0) {
                    sum = 0;
                    start = i + 1;
                }
            }

            return {max_sum, ans_start, ans_end};
        }
};