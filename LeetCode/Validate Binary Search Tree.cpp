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
    using ll = long long;
    bool valid(TreeNode* root, ll mn, ll mx) {
        if (root == NULL) return true;
        if ((ll)root->val >= mx) return false;
        if ((ll)root->val <= mn) return false;
        return valid(root->left, mn, root->val) && valid(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, (ll)INT_MIN - 1, (ll)INT_MAX + 1);
    }
};