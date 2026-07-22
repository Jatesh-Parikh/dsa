#include <string>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int longest_repeating_char_replacement(string& s, int k) {
            int left = 0, right = 0, max_len = 0, max_freq = 0;
            int n = s.size();
            int hash[26] = {0};

            while (right < n) {
                hash[s[right] - 'A']++;
                max_freq = max(max_freq, hash[s[right] - 'A']);

                while ((right - left + 1) - max_freq > k) {
                    hash[s[left] - 'A']--; 
                    max_freq = 0;
                    for (int i = 0; i < 26; i++) max_freq = max(max_freq, hash[i]);
                    left++;
                }

                max_len = max(max_len, right - left + 1);
                right++;
            }

            return max_len;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int longest_repeating_char_replacement_optimal(string& s, int k) {
            int left = 0, right = 0, max_len = 0, max_freq = 0;
            int n = s.size();
            int hash[26] = {0};

            while (right < n) {
                hash[s[right] - 'A']++;
                max_freq = max(max_freq, hash[s[right] - 'A']);

                if ((right - left + 1) - max_freq > k) {
                    hash[s[left] - 'A']--; 
                    left++;
                }

                if ((right - left + 1) - max_freq <= k) max_len = max(max_len, right - left + 1);
                right++;
            }

            return max_len;
        }
};