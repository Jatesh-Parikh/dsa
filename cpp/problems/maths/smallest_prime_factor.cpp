#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n log log n)
        // Space Complexity - O(1)
        vector<int> smallest_prime_factor(int n) {
            vector<int> spf(n + 1);

            for (int i = 0; i <= n; i++) spf[i] = i;

            for (int i = 2; i * i <= n; i++) {
                if (spf[i] == i) {
                    for (int j = i * i; j <= n; j += i) {
                        if (spf[j] == j) {
                            spf[j] = i;
                        }
                    }
                }
            }

            return spf;
        }
};