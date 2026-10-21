#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int celebrity_problem(vector<vector<int>>& mat) {
            int n = mat.size();

            if (n == 0) return -1;

            int candidate = 0;

            for (int i = 1; i < n; i++) {
                if (mat[candidate][i] == 1) {
                    candidate = i;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i != candidate) {
                    if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                        return -1;
                    }
                }
            }

            return candidate;
        }
};