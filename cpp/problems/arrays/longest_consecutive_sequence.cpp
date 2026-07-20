#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n * logn)
        // Space Complexity - O(1)
        int longest_consecutive_sequence(vector<int>& arr) {
            if (arr.size() == 0) return 0;

            sort(arr.begin(), arr.end());

            int n = arr.size();
            int count = 0;
            int longest = 1;
            int last_smaller = INT_MIN;

            for (int i = 0; i < n; i++) {
                if (arr[i] - 1 == last_smaller) {
                    count += 1;
                    last_smaller = arr[i];
                } else if (arr[i] != last_smaller) {
                    count = 1;
                    last_smaller = arr[i];
                }

                longest = max(longest, count);
            }

            return longest;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int longest_consecutive_sequence_optimal(vector<int>& arr) {
            if (arr.size() == 0) return 0;
            
            int n = arr.size();
            int longest = 1;

            unordered_set<int> st;

            for (int i = 0; i < n; i++) {
                st.insert(arr[i]);
            }

            for (auto it: st) {
                if (st.find(it - 1) == st.end()) {
                    int count = 1;
                    int x = it;

                    while (st.find(x + 1) != st.end()) {
                        count += 1;
                        x += 1;
                    }

                    longest = max(longest, count);
                }
            }

            return longest;
        }
};