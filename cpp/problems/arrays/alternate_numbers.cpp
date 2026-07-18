// Similar to rearrange elements, but the number of positives may not be equal to the number of negatives 
#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> alternate_nums(vector<int>& a) {
            vector<int> pos, neg;

            for (int i = 0; i < a.size(); i++) {
                if (a[i] < 0) {
                    neg.push_back(a[i]);
                } else {
                    pos.push_back(a[i]);
                }
            }

            if (pos.size() > neg.size()) {
                for (int i = 0; i < neg.size(); i++) {
                    a[2 * i] = pos[i];
                    a[2 * i + 1] = neg[i];
                }

                int index = neg.size() * 2;
                for (int i = neg.size(); i < pos.size(); i++) {
                    a[index] = pos[i];
                    index++;
                }
            } else {
                for (int i = 0; i < pos.size(); i++) {
                    a[2 * i] = pos[i];
                    a[2 * i + 1] = neg[i];
                }

                int index = pos.size() * 2;
                for (int i = pos.size(); i < neg.size(); i++) {
                    a[index] = neg[i];
                    index++;
                }
            }

            return a;
        }
};