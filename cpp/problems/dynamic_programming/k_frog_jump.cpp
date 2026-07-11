#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    private:
        // Time Complexity - O(K ^ N)
        // Space Complexity - O(N)
        int k_frog_jump_recursive(int index, vector<int>& heights, int k) {
            if (index == 0) return 0;

            int min_steps = INT_MAX;

            for (int i = 1; i <= k; i++) {
                if (index - i >= 0) {
                    int jump = k_frog_jump_recursive(index - i, heights, k) + abs(heights[index] - heights[index - i]);
                    min_steps = min(min_steps, jump);
                }
            }

            return min_steps;
        }
        
        // Time Complexity - O(K * N)
        // Space Complexity - O(N)
        int k_frog_jump_memoized(int index, vector<int>& heights, int k, vector<int>& arr) {
            if (index == 0) return 0;

            if (arr[index] != - 1) return arr[index];

            int min_steps = INT_MAX;

            for(int i = 1; i <= k; i++) {
                if (index - i >= 0) {
                    int jump = k_frog_jump_memoized(index - i, heights, k, arr) + abs(heights[index] - heights[index - i]);
                    min_steps = min(min_steps, jump);
                }
            }

            arr[index] = min_steps;
            return arr[index];
        }
        
        // Time Complexity - O(K * N)
        // Space Complexity - O(N)
        int k_frog_jump_iterative(vector<int>& heights, int k) {
            int n = heights.size();
            vector<int> dp(n, -1);
            dp[0] = 0;

            for (int i = 1; i < n; i++) {
                int min_steps = INT_MAX;
                for (int j = 1; j <= k; j++) {
                    if (i - j >= 0) {
                        int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                        min_steps = min(min_steps, jump);
                    }
                }
                dp[i] = min_steps;
            }

            return dp[n - 1];
        }
        
        // Time Complexity - O(K * N)
        // Space Complexity - O(K)
        int k_frog_jump_optimized(vector<int>& heights, int k) {
            int n = heights.size();
            vector<int> dp(k, -1);
            dp[0] = 0;

            for (int i = 1; i < n; i++) {
                int min_steps = INT_MAX;
                for (int j = 1; j <= k; j++) {
                    if (i - j >= 0) {
                        int prev = dp[(i - j) % k];
                        int jump = prev + abs(heights[i] - heights[i - j]);
                        min_steps = min(min_steps, jump);
                    }
                }
                dp[i % k] = min_steps;
            }

            return dp[(n - 1) % k];
        }

    public:
        void k_frog_jump(int n, vector<int>& heights, int k) {
            cout << k_frog_jump_recursive(n - 1, heights, k) << endl;

            vector<int> arr(n, -1);
            cout << k_frog_jump_memoized(n - 1, heights, k, arr) << endl;

            cout << k_frog_jump_iterative(heights, k) << endl;
            
            cout << k_frog_jump_optimized(heights, k) << endl;
        }
};