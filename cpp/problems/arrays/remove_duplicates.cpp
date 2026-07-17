// Time Complexity - O(n)
// Space Complexity - O(1)

#include <vector>

using namespace std;

class Solution {
    public:
        int remove_duplicates(vector<int>& arr, int n) {
            int i = 0;

            for (int j = 1; j < n; j++) {
                if (arr[j] != arr[i]) {
                    arr[i + 1] = arr[j];
                    i++;
                }
            }

            return i + 1;
        }
};