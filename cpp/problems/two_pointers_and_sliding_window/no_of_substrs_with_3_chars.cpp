#include <string>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int number_of_substr_with_3_chars(string& s) {
            int last_seen[] = { -1, -1, -1 };
            int n = s.size();
            int count = 0;

            for (int i = 0; i < n; i++) {
                last_seen[s[i] - 'a'] = i;

                if (
                    last_seen[0] != -1 &&
                    last_seen[1] != -1 &&
                    last_seen[2] != -1
                ) {
                    count += 1 + min(last_seen[0], last_seen[1], last_seen[2]);
                }
            }

            return count;
        }
};