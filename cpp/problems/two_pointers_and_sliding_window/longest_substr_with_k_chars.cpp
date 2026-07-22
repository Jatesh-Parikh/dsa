#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(k)
        int longest_substr_with_k_chars(string& s, int k) {
            int left = 0, right = 0, max_len = 0;
            int n = s.size();
            unordered_map <char, int> freq;

            while (right < n) {
                freq[s[right]]++;

                while (freq.size() > k) {
                    freq[s[left]]--;
                    if (freq[s[left]] == 0) freq.erase(s[left]);
                    left++;
                }

                max_len = max(max_len, right - left + 1);
                right++;
            }

            return max_len;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(k)
        int longest_substr_with_k_chars_optimal(string& s, int k) {
            int left = 0, right = 0, max_len = 0;
            unordered_map<char, int> freq;
            int n = s.size();

            while (right < n) {
                freq[s[right]]++;

                if (freq.size() > k) {
                    freq[s[left]]--;
                    if (freq[s[left]] == 0) freq.erase(s[left]);
                    left++;
                }

                if (freq.size() <= k) max_len = max(max_len, right - left + 1);
                right++;
            }

            return max_len;
        }
};