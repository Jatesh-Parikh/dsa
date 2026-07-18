#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(N ^ 2)
        // Space Complexity - O(1)
        int missing_number_brute(vector<int>& arr, int N) {
            for (int i = 1; i <= N; i++) {
                bool found = false;
                
                for (int j = 0; j < arr.size(); j++) {
                    if (arr[j] == i) {
                        found = true;
                        break;
                    }
                }

                if (!found) return i; 
            }

            return -1;
        }

        // Time Complexity - O(N)
        // Space Complexity - O(N) 
        int missing_number_better(vector<int>& arr, int N) {
            int size = N + 1;
            vector<int> hash(size, 0);

            for (int i = 0; i < N - 1; i++) {
                hash[arr[i]] = 1;
            }

            for (int i = 1; i < size; i++) {
                if (hash[i] == 0) {
                    return i;
                }
            }

            return -1;
        }

        // Time Complexity - O(N)
        // Space Complexity - O(1) 
        int missing_number_optimal_sum(vector<int>& arr, int N) {
            int sum = N * (N + 1) / 2;

            int sum_arr = 0;

            for (int i = 0; i < N - 1; i++) {
                sum_arr += arr[i]; 
            }

            return sum - sum_arr;
        }

        // Time Complexity - O(N)
        // Space Complexity - O(1)
        int missing_number_optimal_xor(vector<int>& arr, int N) {
            int xor_1 = 0, xor_2 = 0;
            
            int n = N - 1;
            for (int i = 0; i < n; i++) {
                xor_1 = xor_1 ^ arr[i];
                xor_2 = xor_2 ^ (i + 1);
            }

            xor_2 = xor_2 ^ N;
            return xor_2 ^ xor_1;
        }
};