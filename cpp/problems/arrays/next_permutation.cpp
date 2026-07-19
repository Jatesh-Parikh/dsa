#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> next_permutation_better(vector<int>& arr) {
            next_permutation(arr.begin(), arr.end());
            return arr;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> next_permutation_optimal(vector<int>& arr) {
            int index = -1;
            int n = arr.size();

            for (int i = n - 2; i >= 0; i--) {
                if (arr[i] < arr[i + 1]) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                reverse(arr.begin(), arr.end());
                return arr;
            }

            for (int i = n - 1; i > index; i--) {
                if (arr[i] > arr[index]) {
                    swap(arr[i], arr[index]);
                    break;
                }
            }

            reverse(arr.begin() + index + 1, arr.end());

            return arr;
        }
};