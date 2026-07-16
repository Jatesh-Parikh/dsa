// Time Complexity - O(n)
// Space Complexity - O(1)

#include <vector>

using namespace std;

class Solution {
    public:
        int largest(vector<int>& arr, int n) {
            int largest = arr[0];

            for (int i = 1; i < n; i++) {
                if (arr[i] > largest) largest = arr[i];
            }

            return largest;
        } 
};