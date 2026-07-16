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
	vector<int> kLargesSmall(TreeNode* root,int k){
        vector<int>res;
        queue<TreeNode*>q;
        if(!root){
            return {0,0};
        }
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                res.push_back(q.front()->data);
                q.pop();
            }
        }
        sort(res.begin(),res.end());
        vector<int>ans;
        int n = res.size()-1;
        ans.push_back(res[k-1]);
        ans.push_back(res[n - (k-1)]);
        return ans;
	}
};