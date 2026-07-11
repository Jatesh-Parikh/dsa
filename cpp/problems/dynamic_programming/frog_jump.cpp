#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    private:
        // Time Complexity - O(2 ^ n)
        // Space Complexity - O(n)
        int frog_jump_recursive(int index, vector<int>& heights) {
            if (index == 0) return 0;

            int one_step = frog_jump_recursive(index - 1, heights) + abs(heights[index] - heights[index - 1]);

            int two_step = INT_MAX;
            if(index > 1) {
                two_step = frog_jump_recursive(index - 2, heights) + abs(heights[index] - heights[index - 2]);
            }

            return min(one_step, two_step);
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n), For both the dp vector and the recursion stack space
        int frog_jump_memoized(int index, vector<int>& heights, vector<int>& dp) {
            if (index == 0) return 0;

            if (dp[index] != -1) return dp[index];

            int one_step = frog_jump_memoized(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);

            int two_step = INT_MAX;
            if (index > 1) {
                two_step = frog_jump_memoized(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
            }

            dp[index] = min(one_step, two_step);
            return dp[index];
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int frog_jump_iterative(vector<int>& heights) {
            int n = heights.size();
            vector<int> dp(n, -1);
            dp[0] = 0;

            for (int i = 1; i < n; i++) {
                int one_step = dp[i - 1] + abs(heights[i] - heights[i - 1]);

                int two_step = INT_MAX;
                if(i > 1) two_step = dp[i - 2] + abs(heights[i] - heights[i - 2]);

                dp[i] = min(one_step, two_step);
            }

            return dp[n - 1];
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int frog_jump_optimized(vector<int>& heights) {
            int n = heights.size();
            int prev = 0, prev_2 = 0;

            for (int i = 1; i < n; i++) {
                int one_step = prev + abs(heights[i] - heights[i - 1]);

                int two_step = INT_MAX;
                if (i > 1) two_step = prev_2 + abs(heights[i] - heights[i - 2]);

                int curr = min(one_step, two_step);
                prev_2 = prev;
                prev = curr;
            }

            return prev;
        }
    
    public:
        void frog_jump(int n, vector<int>& heights) {
            cout << frog_jump_recursive(n - 1, heights) << endl;

            vector<int> dp(n, -1);
            cout << frog_jump_memoized(n - 1, heights, dp) << endl;
            
            cout << frog_jump_iterative(heights) << endl;

            cout << frog_jump_optimized(heights) << endl;
        }
};


