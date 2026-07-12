// Time Complexity - O(n * logn)
// Space Complexity - O(n)

#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<int> bottom_view(TreeNode *root) {
            vector<int> ans;
            if(root == nullptr) return ans;

            queue<pair<TreeNode *, int>> q;
            q.push({ root, 0 });

            map<int, int> mpp;

            while (!q.empty()) {
                auto it = q.front();
                q.pop();

                TreeNode *node = it.first;
                int line = it.second;
                
                mpp[line] = node->val;

                if (node->left) {
                    q.push({ node->left, line - 1 });
                }

                if (node->right) {
                    q.push({ node->right, line + 1 });
                }
            }

            for (auto it: mpp) {
                ans.push_back(it.second);
            }

            return ans;
        }
};