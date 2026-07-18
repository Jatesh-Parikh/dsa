#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        bool two_sum(vector<int>& book, int target) {
            unordered_map<int, int> mpp;
            
            for (int i = 0; i < book.size(); i++) {
                int a = book[i];
                int more = target - a;

                if (mpp.find(more) != mpp.end()) {
                    return true; // return { mpp.find(more), i };
                }

                mpp[a] = i;
            }

            return false; // return { -1, -1 };
        }

        // Time Complexity - O(n * logn)
        // Space Complexity - O(logn), recursion stack space when sorting the array
        bool two_sum_other(vector<int>& book, int target) {
            sort(book.begin(), book.end());

            int left = 0, right = book.size() - 1;
            
            while (left < right) {
                int sum = book[left] + book[right];

                if (sum == target) return true; // return { left, right };

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }

            return false; // return { -1, -1 }; 
        }
};