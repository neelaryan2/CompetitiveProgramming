/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using ll = long long;
const ll inf = 1e18;
using pii = pair<ll, ll>;
#define fi first
#define se second
class Solution {
    pii aux(TreeNode* root) {
        if (root == nullptr) return {-inf, 0};
        pii left = aux(root->left);
        pii right = aux(root->right);
        ll curr = max({left.se + right.se + root->val, (ll)root->val, root->val + right.se, root->val + left.se});
        curr = max({curr, left.fi, right.fi});
        ll path = max({right.se, left.se, 0LL}) + root->val;
        return {curr, path};
    }

   public:
    int maxPathSum(TreeNode* root) {
        pii res = aux(root);
        return res.fi;
    }
};