#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(d)
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

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> left_rotate_optimal(vector<int>& arr, int n, int d) {
            d = d % n;

            reverse(arr.begin(), arr.begin() + d);
            reverse(arr.begin() + d, arr.end());
            reverse(arr.begin(), arr.end());
            
            return arr;
        }
};