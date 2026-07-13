// Time Complexity - O(n)
// Space Complexity - O(n)

#include <vector>
#include <queue>
#include <unordered_map>

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
        void mark_parents(TreeNode *root, unordered_map<TreeNode *, TreeNode *>& parent) {
            queue<TreeNode *> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode *current = q.front();
                q.pop();

                if(current->left) {
                    parent[current->left] = current;
                    q.push(current->left);
                }

                if(current->right) {
                    parent[current->right] = current;
                    q.push(current->right);
                }
            }
        }
    public:
        vector<int> distance_k(TreeNode *root, TreeNode *target, int k) {
            if (root == nullptr) return {};
            unordered_map<TreeNode *, TreeNode *> parent;
            mark_parents(root, parent);

            unordered_map<TreeNode *, bool> visited;
            queue<TreeNode *> q;
            q.push(target);
            visited[target] = true;
            int current_level = 0;

            while (!q.empty()) {
                int size = q.size();
                if(current_level++ == k) break;

                for(int i = 0; i < size; i++) {
                    TreeNode * current = q.front();
                    q.pop();

                    if(current->left && !visited[current->left]) {
                        q.push(current->left);
                        visited[current->left] = true;
                    }

                    if(current->right && !visited[current->right]) {
                        q.push(current->right);
                        visited[current->right] = true;
                    }

                    if(parent.count(current) && !visited[parent[current]]) {
                        q.push(parent[current]);
                        visited[parent[current]] = true;
                    }
                }
            }

            vector<int> result;
            while (!q.empty()) {
                TreeNode * current = q.front();
                q.pop();
                result.push_back(current->val);
            }

            return result;
        }
};