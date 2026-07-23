#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        // Time Complexity - O(n)
        // Space Complexity - O(n) 
        long long func(vector<int>& arr, int k) {
            if (k == 0) return 0;
            int left = 0, right = 0; 
            long long count = 0;
            
            unordered_map<int, int> freq;
            
            int n = arr.size();

            while (right < n) {
                freq[arr[right]]++;

                while (freq.size() > k) {
                    freq[arr[left]]--;
                    if (freq[arr[left]] == 0) freq.erase(arr[left]);
                    left++;
                }

                count += right - left + 1;
                right++;
            }

            return count;
        }

    public:
        int count_subarrays_with_distinct_integers(vector<int>& arr, int k) {
            return func(arr, k) - func(arr, k - 1);
        }
};