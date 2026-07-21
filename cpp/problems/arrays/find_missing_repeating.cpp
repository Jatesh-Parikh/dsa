#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> find_missing_repeating_numbers_better(vector<int>& arr) {
            int n = arr.size();
            vector<int> hash(n + 1, 0);
            int repeating = -1, missing = -1;

            for (int i = 0; i < n; i++) {
                hash[arr[i]]++;
            }

            for (int i = 1; i <= n; i++) {
                if (hash[i] == 2) repeating = i;
                else if (hash[i] == 0) missing = i;
                
                if (repeating != -1 && missing != -1) break;
            }

            return {repeating, missing};
        }
        
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> find_missing_repeating_numbers_optimal_one(vector<int>& arr) {
            int n = arr.size();

            long long SN = n * (n + 1) / 2;
            long long S2N = n * (n + 1) * (2* n + 1) / 6;

            long long S = 0, S2 = 0;
            
            for (int i = 0; i < n; i++) {
                S += (long long)arr[i];
                S2 += (long long)arr[i] * (long long)arr[i];
            }

            long long val1 = S - SN; // x - y
            long long val2 = S2 - S2N;
            
            val2 = val2 / val1; // x + y
            long long x = (val1 + val2) / 2;
            long long y = x - val1;

            return { (int)x, (int)y };
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> find_missing_repeating_numbers_optimal_xor(vector<int>& arr) {
            int n = arr.size();
            int xr = 0;

            for (int i = 0; i < n; i++) {
                xr = xr ^ arr[i];
                xr = xr ^ (i + 1);
            }

            int bit_no = 0;

            while (1) {
                if ((xr & (1 << bit_no)) != 0) {
                    break;
                }
                bit_no++;
            }

            int zero = 0, one = 0;

            for (int i = 0; i < n; i++) {
                if ((arr[i] & (1 << bit_no)) != 0) {
                    one = one ^ arr[i];
                } else {
                    zero = zero ^ arr[i];
                }
            }

            for (int i = 1; i <= n; i++) {
                if ((i & (1 << bit_no)) != 0) {
                    one = one ^ i;
                } else {
                    zero = zero ^ i;
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] == zero) count++;
            }

            if (count == 2) return { zero, one };
            return { one, zero };
        }
};