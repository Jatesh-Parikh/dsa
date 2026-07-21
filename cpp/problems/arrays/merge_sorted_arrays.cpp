#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n + m)
        // Space Complexity - O(n + m)
        void merge(long long arr1[], long long arr2[], int n, int m) {
            long long arr3[n + m];
            int left = 0, right = 0, index = 0;

            while (left < n && right < m) {
                if (arr1[left] <= arr2[right]) {
                    arr3[index] = arr1[left];
                    left++;
                } else {
                    arr3[index] = arr2[right];
                    right++;                    
                }
                index++;
            }

            while (left < n) {
                arr3[index] = arr1[left];
                left++; 
                index++;
            }

            while (right < m) {
                arr3[index] = arr2[right];
                right++;
                index++;
            }

            for (int i = 0; i < n + m; i++) {
                if (i < n) {
                    arr1[i] = arr3[i];
                } else {
                    arr2[i - n] = arr3[i];
                }
            }
        }

        // Time Complexity - O(n logn + m logm)
        // Space Complexity - O(1)
        void merge_optimal_one(long long arr1[], long long arr2[], int n, int m) {
            int left = n - 1, right = 0;

            while (left >= 0 && right < m) {
                if (arr1[left] > arr2[right]) {
                    swap(arr1[left], arr2[right]);
                    left--;
                    right++;
                } else {
                    break;
                }
            }

            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        }

        void swap_if_greater(long long arr1[], long long arr2[], int index1, int index2) {
            if (arr1[index1] > arr2[index2]) {
                swap(arr1[index1], arr2[index2]);
            }
        }

        // Time Complexity - O(log(n + m) * (n + m))
        // Space Complexity - O(1)
        void merge_optimal_two(long long arr1[], long long arr2[], int n, int m) {
            int len = n + m;
            int gap = (len / 2) + (len % 2); // gap = (len + 1) / 2;

            while (gap > 0) {
                int left = 0;
                int right = left + gap;

                while (right < len) {
                    // left in arr1 and right in arr2
                    if (left < n && right >=n) {
                        swap_if_greater(arr1, arr2, left, right - n);
                    }
                    // both in arr2
                    else if (left >= n) {
                        swap_if_greater(arr2, arr2, left - n, right - n);
                    }
                    // both in arr1
                    else {
                        swap_if_greater(arr1, arr1, left, right);
                    }
                    left++;
                    right++;
                }

                if (gap == 1) break;
                gap = (gap / 2) + (gap % 2); // gap = (gap + 1) / 2;
            }
        }
};