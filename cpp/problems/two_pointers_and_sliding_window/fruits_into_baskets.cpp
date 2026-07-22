#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(k)
        int fruits_into_baskets(vector<int>& arr, int k) {
            int left = 0, right = 0, max_len = 0;
            unordered_map<int, int> freq;
            int n = arr.size();

            while (right < n) {
                freq[arr[right]]++;

                if (freq.size() > k) {
                    while (freq.size() > k) {
                        freq[arr[left]]--;
                        if (freq[arr[left]] == 0) freq.erase(arr[left]);
                        left++;
                    }
                }

                max_len = max(max_len, right - left + 1);
                right++;
            }

            return max_len;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(k)
        int fruits_into_baskets_optimal(vector<int>& arr, int k) {
            int left = 0, right = 0, max_len = 0;
            int n = arr.size();
            unordered_map<int, int> freq;

            while (right < n) {
                freq[arr[right]]++;

                if (freq.size() > k) {
                    freq[arr[left]]--;
                    if (freq[arr[left]] == 0) freq.erase(arr[left]);
                    left++;
                }

                if (freq.size() <= k) max_len = max(max_len, right - left + 1);
                
                right++;
            }

            return max_len;
        }
};