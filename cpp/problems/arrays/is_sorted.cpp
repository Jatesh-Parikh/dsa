// Time Complexity - O(n)
// Space Complexity - O(1)

#include <vector>

using namespace std;

class Solution {
    public:
        bool is_sorted(vector<int>& arr, int n) {

            for (int i = 1; i < n; i++) {
                if (arr[i] < arr[i - 1]) {
                    return false;
                }
            }

            return true;
        }
};