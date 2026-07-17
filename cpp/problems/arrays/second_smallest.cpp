// Time Complexity - O(n)
// Space Complexity - O(1)

#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        int second_smallest(vector<int>& arr, int n) {
            int smallest = arr[0];
            int second_smallest = INT_MAX;

            for (int i = 1; i < n; i++) {
                if (arr[i] < smallest) {
                    second_smallest = smallest;
                    smallest = arr[i];
                } else if (arr[i] > smallest && arr[i] < second_smallest) {
                    second_smallest = arr[i];
                }
            }

            return second_smallest;
        }
};