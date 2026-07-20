#include <vector>

using namespace std;

class Solution {
    public:
        // Calculate the value at the given row and col index, ncr(r - 1, c - 1)
        // Time Complexity - O(r)
        // Space Complexity - O(1)
        long long ncr(int n, int r) {
            long long res = 1;

            for (int i = 0; i < r; i++) {
                res = res * (n - i);
                res = res / (i + 1);
            }

            return res;
        }

        // Nth row
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> nth_row(int row) {
            vector<int> res;
            long long ans = 1;
            res.push_back(ans);

            for (int col = 1; col < row; col++) {
                ans = ans * (row - col);
                ans = ans / col;
                res.push_back(ans);
            }

            return res;
        }

        // Print the Pascal's Triangle
        // Time Complexity - O(n ^ 2)
        // Space Complexity - O(1)
        vector<vector<int>> pascal_triangle(int N) {
            vector<vector<int>> res;

            for (int i = 1; i <= N; i++) {
                res.push_back(nth_row(i));
            }

            return res;
        }
};