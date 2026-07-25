class Solution {
    public:
        // Time Complexity - O(logn)
        // Space Complexity - O(1)
        int floor_sqrt(int n) {
            int low = 1, high = n;

            while (low <= high) {
                long long mid = low + (high - low) / 2;

                if (mid * mid <= n) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return high;
        }
};