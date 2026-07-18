#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int majority_element(vector<int>& arr) {
            unordered_map<int, int> mpp;

            int size = arr.size();

            for (int i = 0; i < size; i++) {
                mpp[arr[i]] += 1; 
            }

            for (auto it: mpp) {
                if (it.second > size / 2) {
                    return it.first;
                }
            }

            return -1;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int majority_element_optimal(vector<int>& arr) {
            int count = 0, el;
            int size = arr.size();

            for (int i = 0; i < size; i++) {
                if (count == 0) {
                    count = 1;
                    el = arr[i];
                } else if (arr[i] == el) {
                    count++;
                } else {
                    count--;
                }
            }

            int count_check = 0;
            for (int i = 0; i < size; i++) {
                if (arr[i] == el) count_check++;
            }

            if (count_check > size / 2) return el;
            else return -1;
        }
};