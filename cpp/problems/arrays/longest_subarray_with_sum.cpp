#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        // Optimal Solution when the array contains positives and negatives
        int longest_subarray_with_sum(vector<int>& a, long long k) {
            unordered_map<long long, int> presum_map;
            long long sum = 0;
            int max_len = 0;

            for (int i = 0; i < a.size(); i++) {
                sum += a[i];

                if(sum == k) {
                    max_len = max(max_len, i + 1);
                }

                long long rem = sum - k;

                if (presum_map.find(rem) != presum_map.end()) {
                    int len = i - presum_map[rem];
                    max_len = max(max_len, len);
                }

                if (presum_map.find(sum) == presum_map.end()) {
                    presum_map[sum] = i;
                }
            }

            return max_len;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        // Optimal Solution when the array contains only positives
        int longest_subarray_with_sum_optimal(vector<int>& a, long long k) {
            int left = 0, right = 0;
            long long sum = a[0];
            int max_len = 0;
            int n = a.size();

            while (right < n) {
                while (left <= right && sum > k) {
                    sum -= a[left];
                    left++;
                }

                if (sum == k) max_len = max(max_len, right - left + 1);

                right++;
                if (right < n) sum += a[right];
            }

            return max_len;
        };
};