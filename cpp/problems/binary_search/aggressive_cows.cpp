#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
        bool can_we_place(vector<int>& stalls, int dist, int cows) {
            int count_cows = 1, last_placed = stalls[0];

            for (int i = 1; i < stalls.size(); i++) {
                if (stalls[i] - last_placed >= dist) {
                    count_cows++;
                    last_placed = stalls[i];
                }

                if(count_cows >= cows) return true;
            }

            return false;
        }
    
    public:
        // Time Complexity - O(n*logn + n * log(max distance))
        // Space Complexity - O(1)
        int aggressive_cows(vector<int>& stalls, int k) {
            sort(stalls.begin(), stalls.end());
            int low = 1, high = stalls[stalls.size() - 1] - stalls[0];

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (can_we_place(stalls, mid, k)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return high;
        }
};