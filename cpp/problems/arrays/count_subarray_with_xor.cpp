#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int count_subarrays_with_xor(vector<int>& arr, int k) {
            int count = 0;
            unordered_map<int, int> mpp;
            int xr = 0;
            mpp[xr] = 1;

            for (int i = 0; i < arr.size(); i++) {
                xr = xr ^ arr[i];
                int x = xr ^ k;
                count += mpp[x];
                mpp[xr]++;  
            }

            return count;
        }
};