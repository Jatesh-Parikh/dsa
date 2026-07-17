// Time Complexity - O(n)
// Space Complexity - O(1)

#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> rotate_one(vector<int>& arr, int n) {
            int temp = arr[0];

            for (int i = 1; i < n; i++) {
                arr[i - 1] = arr[i];
            }

            arr[n - 1] = temp;

            return arr;
        }
};