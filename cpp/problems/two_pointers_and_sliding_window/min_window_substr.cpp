#include <string>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n ^ 2)
        // Space Complexity - O(1)
        string min_window_substr(string& s, string& t) {
            int n = s.size(), m = t.size();

            int min_len = INT_MAX;
            int start_index = -1;

            for (int i = 0; i < n; i++) {
                int hash[256] = {0};
                for (char c: t) hash[c]++;

                int count = 0;

                for (int j = i; j < n; j++) {
                    if (hash[s[j]] > 0) count += 1;
                    hash[s[j]]--;

                    if (count == m) {
                        if (j - i + 1 < min_len) {
                            min_len = j - i + 1;
                            start_index = i;
                        }
                        break;
                    }
                }
            }

            return start_index == -1 ? "" : s.substr(start_index, min_len);
        }

        // Time Complexity - O(n + m)
        // Space Complexity - O(1)
        string min_window_substr_optimal(string& s, string& t) {
            int n = s.size(), m = t.size();
            int start_index = -1, min_len = INT_MAX;
            int left = 0, right = 0;

            int hash[256] = {0};
            for (char c: t) hash[c]++;
            int count = 0;
            
            while (right < n) {
                if (hash[s[right]] > 0) count += 1;
                hash[s[right]]--;    

                while (count == m) {
                    if (right - left + 1 < min_len) {
                        min_len = right - left + 1;
                        start_index = left;
                    }
                    
                    hash[s[left]]++;
                    if (hash[s[left]] > 0) count -= 1;
                    left++;
                }
                
                right++;
            }

            return start_index == -1 ? "" : s.substr(start_index, min_len);
        }
};