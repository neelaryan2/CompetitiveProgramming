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
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (!l || !r) return !l && !r;
        if (l->val != r->val) return false;
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};