// Time Complexity - O(n)
// Space Complexity - O(1)

#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        int second_largest(vector<int>& arr, int n) {
            int largest = arr[0], second_largest = INT_MIN;

            for (int i = 1; i < n; i++) {
                if (arr[i] > largest) {
                    second_largest = largest;
                    largest = arr[i];
                } else if (arr[i] < largest && arr[i] > second_largest) {
                    second_largest = arr[i];
                }
            }

            return second_largest;
        }
};