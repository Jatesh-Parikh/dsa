#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int longest_substr(string s) {
            int n = s.size();
            int left = 0, right = 0;
            vector<int> hash(256, -1);
            int max_len = 0;

            while (right < n) {
                if (hash[s[right]] != -1) {
                    if (hash[s[right]] >= left) {
                        left = hash[s[right]] + 1;
                    }
                }

                int len = right - left + 1;
                max_len = max(max_len, len);
                hash[s[right]] = right;
                right++;
            }

            return max_len;
        }
};