#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int count_subarrays_with_sum(vector<int>& arr, int k) {
            unordered_map<int, int> mpp;          
            mpp[0] = 1;
            
            int prefix_sum = 0, count = 0;

            for (int i = 0; i < arr.size(); i++) {
                prefix_sum += arr[i];
                int remove = prefix_sum - k;
                count += mpp[remove];
                mpp[prefix_sum] += 1;
            }

            return count;
        }
};