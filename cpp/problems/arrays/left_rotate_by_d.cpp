// Time Complexity - O(n)
// Space Complexity - O(d)

#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> left_rotate(vector<int>& arr, int n, int d) {
            d = d % n;
            vector<int> temp;

            for (int i = 0; i < d; i++) {
                temp.push_back(arr[i]);                
            }

            for (int i = d; i < n; i++) {
                arr[i - d] = arr[i];
            }

            for (int i = n - d; i < n; i++) {
                arr[i] = temp[i - (n - d)];
            }

            return arr;
        }
};