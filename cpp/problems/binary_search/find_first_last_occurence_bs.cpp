#include <vector>

using namespace std;

class Solution {
    private:
        int first_occurence(vector<int>& arr, int k) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int first = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] == k) {
                    first = mid;
                    high = mid - 1;
                } else if (arr[mid] < k) {
                    low = mid + 1;
                } else {
                    high = mid - 1; 
                }
            }

            return first;
        }

        int last_occurence(vector<int>& arr, int k) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int last = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] == k) {
                    last = mid;
                    low = mid + 1;
                } else if (arr[mid] < k) {
                    low = mid + 1;
                } else {
                    high = mid - 1; 
                }
            }

            return last;
        }

    public:
        // Time Complexity - O(logn)
        // Space Complexity - O(1)
        pair<int, int> find_first_last_occurence(vector<int>& arr, int target) {
            int first = first_occurence(arr, target);

            if (first == -1) return {-1, -1};

            int last = last_occurence(arr, target);

            return {first, last};
        } 
};