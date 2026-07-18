#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int appears_once(vector<int>& arr, int n) {
            int xor1 = 0;

            for (int i = 0; i < n; i++) {
                xor1 ^= arr[i];
            }

            return xor1;
        }
};