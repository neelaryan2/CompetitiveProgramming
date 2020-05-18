/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    using pii = pair<int, int>;
    pii dfs(TreeNode* root) {
        if (root == NULL) return make_pair(0, 0);
        pii l = dfs(root->left);
        pii r = dfs(root->right);
        int d = max({l.first, r.first, l.second + r.second});
        return make_pair(d, 1 + max(r.second, l.second));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pii ans = dfs(root);
        return ans.first;
    }
};