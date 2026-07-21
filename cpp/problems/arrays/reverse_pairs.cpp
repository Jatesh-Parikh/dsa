#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n logn)
        // Space Complexity - O(n)
        void merge(vector<int>& arr, int low, int mid, int high) {
            int left = low;
            int right = mid + 1;
            vector<int> temp;

            while (left <= mid && right <= high) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                } else {
                    temp.push_back(arr[right]);
                    right++;
                }
            }

            while (left <= mid) {
                temp.push_back(arr[left]);
                left++;
            }

            while (right <= high) {
                temp.push_back(arr[right]);
                right++;
            }

            for (int i = 0; i < temp.size(); i++) {
                arr[low + i] = temp[i];
            }
        }

        int count_pairs(vector<int>& arr, int low, int mid, int high) {
            int count = 0;
            int right = mid + 1;

            for (int i = low; i <= mid; i++) {
                while (right <= high && (long long)arr[i] > 2 * (long long)arr[right]) right++;
                count += right - (mid + 1);
            }

            return count;
        }

        int merge_sort(vector<int>& arr, int low, int high) {
            int count = 0;
            if(low >= high) return count;

            int mid = low + (high - low) / 2;

            count += merge_sort(arr, low, mid);
            count += merge_sort(arr, mid + 1, high);
            count += count_pairs(arr, low, mid, high);
            merge(arr, low, mid, high);

            return count;
        }

        int reverse_pairs(vector<int>& arr) {
            int n = arr.size();
            return merge_sort(arr, 0, n - 1);
        }
};