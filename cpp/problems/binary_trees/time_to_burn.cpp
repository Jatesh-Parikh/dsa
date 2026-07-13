// Time Complexity - O(n)
// Space Complexity - O(n)

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
    private:
        TreeNode * mark_parents(TreeNode *root, map<TreeNode *, TreeNode *>& parent, int start) {
            queue<TreeNode *> q;
            q.push(root);
            TreeNode *res = nullptr;
            
            while (!q.empty()) {
                auto node = q.front();
                q.pop();

                if(node->val == start) res = node;

                if(node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }

                if(node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }

            return res;
        }

        int find_time(map<TreeNode *, TreeNode *>& parent, TreeNode *target) {
            queue<TreeNode *> q;
            map<TreeNode *, int> vis;
            
            q.push(target);
            vis[target] = 1;
            
            int time = 0;

            while(!q.empty()) {
                int size = q.size();
                int flag = 0;

                for (int i = 0; i < size; i++) {
                    auto node = q.front();
                    q.pop();

                    if(node->left && !vis[node->left]) {
                        flag = 1;
                        q.push(node->left);
                        vis[node->left] = 1;
                    }
                    if(node->right && !vis[node->right]) {
                        flag = 1;
                        q.push(node->right);
                        vis[node->right] = 1;
                    }
                    if(parent.count(node) && !vis[parent[node]]) {
                        flag = 1;
                        q.push(parent[node]);
                        vis[parent[node]] = 1;
                    }
                }
                if(flag) time++;
            }

            return time;
        }

    public:
        int time_to_burn(TreeNode *root, int start) {
            if (root == nullptr) return 0;
            
            map<TreeNode *, TreeNode *> parent;

            TreeNode *target = mark_parents(root, parent, start);
            int time = find_time(parent, target);
            
            return time;
        }
};