class Solution {
    private:
        int func (int mid, int n, int m) {
            long long ans =  1;

            for (int i = 1; i <= n; i++) {
                ans = ans * mid;
                if (ans > m) return 2;
            }

            if (ans == m) return 1;
            return 0;
        }

    public:
        // Time Complexity - O(n * log m)
        // Space Complexity - O(1)
        int nth_root(int n, int m) {
            int low = 1, high = m;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int mid_n = func(mid, n , m);

                if (mid_n == 1) return mid;
                else if (mid_n == 0) low = mid + 1;
                else high = mid - 1;
            }

            return -1;
        }
};