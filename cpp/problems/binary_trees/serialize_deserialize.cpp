#include <string>
#include <sstream>
#include <queue>

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
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        string serialize(TreeNode *root) {
            if (root == nullptr) return "";
            
            string s = "";
            queue<TreeNode *> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode *curr = q.front();
                q.pop();

                if (curr == nullptr) s.append("#,");
                else s.append(to_string(curr->val) + ",");
                if (curr != nullptr) {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            return s;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        TreeNode *de_serialize(string data) {
            if (data.size() == 0) return nullptr;
            stringstream s(data);
            string str;
            getline(s, str, ',');
            TreeNode *root = new TreeNode(stoi(str));
            queue<TreeNode *> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();

                getline(s, str, ',');
                if (str == "#") {
                    node->left = nullptr;
                } else {
                    TreeNode *left_node = new TreeNode(stoi(str));
                    node->left = left_node;
                    q.push(left_node);
                }

                getline(s, str, ',');
                if (str == "#") {
                    node->right = nullptr;
                } else {
                    TreeNode *right_node = new TreeNode(stoi(str));
                    node->right = right_node;
                    q.push(right_node);
                }
            }

            return root;
        }   
};