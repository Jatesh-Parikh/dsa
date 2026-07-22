#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int max_consecutive_ones(vector<int>& arr, int k) {
            int left = 0, right = 0, max_len = 0, zeros = 0;
            int n = arr.size();

            while (right < n) {
                if (arr[right] == 0) zeros++;

                while (zeros > k) {
                    if (arr[left] == 0) zeros--;
                    left++;
                }
                
                int len = right - left + 1;
                max_len = max(max_len, len);

                right++;
            }

            return max_len;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int max_consecutive_ones_optimal(vector<int>& arr, int k) {
            int left = 0, right = 0, max_len = 0, zeros = 0;
            int n = arr.size();

            while (right < n) {
                if (arr[right] == 0) zeros++;

                if (zeros > k) {
                    if (arr[left] == 0) zeros--;
                    left++;
                }

                if (zeros <= k) max_len = max(max_len, right - left + 1);
                right++; 
            }

            return max_len;
        }

};