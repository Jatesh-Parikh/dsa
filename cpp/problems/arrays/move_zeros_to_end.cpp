#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(x), where x is the size of non-zero elements
        vector<int> move_zeros(vector<int>& arr, int n) {
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                if (arr[i] != 0) {
                    temp.push_back(arr[i]);
                }
            }

            for (int i = 0; i < temp.size(); i++) {
                arr[i] = temp[i];
            }

            for (int i = temp.size(); i < n; i++) {
                arr[i] = 0;
            }

            return arr;
        }
        
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> move_zeros_optimal(vector<int>& arr, int n) {
            int j = -1;

            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    j = i;
                    break;
                }
            }

            if (j == -1) return arr;

            for (int i = j + 1; i < n; i++) {
                if (arr[i] != 0) {
                    swap(arr[i], arr[j]);
                    j++;
                }
            }

            return arr;
        }
};