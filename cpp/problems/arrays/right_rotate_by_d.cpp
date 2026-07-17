#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(d)
        vector<int> right_rotate(vector<int>& arr, int n, int d) {
            d = d % n;
            vector<int> temp;

            for (int i = n - d; i < n; i++) {
                temp.push_back(arr[i]);    
            }
            
            for (int i = n - d - 1; i >= 0; i--) {
                arr[i + d] = arr[i];
            }

            for (int i = 0; i < d; i++) {
                arr[i] = temp[i];
            }

            return arr;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> right_rotate_optimal(vector<int>& arr, int n, int d) {
            d = d % n;

            reverse(arr.begin() + (n - d), arr.end());
            reverse(arr.begin(), arr.begin() + (n - d));
            reverse(arr.begin(), arr.end());

            return arr;
        }
};